#ifndef Binomial_h
#define Binomial_h

class Binomial {
  float coeff[3] = {0,1,1};
  int power[3] = {0,1,1};

public:
  Binomial(); Binomial(float a); Binomial(float a, int b);
  Binomial(float a, int b, float c); Binomial(float a, int c, float b, int d);

  int GetPower(int e); float GetCoefficient(int f);
  int SetPower(int g, int h); int Add(Binomial a);
  void Multiply(float a); void Multiply(float a, int b);};
#endif