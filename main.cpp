#include <iostream>
#include "fraction.h"
using namespace std;

int main()
{
  cout << "Mike's Magic" << endl;
  Fraction f(1/2);
  Fraction g(2,4);
  
  f = g * 5;
  f.print();

  //g = f.reciprocal(); //as a member function
  g = recip(f); // as a NON-member function
  g.print();

  f.unreduce(10);
  f.print();
  f.setDen(20);
  f.print();

  f = g = f;

  //saved for yesterday...
  Fraction h(f); //calling the copy constructor
  h.print();

  if (f != h) {
    cout << "something is wrong with our copy constructor!" << endl;
  }
  if (f == h) {
    cout << "our copy constructor seems to be working!" << endl;
  }

  cout << "Done !" <<endl;

  return 0;
}
