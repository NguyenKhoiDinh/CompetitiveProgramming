#include <bits/stdc++.h> 

using namespace std; 
long long sum(long long n) {
  if (n < 10) {
    return n; 
  }
  long long t = 0;
  while (n > 0) {
    t += n % 10;
    n /= 10; 
  }
  return sum(t); 
}

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    long long n;
    cin >> n;
    if (n == 0) {
      cout << 1; 
    } 
    else if (n == 1) {
      cout << 1; 
    }
    else if (n == 2) {
      cout << 2; 
    }
    else if (n == 3) {
      cout << 6; 
    }
    else if (n == 4) {
      cout << 6; 
    }
    else if (n == 5) {
      cout << 3; 
    }
    else {
      cout << 9; 
    }
    cout << endl; 
  }
  return 0; 
}