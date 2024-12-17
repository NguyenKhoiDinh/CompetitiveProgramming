#include <bits/stdc++.h> 

using namespace std;
int n;
int a[100005]; 
int cnt[1000005]; 
long long ans = 0LL;

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; 
  }
  for (int i = 1; i <= n; i++) {
    ans += cnt[a[i]];
    cnt[a[i]]++; 
  }
  cout << ans;
  return 0; 
}