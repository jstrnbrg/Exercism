#include "armstrong_numbers.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
Algorithm:
- turn candidate int to string
- split digits => array of digits as strings
- loop over array and reduce: sum + digit ^ 2
- return int  == sum ?
*/

bool is_armstrong_number(int candidate) {
  // Guard clause: 0 is an armstrong number
  if (candidate == 0) {
    return true;
  }
  
  // Turn int candidate into char array
  int length = (int)((ceil(log10(candidate))+1)*sizeof(char));
  char digit_str[length];
  sprintf(digit_str, "%d", candidate);

  // loop over array and reduce into sum
  int sum = 0;
  int num_digits = strlen(digit_str);
  for (int i=0; i < num_digits; i++) {
    int x = (int)digit_str[i] - 48;
    sum += pow(x, num_digits);
  }

  return sum == candidate;
}
