#include <bits/stdc++.h> 

using namespace std; 
int n; 
long long x[100005]; 
long long y, z; 

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i]; 
  }
  cin >> y >> z;
  for (int i = 1; i <= n; i++) {
    x[i] = abs(x[i] - z); 
  } 
  int ans = 0; 
  sort(x + 1, x + n + 1); 
  long long dist = abs(y - z); 
  long long cur = 0; 
  for (int i = 1; i <= n; i++) {
    if (cur + x[i] < dist) {
      ans++; 
      cur += x[i]; 
    }  
    else {
      break; 
    }
  }
  cout << ans;
  return 0; 
}