#include <bits/stdc++.h>
using namespace std;
int n, k, d; 
int a[100005]; 
int l[100005], r[100005]; 

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output2.txt", "w", stdout);
  cin >> n >> k >> d;
  for (int i = 1; i <= k; i++) {
    cin >> l[i] >> r[i]; 
  }
  for (int i = 1; i <= n; i++) {
    a[i] = i;
  }
  for (int i = 1; i <= d; i++) {
    for (int j = 1; j <= k; j++) {
      reverse(a + l[j], a + r[j] + 1); 
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  return 0; 
}