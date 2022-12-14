#include <bits/stdc++.h>

using namespace std;

int l, r; 

bool isPrime(int p) {
  if (p == 1) {
    return false;
  }
  if (p == 2) {
    return true; 
  }
  for (int i = 2; i <= (int) sqrt(p); i++) {
    if (p % i == 0) {
      return false; 
    }
  }
  return true; 
}

int main () {
  cin >> l >> r; 
  for (int i = l; i <= r; i++) {
    if (isPrime(i) == true) {
      cout << i << endl;
    }
  }
  return 0; 
}