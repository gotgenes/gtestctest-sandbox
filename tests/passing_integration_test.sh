#!/bin/bash

# Runs the exectuable provided as the argument.
#
# Example usage:
#
#   integration_test.sh /path/to/execexample
#

set -e
set -u

THE_EXECUTABLE=$1
result=$($THE_EXECUTABLE)
expected='Got 1'
difference=$(diff <(echo "$result") <(echo "$expected"))

# If there is no difference between the result and expected, diff
# will be empty.
if [ -z "$difference" ]; then
    exit 0
else
    # Send a failure exit signal.
    exit 1
fi

