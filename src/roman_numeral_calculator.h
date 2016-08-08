#ifndef ROMAN_NUMERAL_CALCULATOR_H
#define ROMAN_NUMERAL_CALCULATOR_H

#define MAX_VALUE 3999

#define OPERATOR_ADD '+'
#define OPERATOR_SUBTRACT '-'

#define MESSAGE_INVALID_INPUT "INVALID INPUT"
#define MESSAGE_INVALID_OPERATION "INVALID OPERATION"

char *calculate(char *first, char *second, char operator);

#endif /* ROMAN_NUMERAL_CALCULATOR_H */
