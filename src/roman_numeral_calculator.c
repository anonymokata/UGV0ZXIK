#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "roman_numeral_calculator.h"

static const int decimalValues[] = { 100, 50, 40, 10, 9, 5, 4, 1 };
static const char *romanNumerals[] = { "C", "L", "XL", "X", "IX", "V", "IV", "I" };

char *calculator_add(char *first, char *second)
{
  int decimalValue = parse_roman(first) + parse_roman(second);
  return convert_to_roman(decimalValue);
}

int parse_roman(char *value)
{
  int decimal = 0;
  int i;
  for(i=0; i<(int)strlen(value); i++)
  {
    switch(value[i])
    {
      case 'I' : decimal += 1; break;
      case 'V' : decimal += 5; break;
      case 'X' : decimal += 10; break;
      case 'L' : decimal += 50; break;
      case 'C' : decimal += 100; break;
    }
  }
  if(strstr(value, "IV") != NULL || strstr(value, "IX") != NULL)
  {
    decimal -= 2;
  }
  else if(strstr(value, "XL") != NULL)
  {
    decimal -= 20;
  }
  return decimal;
}

const char* convert_to_roman(int decimalValue)
{
  char romanNumeral[10] = "";

  int i;
  for(i=0; i<sizeof (decimalValues) / sizeof *(decimalValues); i++)
  {
    while(decimalValue - decimalValues[i] >= 0)
    {
      strcat( romanNumeral, romanNumerals[i]);
      decimalValue-= decimalValues[i];
    }
  }

  return romanNumeral;
}
