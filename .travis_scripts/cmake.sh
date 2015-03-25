#!/bin/bash

wget http://www.cmake.org/files/v3.2/cmake-3.2.0.tar.gz

tar xzf cmake-3.2.0.tar.gz
cd cmake-3.2.0
cmake .
./configure
make

# Uninstall old version of cmake
if [ "$TRAVIS_OS_NAME" == 'linux']
then
  sudo apt-get remove cmake cmake-data
fi

if [ "$TRAVIS_OS_NAME" == 'osx']
then
 brew uninstall cmake
fi

sudo make install


