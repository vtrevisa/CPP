#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

make > /dev/null 2>&1

# Function to run a test case
run_test() {
	local expression="$1"
	local expected_output="$2"
	local description="$3"

	echo -e "${BLUE}$description${NC}"
	output=$(./rpn "$expression" 2>&1)
	if [ "$output" == "$expected_output" ]; then
		echo -e "${GREEN}PASS${NC}: $expression => $output"
	else
		echo -e "${RED}FAIL${NC}: $expression => $output (expected: $expected_output)"
	fi
	echo
}

# Test cases
run_test "8 9 * 9 - 9 - 9 - 4 - 1 +" "42" "TEST 1: SIMPLE RPN EXPRESSION"
run_test "7 7 * 7 -" "42" "TEST 2: MULTIPLICATION AND SUBTRACTION"
run_test "1 2 * 2 / 2 * 2 4 - +" "0" "TEST 3: MIXED OPERATIONS"
run_test "(1 + 1)" "ERROR: INVALID TOKEN IN RPN EXPRESSION" "TEST 4: INVALID EXPRESSION WITH PARENTHESES"
run_test "8 0 /" "ERROR: DIVISION BY ZERO" "TEST 5: DIVISION BY ZERO"
run_test "1 1 +" "2" "TEST 6: SIMPLE ADDITION"
run_test "9 5 -" "4" "TEST 7: SIMPLE SUBTRACTION"
run_test "2 3 *" "6" "TEST 8: SIMPLE MULTIPLICATION"
run_test "6 3 /" "2" "TEST 9: SIMPLE DIVISION"
run_test "5" "5" "TEST 10: SINGLE NUMBER, INVALID RPN EXPRESSION"
run_test "" "ERROR: INVALID RPN EXPRESSION" "TEST 11: EMPTY INPUT"

echo -e "${YELLOW}ALL TESTS COMPLETED.${NC}"

make fclean > /dev/null 2>&1