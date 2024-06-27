#!/bin/bash

# Color definitions
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Function to execute a test and display results
run_test() {
    local description="$1"
    local command="$2"
    local expected_before="$3"
    local expected_after="$4"

    echo -e "${BLUE}* ${description}${NC}"

    # Print expected results
    echo -e "${GREEN}Expected Before:${NC} $expected_before"
    echo -e "${GREEN}Expected After:${NC} $expected_after"

    # Execute the command and capture the output
    actual_output=$(eval "$command 2>&1")

    # Print actual results
    echo -e "${GREEN}Actual Output:${NC}"
    echo "$actual_output"

    echo -e "${GREEN}========================================${NC}\n"
}

# Run `make` first
echo -e "${BLUE}Building the program...${NC}"
if make; then
    echo -e "${GREEN}Build successful.${NC}\n"
else
    echo -e "${RED}Build failed. Exiting.${NC}"
    exit 1
fi

# Test 1: Basic input sequence
expected_before="Before: 3 5 9 7 4"
expected_after="After: 3 4 5 7 9"
run_test "Test 1: Basic input sequence" "./pmergeme 3 5 9 7 4" "$expected_before" "$expected_after"

# Test 2: Large random sequence
run_test "Test 2: Large random sequence" "./pmergeme \$(shuf -i 1-100000 -n 3000 | tr \"\\n\" \" \")" "Before:" "After:"

# Test 3: Invalid input (negative number)
run_test "Test 3: Invalid input (negative number)" "./pmergeme -1 2" "" "Error"

# Test 4: Large random sequence for OSX users
run_test "Test 4: Large random sequence for OSX users" "./pmergeme \$(jot -r 3000 1 100000 | tr '\\n' ' ')" "Before:" "After:"

# Additional Tests

# Test 5: Empty input
run_test "Test 5: Empty input" "./pmergeme" "" "Error"

# Test 6: Single element
expected_before="Before: 42"
expected_after="After: 42"
run_test "Test 6: Single element" "./pmergeme 42" "$expected_before" "$expected_after"

# Test 7: Already sorted sequence
expected_before="Before: 1 2 3 4 5"
expected_after="After: 1 2 3 4 5"
run_test "Test 7: Already sorted sequence" "./pmergeme 1 2 3 4 5" "$expected_before" "$expected_after"

# Test 8: Reverse sorted sequence
expected_before="Before: 5 4 3 2 1"
expected_after="After: 1 2 3 4 5"
run_test "Test 8: Reverse sorted sequence" "./pmergeme 5 4 3 2 1" "$expected_before" "$expected_after"

# Test 9: All elements the same
expected_before="Before: 7 7 7 7 7"
expected_after="After: 7 7 7 7 7"
run_test "Test 9: All elements the same" "./pmergeme 7 7 7 7 7" "$expected_before" "$expected_after"

# Test 10: Large sequence with small numbers
expected_before="Before: 3 1 4 1 5 9 2 6 5 3 5 9 7 9 3 2 3 8 4 6 2 6 4 3 3 8 3 2 7 9"
expected_after="After: 1 1 2 2 2 3 3 3 3 3 4 4 4 5 5 5 6 6 6 7 7 8 8 9 9 9 9"
run_test "Test 10: Large sequence with small numbers" "./pmergeme 3 1 4 1 5 9 2 6 5 3 5 9 7 9 3 2 3 8 4 6 2 6 4 3 3 8 3 2 7 9" "$expected_before" "$expected_after"

# Test 11: Mix of small and large numbers
expected_before="Before: 3 1000000 4 999999 5 1 2 100000 0"
expected_after="After: 0 1 2 3 4 5 100000 999999 1000000"
run_test "Test 11: Mix of small and large numbers" "./pmergeme 3 1000000 4 999999 5 1 2 100000 0" "$expected_before" "$expected_after"

# Test 12: Sequence with maximum and minimum integers
expected_before="Before: 2147483647 0 2147483646"
expected_after="After: 0 2147483646 2147483647"
run_test "Test 12: Sequence with maximum and minimum integers" "./pmergeme 2147483647 0 2147483646" "$expected_before" "$expected_after"

# End of tests
echo -e "${GREEN}All tests completed.${NC}"

# Clean up
make fclean
