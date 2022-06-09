#include <iostream>
#include <math.h>
#include <stdio.h>
#include <cassert>
using namespace std;



class Polynomial {
public:
  Polynomial();
  Polynomial(int capacity);
  Polynomial(const Polynomial& poly); //copy constructor
  ~Polynomial();

  Polynomial operator + (const Polynomial& rhs);
  Polynomial operator - (const Polynomial& rhs);
  Polynomial operator * (const Polynomial& rhs);
  void operator = (const Polynomial& rhs);

  friend Polynomial operator * (const Polynomial& lhs, double rhs);
  friend Polynomial operator * (double lhs, const Polynomial& rhs);
  friend Polynomial operator - (double lhs, const Polynomial& rhs);

  double& operator [](int index);
  double valueAt(double value);

private:
  double *coefficients;
  int capacity_;
  int used_;
};

int main() {
  return 0;
}

Polynomial::Polynomial() {
  capacity_ = 1;
  used_ = 0;
  coefficients = new double[capacity_];

}

Polynomial::Polynomial(int capacity) {
  capacity_ = capacity;
  used_ = 0;
  coefficients = new double[capacity_];
}

Polynomial::Polynomial(const Polynomial& other) {
  capacity_ = other.capacity_;
  used_ = other.used_;
  coefficients = new double[capacity_];
  for (int i = 0; i < used_; i++) {
    coefficients[i] = other.coefficients[i];
  }
}

Polynomial::~Polynomial() {
  delete[] coefficients;
  coefficients = nullptr;
}

Polynomial Polynomial::operator + (const Polynomial& rhs) {
  if (used_ < rhs.used_) {
    Polynomial ans(rhs.capacity_);
    int difference = rhs.used_ - used_;
    for (int i = 0; i <= used_; i++) {
      ans[i] = coefficients[i] + rhs.coefficients[i];
      ans.used_++;
    }

    for (int j = used_ + 1; j < rhs.used_; j++) {
      ans[j] = rhs.coefficients[j];
    }

    return ans;
  }

  else { //used_ >= rhs.used_
    Polynomial ans(capacity_);
    int difference = used_ - rhs.used_;
    for (int i = 0; i <= rhs.used_; i++) {
      ans[i] = coefficients[i] + rhs.coefficients[i];
      ans.used_++;
    }

    for (int j = used_ + 1; j < used_; j++) {
      ans[j] = coefficients[j];
    }

    return ans;

  }
}

Polynomial Polynomial::operator - (const Polynomial& rhs){
  if (used_ < rhs.used_) {
    Polynomial ans(rhs.capacity_);
    int difference = rhs.used_ - used_;
    for (int i = 0; i <= used_; i++) {
      ans[i] = coefficients[i] - rhs.coefficients[i];
      ans.used_++;
    }

    for (int j = used_ + 1; j < rhs.used_; j++) {
      ans[j] = rhs.coefficients[j];
    }

    return ans;
  }

  else { //used_ >= rhs.used_
    Polynomial ans(capacity_);
    int difference = used_ - rhs.used_;
    for (int i = 0; i <= rhs.used_; i++) {
      ans[i] = coefficients[i] - rhs.coefficients[i];
      ans.used_++;
    }

    for (int j = used_ + 1; j < used_; j++) {
      ans[j] = coefficients[j];
    }

    return ans;

  }
}
Polynomial Polynomial::operator * (const Polynomial& rhs) {
  if (used_ < rhs.used_) {
    Polynomial ans((used_ + rhs.used_));
    for (int i = 0; i < used_; i++) {
      for (int j = 0; j < ans.used_; j++) {
        ans.coefficients[i+j] += coefficients[i] * rhs.coefficients[j];
      }
    }
    return ans;
  }

  else {
    Polynomial ans((used_ + rhs.used_));
    for (int i = 0; i < rhs.used_; i++) {
      for (int j = 0; j < used_; j++) {
        ans.coefficients[i+j] += coefficients[i] * coefficients[j];
      }
    }
    return ans;
  }
}

void Polynomial::operator = (const Polynomial& rhs) {

}

double& Polynomial::operator [](int index){
  assert(index < used_);
  return coefficients[index];
}
double Polynomial::valueAt(double value) {
  double ans = 0.0;
  for (int i = 0; i <= used_; i++) {
    ans += (coefficients[i] * pow(value, i));
  }

  return ans;
}




Polynomial operator + (const Polynomial& lhs, double rhs) {
  Polynomial ans(lhs);
  ans[0] += rhs;
  return ans;
}
Polynomial operator - (const Polynomial& lhs, double rhs) {
  Polynomial ans(lhs);
  ans[0] -= rhs;
  return ans;
}
Polynomial operator * (const Polynomial& lhs, double rhs) {
  Polynomial ans(lhs);
  for (int i = 0; i < ans.used_; i++) {
    ans[i] *= rhs;
  }

  return ans;

}

Polynomial operator + (double lhs, const Polynomial& rhs) {
  Polynomial ans(rhs);
  ans[0] += lhs;
  return ans;
}

Polynomial operator - (double lhs, const Polynomial& rhs) {
  Polynomial ans(rhs);
  ans[0] -= lhs;
  for (int i = 1; i < ans.used_; i++) {
    ans.coefficients[i] *= -1;
  }
  return ans;
}

Polynomial operator * (double lhs, const Polynomial& rhs) {
  Polynomial ans(rhs);
  for (int i = 0; i < ans.used_; i++) {
    ans[i] *= lhs;
  }

  return ans;
}
