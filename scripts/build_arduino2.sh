#!/bin/bash

for f in arduino/main/*
do
  echo "Building $f"
  platformio ci --lib=Algebra-2-Kealing-Light-Matrix-Project/arduino/refs/* --lib=Algebra-2-Kealing-Light-Matrix-Project/arduino/source/* --board=uno $f
done
