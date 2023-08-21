cmake_minimum_required(VERSION 3.14)
project (simpleREPL LANGUAGES CXX)


add_library(
  simpleREPL
    simpleREPL/src/args.tcc
    simpleREPL/src/eval.tcc
    simpleREPL/src/help.tcc
    simpleREPL/src/interface.tcc
    simpleREPL/src/io.cc
    simpleREPL/src/io.tcc
    simpleREPL/src/simpleREPL.h
    simpleREPL/src/tuple.tcc
    simpleREPL/src/types.tcc
  )

target_include_directories(
  simpleREPL
    PUBLIC simpleREPL/src
)