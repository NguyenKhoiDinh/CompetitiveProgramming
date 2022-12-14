#include <bits/stdc++.h> 

using namespace std; 

double power(const double x, int n) {
  if (n == 0) {
    return 1.0; 
  }
  double ret = power(x, n / 2); 
  ret = ret * ret; 
  if (n % 2 == 1) {
    ret = ret * x; 
  }
  return ret; 
}

class Delina {
  public: 
  double getProbability(int T, int G) {
    double p = 1.0 * (T - 1) / 20.0; 
    double ans = 1.0;
    for (int i = G + 1; i <= 5000000; i++) {
      ans *= (1.0 - power(p, i)); 
    }  
    return ans;
  }
};
Delina D; 

int main () {
  cout << fixed << setprecision(20) << D.getProbability(15, 50); 
  return 0; 
}