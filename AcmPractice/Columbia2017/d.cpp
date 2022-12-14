#include <bits/stdc++.h> 

using namespace std; 
int n; 

int main () {
  //freopen("input.txt", "r", stdin); 
  cin >> n; 
  string res = ""; 
  while (n > 0) {
    if (n % 2 == 1) {
      res += 'A'; 
      n = (n - 1) / 2; 
    }
    else {
      res += 'B'; 
      n = (n - 2) / 2; 
    }
  }
  reverse(res.begin(), res.end()); 
  cout << res;
  return 0; 
}