#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 30005;
const long long inf = 10000000000007LL;  
int n; 
long long a[MAX_N];
long long F[MAX_N];

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];   
  }
  F[1] = 1;  
  int maxLength = 1; 
  for (int i = 1; i <= n; i++) {
    if (a[F[maxLength]] < a[i]) {
      maxLength++; 
      F[maxLength] = i; 
    }
    else {
      int l = 0; 
      int r = maxLength;
      int len = 0; 
      while (l <= r) {
        int mid = (l + r) >> 1; 
        if (a[F[mid]] < a[i]) {
          len = mid; 
          l = mid + 1; 
        }
        else {
          r = mid - 1; 
        }
      }
      len++; 
      if (a[F[len]] > a[i]) {
        F[len] = i;
      }
    }
  }
  cout << maxLength;
  return 0; 
}