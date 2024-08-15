#include <bits/stdc++.h>

using namespace std;
int a[200005], b[200005]; 
int n, k; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> b[i]; 
    }
    int lo = 1; 
    int hi = 1000000007;
    int lim = -1; 
    long long maxTotal = -1; 
    while (lo <= hi) {
      int mid = (lo + hi) / 2; 
      long long total = 0LL; 
      for (int i = 1; i <= n; i++) {
        if (a[i] < mid) {
          continue; 
        }  
        if (b[i] >= a[i]) {
          total++; 
          continue;   
        }
        total += 1 + (a[i] - mid) / b[i]; 
      }
      if (total <= k) {
        if (maxTotal == -1 || maxTotal <= total) {
          maxTotal = total;
          lim = mid; 
          hi = mid - 1; 
        } 
        else {
          lo = mid + 1; 
        }
      }
      else {
        lo = mid + 1; 
      }
    }
    k -= maxTotal;
    long long ans = 0LL;
    for (int i = 1; i <= n; i++) {
      if (a[i] < lim) {
        continue; 
      }
      if (b[i] >= a[i]) {
        ans += a[i]; 
        a[i] = 0; 
        continue; 
      }
      long long numb = (a[i] - lim) / b[i];
      ans += (numb + 1) * a[i]; 
      ans -= (long long) b[i] * numb * (numb + 1) / 2; 
      a[i] -= numb * b[i]; 
      int prev = a[i]; 
      a[i] -= b[i]; 
      a[i] = max(a[i], 0); 
    }
    priority_queue <pair <int, int> > pq;
    for (int i = 1; i <= n; i++) {
      pq.push(make_pair(a[i], b[i])); 
    } 
    while (k > 0) {
      pair <int, int> pqTop = pq.top(); 
      if (pqTop.first == 0) {
        break; 
      }
      ans += pqTop.first; 
      pq.pop(); 
      pqTop.first = max(0, pqTop.first - pqTop.second); 
      pq.push(pqTop); 
      k--;
    }
    cout << ans << endl; 
  }
  return 0; 
}