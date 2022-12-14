#include <bits/stdc++.h> 

using namespace std;

int main () {
  int n; 
  cin >> n; 
  double total = 1.00000000000 * (n - 1) * (n - 2) / 2.000000000000;
  cout << fixed << setprecision(12) << total << endl;
  for (int i = 2; i <= n; i++) {
    cout << 1 << ' ' << i << endl;
  }   
  return 0; 
}