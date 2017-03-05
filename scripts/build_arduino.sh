#!/bin/bash

for f in arduino/*
do
  echo "Building $f"
  platformio ci --lib=libs/* --board=uno $f
done
