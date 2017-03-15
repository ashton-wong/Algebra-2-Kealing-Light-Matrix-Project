#!/bin/bash

ls home/
#home/local/lib/python2.7/dist-packages/pip install --user -U -r python/refs/requirements.txt

for q in python/source/*
do
  echo "Building $q"
  python -m py_compile $q
done
