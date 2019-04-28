#!/usr/bin/env bash
echo Updating...
sudo apt-get update
echo Getting essentials...
sudo apt-get install build-essential
echo Installing Required Packages..
sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
echo Creating Working Directory
rm -rf ~/texture_atlas
mkdir ~/texture_atlas
cd ~/texture_atlas
echo Cloning opencv git repositories...
git clone https://github.com/opencv/opencv.git
git clone https://github.com/opencv/opencv_contrib.git
cd ~/texture_atlas/opencv
echo Creating build directory inside cloned opencv directory
mkdir build
cd build
cmake -D CMAKE_BUILD_TYPE=Release \
        -D CMAKE_INSTALL_PREFIX=/usr/local \
        -D OPENCV_EXTRA_MODULES_PATH=~/texture_atlas/opencv_contrib/modules \
        -D BUILD_EXAMPLES=ON \
        -D BUILD_DOCS=ON ..
make -j7
sudo make install

#ozcanay@ubuntu:~/CLionProjects/texture_atlas/cmake-build-debug$
#cmake ..
#cmake --build .
#texture_atlas <DIR>
