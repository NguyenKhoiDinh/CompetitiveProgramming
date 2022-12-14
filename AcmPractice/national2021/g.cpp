#include <bits/stdc++.h> 

using namespace std;
int a[1005]; 
int n, k; 

int main () {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; 
    if (a[i] == 1) {
      a[i] = 0; 
    }
  }
  sort(a + 1, a + n + 1); 
  int sum = 0;
  for (int i = 1; i <= k; i++) {
    sum += a[i]; 
  }
  cout << sum << ' ';
  sum = 0;  
  for (int i = n; i >= n - k + 1; i--) {
    sum += a[i]; 
  }
  cout << sum;
  return 0; 
}