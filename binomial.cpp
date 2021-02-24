#include "binomial.h"
#include "catch.hpp"

Binomial::Binomial() {coeff[1] = 1; coeff[2] = 1; power[1] = 1; power[2] = 1;}

Binomial::Binomial(float a) {coeff[1] = a; coeff[2] = 1; power[1] = 1; power[2] = 1;}

Binomial::Binomial(float a, int b) {coeff[2] = 1; power[2] = 1; coeff[1] = a;
  if (b < 1)
    power[1] = 1;
  else
    power[1] = b;}

Binomial::Binomial(float a, int b, float c) {power[2] = 1; coeff[1] = a;coeff[2] = c;
  if (b < 1)
    power[1] = 1;
  else
    power[1] = b;}

Binomial::Binomial(float a, int c, float b, int d) {coeff[1] = a; coeff[2] = b;
  if ((c < 1) && (d < 1)) {power[1] = 1; power[2] = 1;}
  else if ((c < 1) && (d >= 1)) {power[1] = 1; power[2] = d;}
  else if ((c >= 1) && (d < 1)) {power[1] = c; power[2] = 1;}
  else {power[1] = c; power[2] = d;}}

int Binomial::GetPower(int e) {
  if (power[e] == power[1])
    return power[1];
  if (power[e] == power[2])
    return power[2];
  else
    return -1;}

float Binomial::GetCoefficient(int f) {
  if (coeff[f] == coeff[1])
    return coeff[1];
  if (coeff[f] == coeff[2])
    return coeff[2];
  else
    return -1;}

int Binomial::SetPower(int g, int h) {
  if (((g == 1) || (g == 2)) && (h >= 0)) {power[g] = h; return 0;}
  else if ((h < 0) && ((g == 1) || (g == 2))) {power[g] = 1; return 0;}
  else if (((g != 1) || (g != 2)) && (h >= 0)) {power[1] = power[1]; power[2] = power[2]; return -1;}
  else if (((g != 1) || (g != 2)) && (h < 0)) {power[1] = power[1]; power[2] = power[2]; return -1;}
  else
    return -1;}

int Binomial::Add(Binomial a) {
  if (power[1] != a.power[1])
    return -1;
  else if ((power[1] == a.power[1]) && (power[2] != a.power[2])) {
    coeff[1] = coeff[1] + a.coeff[1];
    return 0;}
  else if ((power[1] == a.power[1]) && (power[2] == a.power[2])) {coeff[1] = coeff[1] + a.coeff[1]; coeff[2] = coeff[2] + a.coeff[2]; return 0;}
  else
    return -1;}

void Binomial::Multiply(float a) {coeff[1] = coeff[1] * a; power[1] = power[1]; coeff[2] = coeff[2] * a; power[2] = power[2];}
void Binomial::Multiply(float a, int b) {coeff[1] = coeff[1] * a; power[1] = power[1] + b; coeff[2] = coeff[2] * a; power[2] = power[2] + b;}

