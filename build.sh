# !/bin/sh
#

cd build/
cmake ..
make

clear

./CynthCompiler ../main.cy
