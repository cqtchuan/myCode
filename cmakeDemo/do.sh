#!/bin/bash
rm -rf build
mkdir build
cd build 
cmake ..
make

echo "######the result of target is:"
../build/bin/test1
