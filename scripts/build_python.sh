#!/bin/bash

pip install -U -r python/refs/requirements.txt
pip install -U pytest

for g in python/source/*
do
  echo "Renaming $g"
  mv $f $f_test
done
ls
#pytest python/source/
