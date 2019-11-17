/*
Aeman Abdulmuhssen
Student ID: 1003984
E-mail: aabdulmu@uoguelph.ca
*/


#include "a4.h"

int pow1( int base, int exp ){ /*alternate version of pow() to avoid compiler issues*/
  int result = base;

  if(exp == 1){
    return result;
  }

  if(exp == 0){
    return 1;
  }

  while( exp > 1 ){
  result = result * result;
  exp--;
  }
  return result;
}


int hash1( char *s, int max ){
  char *c;
  unsigned long result;
  int i;

  result = 0;
  i = 1;

  for(c=s; (*c); c++ ){
    result += (( *c ) * pow1(19,i)); /*each character is multiplied by a constant to the power of character's position*/
    i++;
  }

  return result % max;
}

int hash2( char *s, int max ){
  char *c;
  unsigned long result;
  int i, j;

  result = 0;
  i = 1;
  j = 1;

  for(c=s; (*c); c++ ){
    result += (( *c ) * pow1(19,i)) * 7 ;
    result += atoi(c) * j;
    j = j * 7;
    i++;
  }

  return result % max;
}


int hash3( char *s, int max ){
  int numMonths, numDays, numYear;
  unsigned long result;
  int dayspermonth[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if(s == NULL){
    return 0;
  }

  numMonths = atoi(s);
  numDays = atoi(s+3);
  numYear = atoi(s+6);
  result = 0;

  if(numMonths){
    numMonths--;
    while( numMonths != 0 ){
      result += dayspermonth[numMonths];
      numMonths--;
    }
    result += numDays;
    result += ((numYear - 1900) * 366); /*1900 was the lowest year in the file, each year has its own 366 indexes in hash map*/
  }

  /*some years have februray with 29 days so 366 days a year*/

  return result % max;
}
