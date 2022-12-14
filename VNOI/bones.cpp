#include <bits/stdc++.h>

using namespace std;
int cnt[100]; 

int main () {
  int S1, S2, S3; 
  cin >> S1 >> S2 >> S3; 
  for (int i = 1; i <= S1; i++) {
    for (int j = 1; j <= S2; j++) {
      for (int k = 1; k <= S3; k++) {
        cnt[i + j + k]++;
      }
    }
  }
  int maxi = -1; 
  int res = -1; 
  for (int i = 1; i <= S1 + S2 + S3; i++) {
    if (maxi < cnt[i]) {
      maxi = cnt[i];
      res = i;
    }
  }
  cout << res;
  return 0; 
}