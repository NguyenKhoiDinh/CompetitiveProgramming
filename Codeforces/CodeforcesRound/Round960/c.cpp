#include <bits/stdc++.h>

using namespace std;
int numTest; 
int a[200005]; 
int n;
int cnt[200005]; 

int main () {
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    long long ans = 0LL; 
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      cnt[a[i]] = 0;
      ans += a[i];
    }    
    int maxi = 0;
    vector <int> b; 
    for (int i = 1; i <= n; i++) {
      cnt[a[i]]++; 
      if (cnt[a[i]] > 1) {
        maxi = max(maxi, a[i]); 
      }
      b.push_back(maxi); 
    }
    for (int i = 0; i < n; i++) {
      ans += b[i]; 
    }
    vector <int> c; 
    for (int i = 1; i <= n; i++) {
      cnt[i] = 0; 
    }
    maxi = 0; 
    for (int i = 0; i < n; i++) {
      cnt[b[i]]++; 
      if (cnt[b[i]] > 1) {
        maxi = max(maxi, b[i]); 
      }
      c.push_back(maxi); 
    }
    long long sum = 0LL;
    for (int i = 0; i < n; i++) {
      sum += c[i];
      ans += sum; 
    }
    cout << ans << endl;
  }
  return 0; 
}