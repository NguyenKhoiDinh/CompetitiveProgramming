#include <bits/stdc++.h>

using namespace std;

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    string s;
    cin >> n >> s;
    if (n == 1) {
      cout << "NO"; 
    }  
    else {
      cout << (s[0] == s.back() ? "NO" : "YES");
    }
    cout << endl;
  }
  return 0; 
}