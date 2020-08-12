#!/usr/bin/env bash

set -e

if [ $# -eq 0 ]
  then
    docker build -t utilforever/yahtzeemaster .
else
    docker build -f $1 -t utilforever/yahtzeemaster:$2 .
fi
docker run utilforever/yahtzeemaster