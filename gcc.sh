#!/bin/bash
make CROSS_COMPILE=/mnt/alps/Download/gcc-linaro-5.5.0-2017.10-x86_64_aarch64-elf/bin/aarch64-elf- O=out ARCH=arm64 -j4 $1 $2 $3 $4 $5 