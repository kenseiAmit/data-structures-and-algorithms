/*
This is the coding practice file for Udemy course "Mastering Data ...
Structure and Algorithms using C and C++. This file is for the Section 10 of ...
the course "Sparse Matrices".
*/

// Get the required libraries.
# include <stdio.h>
# include <stdlib.h>
# include <iostream>

using namespace std;

class term {
  /*
  A class to store a term of a polynomial. A polynomia will simply be a ...
  sum of many terms.
  */
public:
  // This is the power of x, which is n.
  int power;
  // This is the coefficient of x^n.
  int coeffecient;
};

class polynomial {
  /*
  This is a class that holds a polynomial. That is to say, it contains a ...
  number of terms.
  */
  // The number of non-zero coefficients in the polynomial.
private:
  int cardinality;
  // A pointer to create required number of terms depending on runtime ...
  // in the polynomial.
  term *terms;

public:
  polynomial(){
    cardinality = 0;
    terms = NULL;
  }
  polynomial (int cardinality) {
    this->cardinality = cardinality;
    terms = new term[cardinality];
  }
  polynomial (int cardinality, term *terms) {
    this->cardinality = cardinality;
    this->terms = new term[cardinality];
    this->terms = terms;
  }
  ~polynomial() { delete [] terms;}
  polynomial operator+(polynomial &expression);
  friend istream & operator>>(istream &input_stream, polynomial &expression);
  friend ostream & operator<<(ostream &output_stream, polynomial &expression);
};

istream & operator>>(istream &input_stream, polynomial &expression) {
  /*
  The funciton creates a polynomial. It sets the polynomial cardinality and ...
  sets the coeffecients and powers of other terms.
  */
  // Prompt the user to input the polynomial.
  cout<<"Enter the terms of the polynomial:\n";
  for(int i = 0; i < expression.cardinality; i++) {
    cout<<"\tEnter the power:\n\t";
    cin>>expression.terms[i].power;
    cout<<"\tEnter the coefficients:\n\t";
    cout<<expression.terms[i].coeffecient;
  }
  return input_stream;
}

ostream & operator<<(ostream &output_stream, polynomial &expression) {
  /*
  The method dispalys a polynomial.
  */
  int i;
  cout<<"The polynomial is as folows:\n";
  for(i = 0; i < expression.cardinality - 1; i++)
    cout<<expression.terms[i].coeffecient<<"x^"<<expression.terms[i].power
      <<" + ";
  cout<<expression.terms[i].coeffecient<<"x^"<<expression.terms[i].power;
  cout<<"\n";
  return output_stream;
}

polynomial polynomial::operator+(polynomial &expression) {
  /*
  The method returns the sum of two polynomials. The polynomilas are assumed ...
  to be sorted in increasing order of powers.
  */
  // Variables to navigate the polynomials.
  int navigate1 = 0, navigate2 = 0, counter = 0;
  // Create a structure to hold the sum.
  polynomial *b = new polynomial;
  // Create an array of terms to hod the terms of the sum.
  term *t = new term[cardinality + expression.cardinality];
  // Add the polynomials.
  while(navigate1 < cardinality && navigate2 < expression.cardinality) {
    // Insert the lower power to the sum.
    if(terms[navigate1].power < expression.terms[navigate2].power) {
      t[counter].power = terms[navigate1].power;
      t[counter++].coeffecient = terms[navigate1++].coeffecient;
    }
    else if(terms[navigate1].power > expression.terms[navigate2].power) {
      t[counter].power = expression.terms[navigate2].power;
      t[counter++].coeffecient = expression.terms[navigate2++].coeffecient;
    }
    // Insert the sum of coeffecients when power match.
    else {
      t[counter].power = terms[navigate1].power;
      t[counter++].coeffecient = terms[navigate1++].coeffecient +
        expression.terms[navigate2++].coeffecient;
    }
  }
  // Insert the remaining terms to the sum.
  while(navigate1 < cardinality) {
    t[counter].power = terms[navigate1].power;
    t[counter++].coeffecient = terms[navigate1++].coeffecient;
  }
  while(navigate2 < expression.cardinality) {
    t[counter].power = expression.terms[navigate2].power;
    t[counter++].coeffecient = expression.terms[navigate2++].coeffecient;
  }
  // Set the carddinality of the sum.
  b->cardinality = counter;
  // Set the terms in the sum.
  b->terms = t;
  return *b;
}

int main(int argc, char const *argv[]) {
  polynomial expression1, expression2;
  //create(&expression1);
  //create(&expression2);

  //cout<<(expression1 + expression2));
  return 0;
}
