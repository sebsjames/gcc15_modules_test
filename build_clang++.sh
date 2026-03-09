#!/bin/sh

# module tools.cppm
clang++-18 -std=c++20 -I. -Ijson/include -Wfatal-errors tools.cppm --precompile -o tools.pcm

# module test1.cppm
clang++-18 -std=c++20 -I. -Ijson/include -Wfatal-errors -fmodule-file=mplot.tools=tools.pcm test1.cppm --precompile -o test1.pcm

# main(). Something like:
# clang++-18 -std=c++20 main.cpp -fmodule-file=mplot.tools=tools.pcm -fmodule-file=test1=test1.pcm -o clang_compiled
