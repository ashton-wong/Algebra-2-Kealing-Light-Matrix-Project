#!/bin/bash

pip install -U -r python/refs/requirements.txt

mv "python/source/*" "python/source/*_test"
pytest python/source/
