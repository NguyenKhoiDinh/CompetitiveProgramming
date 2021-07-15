#include <bits/stdc++.h>

using namespace std;
int numTest; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    long long G;
    cin >> G; 
    G *= 2; 
    long long res = 0LL; 
    for (long long i = 1; i <= (long long) sqrt(G); i++) {
      if (G % i == 0) {
        long long x = i; 
        if (i * i != G) {
          long long y = G / i; 
          if ((x + y - 1) % 2 == 0) {
            long long n = (x + y - 1) / 2; 
            long long m = n - x; 
            if (n >= 0 && m >= 0) {
              res++; 
            }
          }
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}