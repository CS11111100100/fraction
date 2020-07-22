#include "fraction.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//default constructor with initialization list.
//Fraction::Fraction() : m_Numerator(1), m_Denominator(1) {}

Fraction::Fraction(const int num, const int den) : m_Numerator(num), m_Denominator(1) {
  setDen(den);
}

//Copy Const.
Fraction::Fraction(const Fraction & source) :
    m_Numerator(source.m_Numerator), m_Denominator(source.m_Denominator) { }

void Fraction::readin() {
  cout << " Give me a N ";
  cin  >> m_Numerator;
  do {
    cout << " Give me a D (that's not 0)! ";
    cin  >> m_Denominator;
  } while (m_Denominator == 0);
  return;
}

void Fraction::print() const {
  cout << "(" << m_Numerator << "/"
       << m_Denominator << ")" << endl;
}

// //reciprocal function but NOT a member
// Fraction recip(const Fraction in) {
//   Fraction toReturn;
//   if (in.getNum() != 0) {
//     toReturn.setNum(in.getDen());
//     toReturn.setDen(in.getNum());
//   }
//   return toReturn;
// }

//reciprocal function NOT a member
//BUT now as a FRIEND function!! :D
Fraction recip(const Fraction in) {
  Fraction toReturn;
  if (in.m_Numerator != 0) {
    toReturn.m_Numerator = in.m_Denominator;
    toReturn.m_Denominator = in.m_Numerator;
  }
  return toReturn;
}

Fraction Fraction::reciprocal() const {
  Fraction toReturn;
  if (m_Numerator != 0) {
    toReturn.m_Numerator = m_Denominator;
    toReturn.m_Denominator = m_Numerator;
  }
  return toReturn;
}

void Fraction::unreduce(const int m) {
  m_Numerator *= m;
  m_Denominator *= m;
  return;
}

bool Fraction::setDen(const int d) {
  bool set = false;
  if (d != 0) {
    set = true;
    m_Denominator = d;
  }
  return set;
}

Fraction& Fraction::operator=(const Fraction & rhs){
  m_Numerator = rhs.m_Numerator;
  m_Denominator = rhs.m_Denominator;
  return *this;
}

Fraction& Fraction::operator*=(const Fraction & rhs){
  m_Numerator *= rhs.m_Numerator;
  m_Denominator *= rhs.m_Denominator;
  return *this;
}

Fraction operator*(const Fraction & lhs, const Fraction & rhs) {
  Fraction toReturn(lhs);
  return (toReturn *= rhs);
}

bool operator==(const Fraction & lhs, const Fraction & rhs) {
  return lhs.m_Numerator*rhs.m_Denominator == rhs.m_Numerator*lhs.m_Denominator;
}

