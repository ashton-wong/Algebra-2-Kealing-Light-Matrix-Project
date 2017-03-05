#!/bin/bash

for f in arduino/source/*
do
  echo "Building $f"
  platformio ci --lib=libs/* --board=uno $f
done
