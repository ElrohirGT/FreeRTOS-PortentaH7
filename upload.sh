#!/usr/bin/env bash

set -exu

make MCU=M7 upload
make MCU=M4 upload
