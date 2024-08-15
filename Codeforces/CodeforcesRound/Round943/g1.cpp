#include <bits/stdc++.h>

using namespace std;
int numTest; 
string s; 
long long power[200005]; 
bool compare(int l1, int r1, int l2, int r2, const vector <long long> &hash) {
  long long hash1 = hash[r1]; 
  long long hash2 = hash[r2] - hash[l2 - 1]; 
  if (hash1 * power[l2 - l1] == hash2) {
    return true; 
  }
  return false; 
}
int main () {
  power[0] = 1LL; 
  for (int i = 1; i <= 200000; i++) {
    power[i] = power[i - 1] * 191LL; 
  }
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, l, r;
    cin >> n >> l >> r;
    cin >> s;
    vector <long long> prefixHash(n, 0LL);  
    long long sumHash = 0LL; 
    for (int i = 0; i < n; i++) {
      sumHash += power[i] * s[i];   
      prefixHash[i] = sumHash; 
    }
    int lo = 0, hi = n - 1;
    int ans = -1; 
    while (lo <= hi) {
      int mid = (lo + hi) / 2;  
      int p = mid + 1; 
      int numb = 1; 
      while (p < n) {
        if (p + mid < n && compare(0, mid, p, p + mid, prefixHash) == true) {
          numb++;
          p += mid + 1;  
        }
        else {
          p++; 
        }
      }
      if (numb >= l) {
        ans = mid; 
        lo = mid + 1; 
      }
      else {
        hi = mid - 1; 
      }
    }
    cout << ans + 1 << endl; 
  }
  return 0; 
}