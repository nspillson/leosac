#!/bin/bash

TMP_DIR=$(mktemp -d)
set -x

echo "Working in $TMP_DIR"
function die()
{
#    rm -rf $TMP_DIR
    exit $1
}

## check that we are in leosac/test_helper and that we run the script from here
## ./test_working_directory.
[ `dirname $0` == "." ] || die -1

cp -R ../build $TMP_DIR
cp ../cfg/dev-test/amd64.xml $TMP_DIR

cd $TMP_DIR;

mkdir -p path/to/wd

## should fail, no valid path to plugin
if ./build/leosac -k $TMP_DIR/amd64.xml; then
    echo "Should have failed"
    die 1
fi
