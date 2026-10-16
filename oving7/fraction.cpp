#include "fraction.hpp"

Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int numerator, int denominator) {
  set(numerator, denominator);
}

void Fraction::set(int numerator_, int denominator_) {
  if (denominator_ == 0) {
    throw "Nevneren kan ikke være null";
  }

  numerator = numerator_;
  denominator = denominator_;
  reduce();
}

Fraction Fraction::operator+(const Fraction &other) const {
  Fraction fraction = *this;
  fraction += other;
  return fraction;
}

Fraction &Fraction::operator+=(const Fraction &other) {
  set(numerator * other.denominator +
          denominator * other.numerator,
      denominator * other.denominator);

  return *this;
}

Fraction Fraction::operator-(const Fraction &other) const {
  Fraction fraction = *this;
  fraction -= other;
  return fraction;
}

Fraction &Fraction::operator-=(const Fraction &other) {
  set(numerator * other.denominator -
          denominator * other.numerator,
      denominator * other.denominator);

  return *this;
}

// Medlemsfunksjonen brukes ved fraction - heltall.
Fraction Fraction::operator-(int integer) const {
  Fraction fraction = *this;
  fraction -= Fraction(integer, 1);
  return fraction;
}

// Ikke-medlemsfunksjonen brukes ved heltall - fraction.
Fraction operator-(int integer, const Fraction &fraction) {
  Fraction result(integer, 1);
  result -= fraction;
  return result;
}

Fraction Fraction::operator*(const Fraction &other) const {
  Fraction fraction = *this;
  fraction *= other;
  return fraction;
}

Fraction &Fraction::operator*=(const Fraction &other) {
  set(numerator * other.numerator,
      denominator * other.denominator);

  return *this;
}

Fraction Fraction::operator/(const Fraction &other) const {
  Fraction fraction = *this;
  fraction /= other;
  return fraction;
}

Fraction &Fraction::operator/=(const Fraction &other) {
  set(numerator * other.denominator,
      denominator * other.numerator);

  return *this;
}

Fraction Fraction::operator-() const {
  return Fraction(-numerator, denominator);
}

Fraction &Fraction::operator++() {
  numerator += denominator;
  return *this;
}

Fraction &Fraction::operator--() {
  numerator -= denominator;
  return *this;
}

Fraction &Fraction::operator=(const Fraction &other) {
  numerator = other.numerator;
  denominator = other.denominator;
  return *this;
}

bool Fraction::operator==(const Fraction &other) const {
  return compare(other) == 0;
}

bool Fraction::operator!=(const Fraction &other) const {
  return compare(other) != 0;
}

bool Fraction::operator<=(const Fraction &other) const {
  return compare(other) <= 0;
}

bool Fraction::operator>=(const Fraction &other) const {
  return compare(other) >= 0;
}

bool Fraction::operator<(const Fraction &other) const {
  return compare(other) < 0;
}

bool Fraction::operator>(const Fraction &other) const {
  return compare(other) > 0;
}

void Fraction::reduce() {
  if (denominator < 0) {
    numerator = -numerator;
    denominator = -denominator;
  }

  int a = numerator;
  int b = denominator;

  if (a < 0) {
    a = -a;
  }

  while (b > 0) {
    int remainder = a % b;
    a = b;
    b = remainder;
  }

  numerator /= a;
  denominator /= a;
}

int Fraction::compare(const Fraction &other) const {
  Fraction difference = *this - other;

  if (difference.numerator > 0) {
    return 1;
  }

  if (difference.numerator < 0) {
    return -1;
  }

  return 0;
}