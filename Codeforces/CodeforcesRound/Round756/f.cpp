#include <bits/stdc++.h> 

using namespace std;
int numTest;
int a[200005];
long long sum[200005]; 
int rmq[200005][25]; 
int n;
long long s; 

int minQuery(int l, int r) {
  int k = (int) log2(r - l + 1); 
  if (sum[rmq[l][k]] <= sum[rmq[r - (1 << k) + 1][k]]) {
    return rmq[l][k];
  }
  else {
    return rmq[r - (1 << k) + 1][k];
  }
}

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum[i] = sum[i - 1] + a[i]; 
    } 
    for (int i = 1; i <= n; i++) {
      rmq[i][0] = i; 
    }
    for (int j = 1; (1 << j) <= n; j++) {
      for (int i = 1; i + (1 << j) - 1 <= n; i++) {
        if (sum[rmq[i][j - 1]] < sum[rmq[i + (1 << (j - 1))][j - 1]]) {
          rmq[i][j] = rmq[i][j - 1];
        }  
        else {
          rmq[i][j] = rmq[i + (1 << (j - 1))][j - 1]; 
        }
      }
    }
    int start = -1; 
    int length = -1; 
    int lo = 1; 
    int hi = n; 
    while (lo <= hi) {
      int mid = (lo + hi) >> 1; 
      long long S = s; 
      bool found = false; 
      for (int i = 1; i + mid - 1 <= n; i++) {
        int l = i;
        int r = i + mid - 1;
        int pos = minQuery(l, r);
        if (S >= -sum[pos]) {
          found = true;
          start = i;
          break; 
        }  
        S -= a[i];
      }
      if (found == true) {
        length = mid; 
        lo = mid + 1; 
      }
      else {
        hi = mid - 1; 
      }
    }
    if (start == -1) {
      cout << -1 << endl; 
    }
    else {
      cout << start << ' ' << start + length - 1 << endl; 
    }
  }
  return 0; 
}