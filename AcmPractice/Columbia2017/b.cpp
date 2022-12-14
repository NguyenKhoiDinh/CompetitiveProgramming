#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 33; 
int a[MAX_N];
int n; 
long long nodes = 1LL; 
long long ans = 1LL; 

int main () {
  //freopen("input.txt", "r", stdin); 
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; 
  }
  sort(a + 1, a + n + 1); 
  for (int i = n; i >= 1; i--) {
    nodes *= (long long) a[i]; 
    ans += nodes; 
  }
  cout << ans;
  return 0; 
}