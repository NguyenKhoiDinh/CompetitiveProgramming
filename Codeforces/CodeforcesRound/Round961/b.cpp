#include <bits/stdc++.h>

using namespace std;
int n;
long long m; 
long long a[200005]; 
long long c[200005]; 

int main () {
  int numTest;
  cin >> numTest;
  bool isEasy = false; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
      c[i] = 0; 
    }
    vector <pair <long long, long long> > v; 
    map <long long, long long> cnt;     
    if (isEasy == true) {
      for (int i = 1; i <= n; i++) {
        cnt[a[i]]++; 
      }
      for (map <long long, long long>::iterator it = cnt.begin(); it != cnt.end(); it++) {
        v.push_back(make_pair(it->first, it->second)); 
      }
      sort(a + 1, a + n + 1); 
      int l = 1; 
      long long sum = 0LL; 
      long long ans = 0LL; 
      for (int i = 1; i <= n; i++) {
        sum += a[i]; 
        while (l <= i && (sum > m || a[l] < a[i] - 1)) {
          sum -= a[l]; 
          l++; 
        }
        ans = max(ans, sum); 
      }
      cout << ans << endl;
      continue; 
    }
    else {
      for (int i = 1; i <= n; i++) {
        cin >> c[i]; 
        v.push_back(make_pair(a[i], c[i])); 
      }
    }
    sort(v.begin(), v.end());
    long long ans = 0LL; 
    for (int i = 0; i < (int) v.size(); i++) {
      long long numb = 0LL; 
      numb += min((long long) v[i].second, m / v[i].first);
      long long total = 0LL;
      total += numb * v[i].first;   
      ans = max(ans, total); 
    }
    for (int i = 1; i < (int) v.size(); i++) {
      if (v[i - 1].first == v[i].first - 1) {
        long long x = min(v[i - 1].second, m / v[i - 1].first); 
        long long y = min(v[i].second, (m - x * v[i - 1].first) / v[i].first);
        long long z = min(x, min(v[i].second - y, m - x * v[i - 1].first - y * v[i].first));
        x -= z;
        y += z;
        ans = max(ans, x * v[i - 1].first + y * v[i].first);  
      }
    } 
    cout << ans << endl;
  }
  return 0; 
}