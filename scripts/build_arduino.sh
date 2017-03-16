#!/bin/bash

pip install --user -U platformio

for f in arduino/main/*
do
  echo "Building $f"
  platformio ci --lib=arduino/refs/* --lib=arduino/source/* --board=uno $f
done
