#!/bin/bash
wget -P /tmp https://github.com/zaynOm/alx-low_level_programming/raw/main/0x18-dynamic_libraries/myrand.so
export LD_PRELOAD=/tmp/myrand.so
