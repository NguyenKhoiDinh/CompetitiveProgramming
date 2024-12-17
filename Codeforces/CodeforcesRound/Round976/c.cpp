#include <bits/stdc++.h>

using namespace std;
long long b, c, d; 
int f[70][2]; 
pair <int, int> trace[70][2]; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> b >> c >> d; 
    for (int i = 0; i < 70; i++) {
      for (int rem = 0; rem <= 1; rem++) {
        f[i][rem] = 0; 
        trace[i][rem] = make_pair(-1, -1); 
      }
    }
    f[0][0] = 1; 
    for (int i = 0; i < 62; i++) {
      for (int rem = 0; rem <= 1; rem++) {
        if (f[i][rem] == 0) {
          continue; 
        }
        int dd = ((d & (1LL << (long long) i)) > 0); 
        int db = ((b & (1LL << (long long) i)) > 0); 
        int dc = ((c & (1LL << (long long) i)) > 0);
        for (int da = 0; da <= 1; da++) {
          int dac = (da & dc); 
          int digit = (dd + rem + dac) % 2;
          if (digit != (da | db)) {
            continue; 
          }
          int nextRem = (dd + rem + dac) / 2;
          f[i + 1][nextRem] = 1;
          trace[i + 1][nextRem] = make_pair(rem, da);    
        } 
      }
    }
    if (f[62][0] == 0) {
      cout << -1 << endl;
      continue; 
    }
    int i = 62;
    int rem = 0; 
    long long ans = 0LL; 
    while (i > 0) {
      int da = trace[i][rem].second;
      if (da == 1) {                                                                             
        ans += (1LL << (long long) (i - 1)); 
      } 
      rem = trace[i][rem].first; 
      i--; 
    }
    cout << ans << endl;
  }                                                       
  return 0; 
}