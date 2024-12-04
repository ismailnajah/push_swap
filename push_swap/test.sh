#!/bin/bash

arg=$(shuf -i 0-$1 -n $1 | tr '\n' ' ')
echo "test: [$arg]"
steps=$(./push_swap $arg | wc -l)
echo "number of instructions: $steps"
echo "checker result: $(./push_swap $arg | ../checker_linux $arg)"
