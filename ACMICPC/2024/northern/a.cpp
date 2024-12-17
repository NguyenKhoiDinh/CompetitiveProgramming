#include <bits/stdc++.h> 

using namespace std;
int n, D, H;
int a[10005]; 
int f[10005]; 

int main () {
  cin >> n >> D >> H;
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; 
  }
  for (int i = 2; i <= n; i++) {
    f[i] = 1000000007; 
  }
  f[1] = a[1]; 
  for (int i = 2; i <= n; i++) {
    for (int j = i - 1; j >= max(1, i - D); j--) {
      if (abs(a[i] - a[j]) <= H) {
        f[i] = min(f[i], f[j] + a[i]); 
      }
    }  
  }
  cout << f[n];
  return 0; 
}