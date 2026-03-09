clang++-18 -std=c++20 -I. -Ijson/include -Wfatal-errors tools.cppm --precompile -o tools.pcm
clang++-18 -std=c++20 -I. -Ijson/include -Wfatal-errors -fmodule-file=mplot.tools=tools.pcm test1.cppm --precompile -o test1.pcm
