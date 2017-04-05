#!/bin/sh
echo "Compile targets."
make
echo "Successfully compiled."
echo "Run executable.\n"
./cps
echo "Remove executable."
rm cps
