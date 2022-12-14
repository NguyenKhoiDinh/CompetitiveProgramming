#include <bits/stdc++.h>

using namespace std;
int numTest;

int main () {
  //freopen("input.txt", "r", stdin);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d; 
    if (max(a, b) < min(c, d) || max(c, d) < min(a, b)) {
      cout << "NO";
    }
    else {
      cout << "YES";
    }
    cout << endl;
  }
  return 0;
}