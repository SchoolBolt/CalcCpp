#!/bin/sh

g++ -std=c++11 -Wall -Wpedantic main.cpp Expressions/*.cpp Parser/*.cpp -o calc
