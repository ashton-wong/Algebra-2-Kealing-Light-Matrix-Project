#!/bin/bash

pip install -U -r python/refs/requirements.txt
pip install -U pytest

pytest python/
#pytest python/source/
