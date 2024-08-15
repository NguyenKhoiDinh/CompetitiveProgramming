#include <bits/stdc++.h>

using namespace std;
int numTest; 
int n, m, k; 
pair <pair <int, int>, int> a[200005];
long long ans[200005]; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m >> k; 
    for (int i = 1; i <= k; i++) {
      cin >> a[i].first.first >> a[i].first.second; 
      a[i].second = i; 
    }
    sort(a + 1, a + k + 1);
    a[k + 1].first.second = m + 1;
    a[k + 1].first.first = n;  
    vector <int> suffix(k + 2);
    suffix[k + 1] = a[k + 1].first.second;
    for (int i = k; i >= 1; i--) {
      suffix[i] = min(a[i].first.second, suffix[i + 1]); 
    }
    long long total = (long long) a[1].first.first * (suffix[1] - 1);
    for (int i = 2; i <= k + 1; i++) {
      total += (long long) (a[i].first.first - a[i - 1].first.first) * (suffix[i] - 1); 
    }  
    for (int i = 1; i <= k; i++) {
      if (a[i].first.second < suffix[i + 1] && a[i - 1].first.first < a[i].first.first) {
        long long ret = total;
        ret -= (long long) (a[i].first.first - a[i - 1].first.first) * (suffix[i] - 1);
        ret -= (long long) (a[i + 1].first.first - a[i].first.first) * (suffix[i + 1] - 1);
        ret += (long long) (a[i + 1].first.first - a[i - 1].first.first) * (suffix[i + 1] - 1);
        ans[a[i].second] = ret - total;   
      }                                                          
      else {
        ans[a[i].second] = 0;
      }
    }
    cout << total << endl;
    for (int i = 1; i <= k; i++) {
      cout << ans[i] << ' ';
    }
    cout << endl;
  }
  return 0; 
}