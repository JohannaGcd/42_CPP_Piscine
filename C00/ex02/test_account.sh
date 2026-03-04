#!/usr/bin/env bash
set -u

PASS=0
FAIL=0

pass() {
  echo "[PASS] $1"
  PASS=$((PASS + 1))
}

fail() {
  echo "[FAIL] $1"
  FAIL=$((FAIL + 1))
}

echo "Building ex02..."
if make -s re; then
  pass "Build with project Makefile"
else
  fail "Build with project Makefile"
  echo "Result: $PASS passed, $FAIL failed"
  exit 1
fi

echo "Running executable and normalizing timestamps..."
./bankster | sed -E 's/^\[[0-9]{8}_[0-9]{6}\] //' > /tmp/ex02_actual_notime.log

if diff -q notime19920104_091532.log /tmp/ex02_actual_notime.log >/dev/null; then
  pass "Output matches notime reference log"
else
  fail "Output matches notime reference log"
  echo "--- Diff (expected vs actual) ---"
  diff -u notime19920104_091532.log /tmp/ex02_actual_notime.log | cat
fi

echo "Checking strict compile (-Wall -Wextra -Werror)..."
if c++ -Wall -Wextra -Werror -std=c++11 tests.cpp Account.cpp -o /tmp/ex02_strict_check 2>/tmp/ex02_strict_err.log; then
  pass "Strict compile"
else
  fail "Strict compile"
  echo "Compiler diagnostics:"
  cat /tmp/ex02_strict_err.log
fi

echo ""
echo "Result: $PASS passed, $FAIL failed"

if [ "$FAIL" -ne 0 ]; then
  exit 1
fi
