
#include "player.hpp"

#include <stdexcept>

#include <components/esm/esmreader.hpp>
#include <components/esm/esmwriter.hpp>
#include <components/esm/player.hpp>
#include <components/esm/defs.hpp>

#include "../mwbase/environment.hpp"
#include "../mwbase/world.hpp"
#include "../mwbase/windowmanager.hpp"
#include "../mwbase/soundmanager.hpp"

#include "../mwworld/ptr.hpp"
#include "../mwworld/inventorystore.hpp"

#include "../mwmechanics/movement.hpp"
#include "../mwmechanics/npcstats.hpp"

#include "class.hpp"

namespace MWWorld
{
    Player::Player (const ESM::NPC *player, const MWBase::World& world)
      : mCellStore(0),
        mLastKnownExteriorPosition(0,0,0),
        mAutoMove(false),
        mForwardBackward (0),
        mTeleported(false),
        mMarkedCell(NULL)
    {
        mPlayer.mBase = player;
        mPlayer.mRef.mRefID = "player";

        float* playerPos = mPlayer.mData.getPosition().pos;
        playerPos[0] = playerPos[1] = playerPos[2] = 0;
    }

    void Player::set(const ESM::NPC *player)
    {
        mPlayer.mBase = player;
    }

    void Player::setCell (MWWorld::CellStore *cellStore)
    {
        mCellStore = cellStore;
    }

    MWWorld::Ptr Player::getPlayer()
    {
        MWWorld::Ptr ptr (&mPlayer, mCellStore);
        return ptr;
    }

    void Player::setBirthSign (const std::string &sign)
    {
        mSign = sign;
    }

    const std::string& Player::getBirthSign() const
    {
        return mSign;
    }

    void Player::setDrawState (MWMechanics::DrawState_ state)
    {
         MWWorld::Ptr ptr = getPlayer();
         MWWorld::Class::get(ptr).getNpcStats(ptr).setDrawState (state);
    }

    bool Player::getAutoMove() const
    {
        return mAutoMove;
    }

    void Player::setAutoMove (bool enable)
    {
        MWWorld::Ptr ptr = getPlayer();

        mAutoMove = enable;

        int value = mForwardBackward;

        if (mAutoMove)
            value = 1;

        MWWorld::Class::get (ptr).getMovementSettings (ptr).mPosition[1] = value;
    }

    void Player::setLeftRight (int value)
    {
        MWWorld::Ptr ptr = getPlayer();

        MWWorld::Class::get (ptr).getMovementSettings (ptr).mPosition[0] = value;
    }

    void Player::setForwardBackward (int value)
    {
        MWWorld::Ptr ptr = getPlayer();

        mForwardBackward = value;

        if (mAutoMove)
            value = 1;

        MWWorld::Class::get (ptr).getMovementSettings (ptr).mPosition[1] = value;
    }

    void Player::setUpDown(int value)
    {
        MWWorld::Ptr ptr = getPlayer();

        MWWorld::Class::get (ptr).getMovementSettings (ptr).mPosition[2] = value;
    }

    void Player::setRunState(bool run)
    {
        MWWorld::Ptr ptr = getPlayer();
        MWWorld::Class::get(ptr).setStance(ptr, MWWorld::Class::Run, run);
    }

    void Player::setSneak(bool sneak)
    {
        MWWorld::Ptr ptr = getPlayer();

        MWWorld::Class::get (ptr).setStance (ptr, MWWorld::Class::Sneak, sneak);

        // TODO show sneak indicator only when the player is not detected by any actor
        MWBase::Environment::get().getWindowManager()->setSneakVisibility(sneak);
    }

    void Player::yaw(float yaw)
    {
        MWWorld::Ptr ptr = getPlayer();
        MWWorld::Class::get(ptr).getMovementSettings(ptr).mRotation[2] += yaw;
    }
    void Player::pitch(float pitch)
    {
        MWWorld::Ptr ptr = getPlayer();
        MWWorld::Class::get(ptr).getMovementSettings(ptr).mRotation[0] += pitch;
    }
    void Player::roll(float roll)
    {
        MWWorld::Ptr ptr = getPlayer();
        MWWorld::Class::get(ptr).getMovementSettings(ptr).mRotation[1] += roll;
    }

    MWMechanics::DrawState_ Player::getDrawState()
    {
         MWWorld::Ptr ptr = getPlayer();
         return MWWorld::Class::get(ptr).getNpcStats(ptr).getDrawState();
    }

    bool Player::wasTeleported() const
    {
        return mTeleported;
    }

    void Player::setTeleported(bool teleported)
    {
        mTeleported = teleported;
    }

    void Player::markPosition(CellStore *markedCell, ESM::Position markedPosition)
    {
        mMarkedCell = markedCell;
        mMarkedPosition = markedPosition;
    }

    void Player::getMarkedPosition(CellStore*& markedCell, ESM::Position &markedPosition) const
    {
        markedCell = mMarkedCell;
        if (mMarkedCell)
            markedPosition = mMarkedPosition;
    }

    void Player::clear()
    {
        mCellStore = 0;
        mSign.clear();
        mMarkedCell = 0;
        mAutoMove = false;
        mForwardBackward = 0;
        mTeleported = false;
    }

    void Player::write (ESM::ESMWriter& writer) const
    {
        ESM::Player player;

        mPlayer.save (player.mObject);
        player.mCellId = mCellStore->mCell->getCellId();

        /// \todo sign
        /// \todo last know exterior position
        /// \todo mark

        player.mAutoMove = mAutoMove ? 1 : 0;

        writer.startRecord (ESM::REC_PLAY);
        player.save (writer);
        writer.endRecord (ESM::REC_PLAY);
    }

    bool Player::readRecord (ESM::ESMReader& reader, int32_t type)
    {
        if (type==ESM::REC_PLAY)
        {
            ESM::Player player;
            player.load (reader);

            if (!mPlayer.checkState (player.mObject))
            {
                // this is the one object we can not silently drop.
                throw std::runtime_error ("invalid player state record");
            }

            mPlayer.load (player.mObject);

            mCellStore = MWBase::Environment::get().getWorld()->getCell (player.mCellId);

            /// \todo sign
            /// \todo last know exterior position
            /// \todo mark

            mAutoMove = player.mAutoMove!=0;

            mForwardBackward = 0;
            mTeleported = false;

            return true;
        }

        return false;
    }
}
