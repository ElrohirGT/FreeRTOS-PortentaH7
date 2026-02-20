#!/usr/bin/env bash

set -xu

buildArchIfUnavailable() {
	if [ -d "./C$1/libs/" ]; then
		echo "./C$1/libs already exists! Skipping compilation of stm32h7..."
	else
		echo "./C$1/libs doesn't exist! Compiling..."
		(cd ./STM32H747 && ./build.sh "$1")
	fi
}

buildArchIfUnavailable M4
buildArchIfUnavailable M7

make MCU=M4
make MCU=M7
