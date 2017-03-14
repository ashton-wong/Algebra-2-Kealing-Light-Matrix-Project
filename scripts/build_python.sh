#!/bin/bash

pip install -U -r python/refs/requirements.txt

python -m py_compile python/source/\*.py
#pytest python/source/
