#!/bin/sh

/opt/gcc-15/bin/g++ -std=c++20 -fmodules -c tools.cppm -I. -Ijson/include -Wfatal-errors

/opt/gcc-15/bin/g++ -std=c++20 -fmodules -c test1.cppm -I. -Ijson/include -Wfatal-errors
