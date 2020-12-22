#! /bin/bash
make clean
rm -rf CMakeFiles CMakeCache.txt
cmake .
make
