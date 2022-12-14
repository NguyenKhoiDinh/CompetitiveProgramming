#include <bits/stdc++.h> 

using namespace std;

int main () {
  double E, W, S;
  cin >> E >> W >> S; 
  double ans = E / S * W; 
  cout << fixed << setprecision(10) << ans; 
  return 0; 
}