#!/bin/bash

pip install -U -r python/refs/requirements.txt
pip install -U pytest

mv python/source/* "python/source/*_test"
pytest python/source/
