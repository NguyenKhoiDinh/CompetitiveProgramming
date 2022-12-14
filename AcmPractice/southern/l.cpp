#include <bits/stdc++.h> 

using namespace std;
int n;
int a[100005]; 
string s; 
long long sumOdd = 0LL, sumEven = 0LL, sum = 0LL; 

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; 
    sum += a[i];
    if (a[i] % 2 == 1) {
      sumOdd++;
    } 
    else {
      sumEven += a[i]; 
    }
  }
  cin >> s;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == '0') {
      if (sumEven == 0) {
        cout << sum << endl;
        continue; 
      } 
      sumEven = 0; 
      sum = 0; 
      for (int j = 1; j <= n; j++) {
        if (a[j] % 2 == 0) {
          a[j] /= 2;
          if (a[j] % 2 == 0) {
            sumEven += a[j]; 
          }  
          else {
            sumOdd++; 
          }
        }
        sum += a[j]; 
      }
      cout << sum << endl;  
    }
    else {
      if (sumOdd > 0) {
        for (int j = 1; j <= n; j++) {
          if (a[j] % 2 == 1) {
            a[j]--; 
          }
        }
      }
      sum -= sumOdd;
      sumEven = sum;
      sumOdd = 0;
      cout << sum << endl;   
    }
  }
  return 0; 
}