#!/bin/bash
pushd src
gcc -std=c99 -pedantic -o keen keen.c keen_codes.c keen_io.c keen_validation.c
popd
