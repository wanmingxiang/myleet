#!/bin/bash - 
#===============================================================================
#
#          FILE: build.sh
# 
#         USAGE: ./build.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: wanmingxiang (wanmx@foxmail.com), 
#  ORGANIZATION: 
#       CREATED: 2017/05/10 01:15
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error

#run test
if [ -d ./googletest/build ]; then
	rm -rf ./googletest/build
fi
mkdir -p ./googletest/build && cd ./googletest/build
cmake ..
make -s
cd ../../

# build steps
if [ -d ./build ]; then
	rm -rf ./build
fi
mkdir build && cd ./build
cmake  -DCMAKE_INSTALL_PREFIX=./ ..
make -s
cd ../


