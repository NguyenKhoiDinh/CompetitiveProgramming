#include <bits/stdc++.h>

using namespace std;
long long sum(const long long &l, const long long &r) {
  long long ret = 1LL * r * (r + 1) / 2;
  ret -= 1LL * l * (l - 1) / 2; 
  return ret; 
}
int calc(vector <int> &a) {
  set <int> S; 
  for (int i = 0; i < (int) a.size(); i++) {
    S.insert(a[i]); 
  }
  int mex = 0; 
  for (set <int>::iterator it = S.begin(); it != S.end(); it++) {
    int v = *it; 
    if (mex == v) {
      mex++; 
    }
    else {
      break; 
    }
  }
  S.insert(mex); 
  mex = 0; 
  for (set <int>::iterator it = S.begin(); it != S.end(); it++) {
    int v = *it; 
    if (mex == v) {
      mex++; 
    }
    else {
      break; 
    }
  }
  return mex; 
}
int n, m;
 
int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m;
    int maxValue = -1;
    for (int i = 1; i <= n; i++) {
      vector <int> a; 
      int cnt;
      cin >> cnt;
      for (int j = 0; j < cnt; j++) {
        int x;
        cin >> x; 
        a.push_back(x); 
      }
      maxValue = max(maxValue, calc(a)); 
    }
    long long ans = 1LL * maxValue * min(m + 1, (maxValue + 1));
    if (maxValue < m) {
      ans += sum(maxValue + 1, m); 
    }       
    cout << ans << endl; 
  }
  return 0; 
}