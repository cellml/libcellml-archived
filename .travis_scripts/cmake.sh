#!/bin/bash

wget http://www.cmake.org/files/v3.1/cmake-3.1.0.tar.gz

tar xzf cmake-3.1.0.tar.gz
cd cmake-3.1.0
cmake .
./configure --prefix=/opt/cmake
make

sudo apt-get remove cmake cmake-data

sudo make install
