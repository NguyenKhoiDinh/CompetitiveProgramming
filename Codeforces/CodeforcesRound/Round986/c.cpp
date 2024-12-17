#include <bits/stdc++.h>

using namespace std;
int n, m, v;
int a[200005]; 
vector <int> suffix; 
long long prefixSum[200005]; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m >> v; 
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
      prefixSum[i] = prefixSum[i - 1] + a[i]; 
    }
    suffix.clear();
    suffix.push_back(n + 1); 
    long long sum = 0LL;
    for (int i = n; i >= 1; i--) {
      sum += a[i];
      if (sum >= v) {
        suffix.push_back(i);
        sum = 0;  
      } 
    }
    if (m >= (int) suffix.size()) {
      cout << -1 << endl;
      continue; 
    }
    long long ans = prefixSum[suffix[m] - 1]; 
    sum = 0LL;
    int numb = 0; 
    for (int i = 1; i <= n; i++) {
      if (numb <= m) {
        int rest = m - numb;
        if (rest < (int) suffix.size() && i <= suffix[rest]) {
          ans = max(ans, prefixSum[suffix[rest] - 1] - prefixSum[i]);   
        } 
      } 
      sum += a[i];
      if (sum >= v) {
        numb++; 
        sum = 0;
      }
      if (numb <= m) {
        int rest = m - numb;
        if (rest < (int) suffix.size() && i <= suffix[rest]) {
          ans = max(ans, prefixSum[suffix[rest] - 1] - prefixSum[i]); 
        }
      }  
    }  
    cout << ans << endl; 
  }
  return 0; 
}