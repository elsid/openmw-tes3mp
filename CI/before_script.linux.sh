#!/bin/bash -ex

free -m

env GENERATOR='Unix Makefiles' CONFIGURATION=Release CI/build_googletest.sh
GOOGLETEST_DIR="$(pwd)/googletest/build"

mkdir build
cd build

# Set up compilers
if [ ! -z "${MATRIX_CC}" ]; then
    eval "${MATRIX_CC}"
fi

export RAKNET_ROOT=~/CrabNet

export CODE_COVERAGE=1

if [[ "${CC}" =~ "clang" ]]; then export CODE_COVERAGE=0; fi
if [[ -z "${BUILD_OPENMW}" ]]; then export BUILD_OPENMW=ON; fi
if [[ -z "${BUILD_OPENMW_CS}" ]]; then export BUILD_OPENMW_CS=ON; fi

${ANALYZE} cmake .. \
    -DCMAKE_C_COMPILER="${CC}" \
    -DCMAKE_CXX_COMPILER="${CXX}" \
    -DBUILD_OPENMW=${BUILD_OPENMW} \
    -DBUILD_OPENCS=${BUILD_OPENMW_CS} \
    -DBUILD_LAUNCHER=${BUILD_OPENMW_CS} \
    -DBUILD_BSATOOL=${BUILD_OPENMW_CS} \
    -DBUILD_ESMTOOL=${BUILD_OPENMW_CS} \
    -DBUILD_MWINIIMPORTER=${BUILD_OPENMW_CS} \
    -DBUILD_ESSIMPORTER=${BUILD_OPENMW_CS} \
    -DBUILD_WIZARD=${BUILD_OPENMW_CS} \
    -DBUILD_NIFTEST=${BUILD_OPENMW_CS} \
    -DBUILD_MYGUI_PLUGIN=${BUILD_OPENMW_CS} \
    -DBUILD_OPENMW_MP=ON \
    -DBUILD_BROWSER=ON \
    -DBUILD_MASTER=ON \
    -DBUILD_WITH_CODE_COVERAGE=${CODE_COVERAGE} \
    -DBUILD_UNITTESTS=1 \
    -DUSE_SYSTEM_TINYXML=1 \
    -DDESIRED_QT_VERSION=5 \
    -DCMAKE_INSTALL_PREFIX=/usr \
    -DBINDIR=/usr/games \
    -DCMAKE_BUILD_TYPE="None" \
    -DUSE_SYSTEM_TINYXML=TRUE \
    -DGTEST_ROOT="${GOOGLETEST_DIR}" \
    -DGMOCK_ROOT="${GOOGLETEST_DIR}" \
    -DRakNet_LIBRARY_RELEASE=~/CrabNet/lib/libRakNetLibStatic.a \
    -DRakNet_LIBRARY_DEBUG=~/CrabNet/lib/libRakNetLibStatic.a
