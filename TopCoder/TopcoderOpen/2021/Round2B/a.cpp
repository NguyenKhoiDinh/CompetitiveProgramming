#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 68;
unsigned long long dp[MAX_N][2][3];

string convertToString(unsigned long long x) {
  string res = "";
  while (x > 0) {
    int r = x % 10;
    x /= 10;
    res += (char) (r + '0');
  }
  reverse(res.begin(), res.end());
  return res;
}

unsigned long long dynamicProgramming(unsigned long long X) {
  memset(dp, 0, sizeof(dp));
  string s = convertToString(X);
  int len = (int) s.size();
  for (int x = 1; x <= 9; x++) {
    int status = 0;
    if (x == s[0] - '0') {
      status = 1;
    }
    else if (x > s[0] - '0') {
      status = 2;
    }
    dp[1][x % 2][status]++;
  }
  for (int i = 1; i < len; i++) {
    for (int type = 0; type <= 1; type++) {
      for (int status = 0; status <= 2; status++) {
        if (dp[i][type][status] == 0) {
          continue;
        }
        for (int d = (type == 0 ? 1 : 0); d <= 9; d += 2) {
          int nextStatus = status;
          if (status == 1) {
            if (d < s[i] - '0') {
              nextStatus = 0; 
            }
            else if (d > s[i] - '0') {
              nextStatus = 2;
            }
          }
          dp[i + 1][!type][nextStatus] += dp[i][type][status];
        }
      }
    }
  }
  unsigned long long ans = 0LL;
  for (int i = 1; i <= len; i++) {
    for (int type = 0; type <= 1; type++) {
      for (int status = 0; status <= (i == len ? 1 : 2); status++) {
        ans += dp[i][type][status];
      }
    }
  }
  return ans;
}

class AlternateOddEven {
  public: 
  long long kth(long long K) {
    long long res = 0LL;
    unsigned long long lo = 1;
    unsigned long long hi = 9223372036854775807LL;
    while (lo <= hi) {
      unsigned long long mid = (lo + hi) >> 1;
      unsigned long long value = dynamicProgramming(mid);
      if (value >= K) {
        res = mid;
        hi = mid - 1;
      }
      else {
        lo = mid + 1;
      }
    }
    return res;
  }
};

AlternateOddEven A;

int main () {
  cout << A.kth(15);
  return 0; 
}
