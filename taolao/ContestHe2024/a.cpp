#include <bits/stdc++.h> 

using namespace std; 
int numTest; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int a, b;
    cin >> a >> b;
    if (a % b == 0) {
      cout << a / b; 
    }
    else {
      cout << -1;
    }
    cout << endl;
  }
  return 0; 
}