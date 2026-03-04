#!/usr/bin/env bash

PASS=0
FAIL=0

run_case() {
    local name="$1"
    local input="$2"
    local must_contain="$3"
    shift 3

    local output
    output=$(printf "%b" "$input" | ./phonebook)

    if echo "$output" | grep -Fq -- "$must_contain"; then
        echo "[PASS] $name"; PASS=$((PASS+1))
    else
        echo "[FAIL] $name"
        echo "  expected to contain: '$must_contain'"
        echo "  got     : '$output'"
        FAIL=$((FAIL + 1))
    fi
}

echo "Building phonebook..."
if ! make -s re; then
    echo "Build failed"
    exit 1
fi

echo "Running tests..."
run_case "Exit immediately" "EXIT\n" "Please enter your command"
run_case "Search when empty" "SEARCH\nEXIT\n" "No contacts available. Please add a contact first."
run_case "Add then search index 0" "ADD\nJohn\nDoe\nJD\n12345\nsecret\nSEARCH\n0\nEXIT\n" "John"
run_case "Add two contacts, then search index 1" "ADD\nJames\nDean\nJD\n12345\nsecret\nADD\nJohn\nTravolta\nJohnny\n12354\ngay\nSEARCH\n1\nEXIT\n" "John"
run_case "empty SEARCH" "SEARCH\n     \nEXIT\n" "No contacts available. Please add a contact first."
run_case "invalid SEARCH index" "ADD\nJohn\nDoe\nJD\n12345\nsecret\nSEARCH\n1\nEXIT\n" "You must enter a number between 0 "
run_case "9th-add overwrite behavior" "ADD\nJohn\nDoe\nJD\n12345\nsecret\nADD\nJohn\nDoe\nJD\n12345\nsecret\nADD\nJohn\nDoe\nJD\n12345\nsecret\nADD\nJohn\nDoe\nJD\n12345\nsecret\nADD\nJohn\nDoe\nJD\n12345\nsecret\nADD\nJohn\nDoe\nJD\n12345\nsecret\nADD\nJohn\nDoe\nJD\n12345\nsecret\nADD\nJohn\nDoe\nJD\n12345\nsecret\nADD\nMARTHA\nDoe\nJD\n12345\nsecret\nSEARCH\n0\nEXIT\n" "MARTHA"

echo ""
echo "Result: $PASS passed, $FAIL failed"

if [ "$FAIL" -ne 0 ]; then
    exit 1
fi