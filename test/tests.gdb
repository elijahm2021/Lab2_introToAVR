# Test file for "Lab2_introToAVR"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

test “PINA: 0, PINB: 0, PINC: 0 => PORTD: 0x00”
setPINA 0x00
setPINB 0x00
setPINC 0x00
continue 5
expectPORTD 0x00
checkResult

test "PINA: 5, PINB: 5, PINC: 5 => PORTD: 0x0C"
setPINA 0x05
setPINB 0x05
setPINC 0x05
continue 5
expectPORTD 0x0C
checkResult

test "PINA: 47, PINB: 47, PINC: 46 => PORTD: 0x8C"
setPINA 47
setPINB 47
setPINC 46
continue 5
expectPORTD 0x8C
checkResult

test "PINA: 107, PINB: 17, PINC: 17 => PORTD: 0x8F"
setPINA 107
setPINB 17
setPINC 17
expectPORTD 0x8F
checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests

echo ======================================================\n
