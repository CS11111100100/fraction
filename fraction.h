//fraction.h
#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
 public:
  //Fraction(); //default constructor
  Fraction() : m_Numerator(1), m_Denominator(1) {}
  Fraction(const int n) : m_Numerator(n), m_Denominator(1) {}
  Fraction(const int num, const int den);
  //Copy Constructor
  Fraction(const Fraction & source);

  //post m_N and m_D have user data and m_D != 0
  void readin();
  void print() const;
  //desc: A new fraction is returned which is the reciprocal of the original object
  //Pre:  original cannot have a 0 numerator
  //Post: New Fraction is returned, original is unchanged
  Fraction reciprocal() const;
  void unreduce(const int m);
  //accessor functions
  inline int getDen() const {return m_Denominator;}
  inline int getNum() const {return m_Numerator;}
  //mutator functions
  bool setDen(const int d);
  void setNum(const int n) {m_Numerator = n;}
  //Friend Functions
  friend Fraction recip(const Fraction in);

  Fraction& operator =(const Fraction & rhs); //modifying - member func.
  Fraction& operator *=(const Fraction & rhs); //modifying - member func.
  friend Fraction operator *(const Fraction & lhs, const Fraction & rhs);
  friend bool operator==(const Fraction & lhs, const Fraction & rhs);
 private:
  int m_Numerator;
  int m_Denominator;
};

//reworking as friend 
//Fraction recip(const Fraction in);

inline bool operator!=(const Fraction & lhs, const Fraction & rhs)
  {return !(lhs==rhs);}
 
#endif
