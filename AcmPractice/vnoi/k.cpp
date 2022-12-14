#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 1000005;           
long long x[MAX_N], y[MAX_N];
int n; 
long long changex[MAX_N], changey[MAX_N];  

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i]; 
    changex[i - 1] = x[i] + y[i];
    changey[i - 1] = x[i] - y[i]; 
  }
  long long ans = 0LL;
  sort(changex, changex + n);
  sort(changey, changey + n);
  long long u = (changex[n / 2] + changey[n / 2]) / 2; 
  long long v = changex[n / 2] - u; 
  for (int i = 1; i <= n; i++) {
    ans += max(abs(u - x[i]), abs(v - y[i])); 
  }                
  cout << ans; 
  return 0; 
}