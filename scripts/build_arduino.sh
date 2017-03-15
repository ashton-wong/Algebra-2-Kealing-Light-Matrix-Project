#!/bin/bash

./local/lib/python2.7/dist-packages/pip install --user -U platformio

for f in arduino/main/*
do
  echo "Building $f"
  platformio ci --lib=arduino/refs/* --lib=arduino/source/* --board=uno $f
done
