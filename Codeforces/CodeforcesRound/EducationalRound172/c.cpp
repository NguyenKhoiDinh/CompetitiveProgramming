#include <bits/stdc++.h>

using namespace std;
int n, k;
string s;
long long f[200005]; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> k;
    for (int i = 0; i <= n + 1; i++) {
      f[i] = 0; 
    }
    cin >> s;
    s = "." + s; 
    long long total = 0LL; 
    for (int i = n; i >= 1; i--) {
      f[i] = f[i + 1];
      if (s[i] == '1') {
        total += i - 1; 
        f[i]++; 
      }
      else {
        total -= i - 1; 
        f[i]--;
      }
    }
    int ans = n; 
    vector <long long> save; 
    for (int i = n; i > 1; i--) {
      if (f[i] > 0) {
        save.push_back(f[i]);
      }
      else {
        ans--;
        total -= f[i];
      }
    }
    sort(save.begin(), save.end()); 
    if (total >= k) {
      for (int i = 0; i < (int) save.size(); i++) {
        if (total - save[i] < k) {
          break; 
        }
        total -= save[i];
        ans--; 
      }
      cout << ans << endl;
    }
    else {
      cout << -1 << endl; 
    }
  }
  return 0; 
}