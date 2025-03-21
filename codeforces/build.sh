#!/usr/bin/env sh
g++ -Wall -Wextra -pedantic -std=c++20 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op \
    -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC \
    -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector -I /home/ivan/cs/contests/codeforces/include $1 
