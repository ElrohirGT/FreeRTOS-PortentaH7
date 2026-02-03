#!/bin/bash

set -exu

rm -r ./CM4/libs/ || echo "CM4 lib doesn't exist! Not cleaning..."
rm -r ./CM7/libs/ || echo "CM7 lib doesn't exist! Not cleaning..."

make MCU=M7 clean
make MCU=M4 clean
