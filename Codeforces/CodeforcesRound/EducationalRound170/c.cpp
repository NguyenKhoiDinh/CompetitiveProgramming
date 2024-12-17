#include <bits/stdc++.h>

using namespace std;
int a[200005]; 
int d[200005];
int sum[200005];  

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    map <int, int> cnt;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      cnt[a[i]]++; 
    }
    vector <pair <int, int> > save; 
    for (map <int, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
      save.push_back(make_pair(it->first, it->second)); 
    }
    d[0] = 1; 
    sum[0] = save[0].second; 
    for (int i = 1; i < (int) save.size(); i++) {
      if (save[i].first == save[i - 1].first + 1) {
        if (d[i - 1] == k) {
          d[i] = k; 
          sum[i] = sum[i - 1] + save[i].second - save[i - k].second; 
        }
        else {
          d[i] = d[i - 1] + 1;
          sum[i] = sum[i - 1] + save[i].second;  
        }
      }
      else {
        d[i] = 1;
        sum[i] = save[i].second; 
      }
    }
    int ans = -1; 
    for (int i = 0; i < (int) save.size(); i++) {
      ans = max(ans, sum[i]); 
    }
    cout << ans << endl; 
  }
  return 0; 
}