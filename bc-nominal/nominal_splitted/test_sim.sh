#!/bin/bash

CURRENTDIR=$(dirname $0)
cd $CURRENTDIR

COMPILER="$CURRENTDIR/../../compiler/mtl_simu"

./make_nominal.sh

[ $? -eq 0 ] || { echo "Could not make nominal.mtl" ;  }

"$COMPILER" --mac 0123456789ab --source "../nominal.mtl"
