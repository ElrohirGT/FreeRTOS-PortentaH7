[![xc compatible](https://xcfile.dev/badge.svg)](https://xcfile.dev)

# FreeRTOS-PortentaH7

GSoC 2020 Arduino project.

[Portenta H7](https://www.arduino.cc/pro/hardware/product/portenta-h7) is a high
performance board released by [Arduino](https://www.arduino.cc).

## Tasks

### lib

Build the static library of STM32H7 for CM4 and CM7.

```sh
cd ./STM32H747/
./build.sh M4
./build.sh M7
```

### m4

Build the CM4 flash image, needs the static library to already be built!

```sh
make MCU=M4
```

### m7

Build the CM7 flash image, needs the static library to already be built!

```sh
make MCU=M7
```

### clean

Clean all generated artifacts (including the static library).

```sh
rm -r ./CM4/libs/ || echo "CM4 lib doesn't exist! Not cleaning..."
rm -r ./CM7/libs/ || echo "CM7 lib doesn't exist! Not cleaning..."

make MCU=M7 clean
make MCU=M4 clean
```

### flash

Inputs: CORE

Flash the to the specified core.

```sh
make MCU="$CORE" upload
```
