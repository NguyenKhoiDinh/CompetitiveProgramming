#include <bits/stdc++.h> 

using namespace std;
int numTest;

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    long long n, x0;
    cin >> x0 >> n;
    if (n == 0) {
      cout << x0 << endl;
      continue;
    }
    if (n == 1) {
      if (x0 % 2 == 0) {
        cout << x0 - 1 << endl;
      }
      else {
        cout << x0 + 1 << endl;
      }
      continue;
    }
    long long odd = n;
    if (n % 2 == 0) {
      odd--;
    }
    long long numOdd = odd / 2 + 1;  
    if (numOdd % 2 == 0) {
      odd = (numOdd / 2) * (-2); 
    }
    else {
      odd = ((numOdd - 1) / 2) * (-2) + odd; 
    }
    long long even = n; 
    if (n % 2 == 1) {
      even--; 
    }
    long long numEven = (even - 2) / 2 + 1; 
    if (numEven % 2 == 0) {
      even = (numEven / 2) * 2; 
    } 
    else {
      even = ((numEven - 1) / 2) * 2 - even; 
    }
    long long total = odd + even;
    if (x0 % 2 == 0) {
      total = -total; 
    } 
    cout << total + x0 << endl;
  }
  return 0; 
}
       
