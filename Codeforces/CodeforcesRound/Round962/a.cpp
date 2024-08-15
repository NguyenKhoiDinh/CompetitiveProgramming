#include <bits/stdc++.h>

using namespace std;

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    cin >> n;
    cout << (n / 4) + (n % 4) / 2 << endl;  
  }
  return 0; 
}