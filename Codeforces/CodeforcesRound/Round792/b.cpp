#include <bits/stdc++.h> 

using namespace std;
int numTest; 
int a, b, c; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> a >> b >> c; 
    long long z = c;
    long long y = b;
    long long k = (c - a) / b;
    long long x = (k + 1) * b + a; 
    cout << x << ' ' << y << ' ' << z << endl; 
  }
  return 0; 
}