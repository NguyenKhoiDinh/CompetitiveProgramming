#include <bits/stdc++.h>

using namespace std;

int main () {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    if ((a <= 2 && b <= 1) || (a <= 1 && b <= 2)) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
  return 0; 
}