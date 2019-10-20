#!/usr/bin/env bash

set -eu

if [ "${TRAVIS_OS_NAME}" != "osx" ]; then
    echo "Not a macOS build; skipping installation"
    exit 0
fi

