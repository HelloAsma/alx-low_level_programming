#!/bin/bash
wget -P /tmp https://github.com/pixie-a/alx-low_level_programming/blob/master/0x18-dynamic_libraries/libhack.so
export LD_PRELOAD="$PWD/tmp/libhack.so"
