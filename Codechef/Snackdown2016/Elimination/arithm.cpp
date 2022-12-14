#include <bits/stdc++.h> 

using namespace std;
int numTest; 

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    long long n, C; 
    cin >> n >> C;
    C = C * 2LL; 
    if (C % n != 0) {
      cout << "No" << endl;
      continue;
    }
    C /= n; 
    if (C % 2 == 1 && n % 2 == 1) {
      cout << "No" << endl;
      continue; 
    }
    long long l = 1;
    long long r = C / (n - 1); 
    if (r < l) {
      cout << "No" << endl;
      continue;
    }
    long long d = 1; 
    if (C % 2 == (n - 1) % 2) {
      if (C - (n - 1) >= 2) {
        cout << "Yes" << endl;
      }
      else {
        cout << "No" << endl; 
      }
    }
    n * x + (1 + 2 + 3 + ... + n - 1) * d = C 
    n * x + n * (n - 1) / 2 * d = C
    2 * n * x + n * (n - 1) * d = 2 * C

    2 * x + (n - 1) * d = 2 * C / n
  } 
  return 0; 
}