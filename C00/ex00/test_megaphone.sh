#!/usr/bin/env bash

PASS=0
FAIL=0

run_case() {
    local name="$1"
    local expected="$2"
    shift 2

    local output
    output=$(./megaphone "$@")

    if [ "$output" = "$expected" ]; then
        echo "[PASS] $name"
        PASS=$((PASS + 1))
    else
        echo "[FAIL] $name"
        echo "  expected: '$expected'"
        echo "  got     : '$output'"
        FAIL=$((FAIL + 1))
    fi
}

echo "Building megaphone..."
if ! make -s re; then
    echo "Build failed"
    exit 1
fi

echo "Running tests..."
run_case "No args" "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
run_case "Subject example 1" "SHHHHH... I THINK THE STUDENTS ARE ASLEEP..." "shhhhh... I think the students are asleep..."
run_case "Subject example 2" "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF." "Damnit" " ! " "Sorry students, I thought this thing was off."

echo ""
echo "Result: $PASS passed, $FAIL failed"

if [ "$FAIL" -ne 0 ]; then
    exit 1
fi
