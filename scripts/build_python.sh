#!/bin/bash

pip install -U -r python/refs/requirements.txt

for q in python/source/*
do
  echo "Building $q"
  python -m py_compile $q
done
