#include <bits/stdc++.h> 

using namespace std;
int numTest;

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b <= c || b + c <= a || c + a <= b) {
      cout << "NO";
      return 0; 
    }
  }
  cout << "YES";
  return 0; 
}