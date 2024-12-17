#include <bits/stdc++.h> 

using namespace std;

int main () {
  double ans = 0.0; 
  for (int i = 1; i <= 100000; i += 2) {
    ans += pow(0.5, i); 
  }
  cout << fixed << setprecision(12) << ans;
  return 0; 
}