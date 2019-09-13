/*
This is the coding practice file for Udemy course "Mastering Data ...
Structure and Algorithms using C and C++. This file is for the Section 10 of ...
the course "Sparse Matrices".
*/

// Get the required libraries.
# include <stdio.h>
# include <stdlib.h>

struct term {
  /*
  A structure to store a term of a polynomial. A polynomia will simply be a ...
  sum of many terms.
  */
  // This is the power of x, which is n.
  int power;
  // This is the coefficient of x^n.
  int coeffecient;
};

struct polynomial {
  /*
  This is a structure that holds a polynomial. That is to say, it contains a ...
  number of terms.
  */
  // The number of non-zero coefficients in the polynomial.
  int cardinality;
  // A pointer to create required number of terms depending on runtime ...
  // in the polynomial.
  struct term *terms;
};

void create(struct polynomial *expression) {
  /*
  The funciton creates a polynomial. It sets the polynomial cardinality and ...
  sets the coeffecients and powers of other terms.
  */
  // A variable to navigate the polynomial.
  int i;
  printf("Creating a polynomial:\n");
  printf("Enter the number of terms:\n");
  scanf("%d",& expression->cardinality);
  expression->terms = (struct term *)malloc(expression->cardinality*
    sizeof(struct term));
  printf("Enter the terms of the polynomial:\n");
  for(i = 0; i < expression->cardinality; i++) {
    printf("\tEnter the power:\n\t");
    scanf("%d", &expression->terms[i].power);
    printf("\tEnter the coefficients:\n\t");
    scanf("%d", &expression->terms[i].coeffecient);
  }
}

void display(struct polynomial *expression) {
  /*
  The method dispalys a polynomial.
  */
  // Variable to navigate the polynomial.
  int i;
  printf("The polynomial is as folows:\n");
  for(i = 0; i < expression->cardinality - 1; i++)
    printf("%dx^%d+", expression->terms[i].coeffecient,
     expression->terms[i].power);
  printf("%dx^%d", expression->terms[i].coeffecient,
      expression->terms[i].power);
  printf("\n");
}

struct polynomial *add(struct polynomial *expression1,
  struct polynomial *expression2) {
  /*
  The method returns the sum of two polynomials. The polynomilas are assumed ...
  to be sorted in increasing order of powers.
  */
  // Variables to navigate the polynomials.
  int navigate1, navigate2, counter;
  navigate1 = 0;
  navigate2 = 0;
  counter = 0;
  // Create a structure to hold the sum.
  struct polynomial *b = (struct polynomial *)malloc(sizeof(struct polynomial));
  // Create an array of terms to hod the terms of the sum.
  struct term *t = (struct term *)malloc((expression1->cardinality
    + expression2->cardinality)*sizeof(struct term));
  // Add the polynomials.
  while(navigate1 < expression1->cardinality &&
    navigate2 < expression2->cardinality) {
    // Insert the lower power to the sum.
    if(expression1->terms[navigate1].power <
      expression2->terms[navigate2].power) {
      t[counter].power = expression1->terms[navigate1].power;
      t[counter++].coeffecient = expression1->terms[navigate1++].coeffecient;
    }
    else if(expression1->terms[navigate1].power >
      expression2->terms[navigate2].power) {
      t[counter].power = expression2->terms[navigate2].power;
      t[counter++].coeffecient = expression2->terms[navigate2++].coeffecient;
    }
    // Insert the sum of coeffecients when power match.
    else {
      t[counter].power = expression1->terms[navigate1].power;
      t[counter++].coeffecient = expression1->terms[navigate1++].coeffecient +
        expression2->terms[navigate2++].coeffecient;
    }
  }
  // Insert the remaining terms to the sum.
  while(navigate1 < expression1->cardinality) {
    t[counter].power = expression1->terms[navigate1].power;
    t[counter++].coeffecient = expression1->terms[navigate1++].coeffecient;
  }
  while(navigate2 < expression2->cardinality) {
    t[counter].power = expression2->terms[navigate2].power;
    t[counter++].coeffecient = expression2->terms[navigate2++].coeffecient;
  }
  // Set the carddinality of the sum.
  b->cardinality = counter;
  // Set the terms in the sum.
  b->terms = t;
  return b;
}

int main(int argc, char const *argv[]) {
  struct polynomial expression1, expression2;
  create(&expression1);
  create(&expression2);

  display(add(&expression1, &expression2));
  return 0;
}
