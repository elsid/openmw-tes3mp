#ifndef OPENMW_PROCESSORVIDEOPLAY_HPP
#define OPENMW_PROCESSORVIDEOPLAY_HPP

#include "../ObjectProcessor.hpp"

namespace mwmp
{
    class ProcessorVideoPlay : public ObjectProcessor
    {
    public:
        ProcessorVideoPlay()
        {
            BPP_INIT(ID_VIDEO_PLAY)
        }
    };
}

#endif //OPENMW_PROCESSORVIDEOPLAY_HPP
