#include <bits/stdc++.h>

using namespace std;
map <int, int> fx, fy; 
int n; 
pair <int, int> a[150005]; 
vector <int> savex, savey;
long long suffixSum[150005];
vector <int> save[150005];
long long prefix[150005];   

int main () {
  cin >> n;
  bool check0 = true; 
  bool checkEqual = true; 
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
    if (a[i].second > 0) {
      check0 = false; 
    }
    if (a[i].first != a[i].second) {
      checkEqual = false; 
    }
    savex.push_back(a[i].first);
    savey.push_back(a[i].second);  
  }
  sort(a + 1, a + n + 1); 
  if (n <= 3000) {
    save[1].push_back(a[1].second); 
    for (int i = 2; i <= n; i++) {
      save[i] = save[i - 1]; 
      save[i].push_back(a[i].second); 
      sort(save[i].begin(), save[i].end()); 
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < (int) save[i].size(); j++) {
        prefix[i] = max(prefix[i], (long long) save[i][j] * (i - j)); 
      }
    }
    long long ans = (long long) n * a[1].first;
    for (int i = 1; i <= n; i++) {
      long long sum = prefix[i]; 
      sum += (long long) a[i + 1].first * (n - i);
      ans = max(ans, sum);  
    }                                     
    cout << ans; 
  }
  if (check0 == true) {
    long long ans = 0LL; 
    for (int i = 1; i <= n; i++) {
      ans = max(ans, (long long) a[i].first * (n - i + 1));   
    }
    cout << ans;
  }
  if (checkEqual == true) {
    long long ans = 0LL; 
    for (int i = 1; i <= n; i++) {
      long long sum = (long long) a[i].first * (n - i + 1);
      int lo = 1; 
      int hi = i - 1;
      long long other = max((long long) a[lo].first * (i - lo), (long long) a[hi].first * (i - hi));  
      while (lo <= hi) {
        int u = (2 * lo + hi) / 3; 
        int v = (lo + 2 * hi) / 3;
        long long fu = (long long) a[u].first * (i - u);
        long long fv = (long long) a[v].first * (i - v);
        other = max(other, max(fu, fv));
        if (fu < fv) {
          lo = u + 1; 
        }  
        else {
          hi = v - 1; 
        }
      }
      ans = max(ans, sum + other); 
    }
    cout << ans; 
  }
  return 0; 
}