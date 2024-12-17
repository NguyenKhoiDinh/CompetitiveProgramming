#include <bits/stdc++.h>

using namespace std;
int n, numQueries; 
long long a[300005], sumb[300005], suma[300005], sum2a[300005], sum3a[300005]; 
vector <pair <int, int> > seg; 
long long b[300005]; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> numQueries; 
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      suma[i] = suma[i - 1] + a[i];
      sum2a[i] = sum2a[i - 1] + suma[i];
      sum3a[i] = sum3a[i - 1] + 1LL * a[i] * (n - i + 1);   
    }
    for (int i = 1; i <= n; i++) {
      b[1] += 1LL * a[i] * (n - i + 1); 
    }
    sumb[1] = b[1]; 
    seg.clear();                         
    int l = 1, r = n; 
    seg.push_back(make_pair(l, r)); 
    for (int i = 2; i <= n; i++) {
      b[i] = b[i - 1] - 1LL * (n - i + 2) * a[i - 1];
      sumb[i] = sumb[i - 1] + b[i];
      l = r + 1;
      r += n - i + 1;
      seg.push_back(make_pair(l, r));   
    }
    for (int query = 1; query <= numQueries; query++) {
      int l, r;
      cin >> l >> r; 
      int posl = -1, posr = -1;
      int lo = 0, hi = n - 1; 
      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (seg[mid].second >= l) {
          posl = mid; 
          hi = mid - 1; 
        }   
        else {
          lo = mid + 1; 
        }
      }
      lo = 0, hi = n - 1; 
      while (lo <= hi) {
        int mid = (lo + hi) / 2; 
        if (seg[mid].first <= r) {
          posr = mid;
          lo = mid + 1; 
        }
        else {
          hi = mid - 1; 
        }
      }
      posl++;
      posr++; 
      long long ans = 0LL; 
      if (posl + 1 <= posr - 1) {
        ans = sumb[posr - 1] - sumb[posl]; 
      }

    }
  }
  return 0; 
}

    
