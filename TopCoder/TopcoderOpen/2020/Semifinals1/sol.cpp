#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1000000007;
const int MAX_V = 2007;
const int MAX_LENGTH = 22;
int final[MAX_V];
int dp[MAX_LENGTH][MAX_V][2][2];

int DFS(int v) {
  int tmp = v;
  int newv = 0;
  while (tmp > 0) {
    int r = tmp % 10;
    tmp /= 10;
    newv += r + 48;
  }
  if (final[newv] != -1) {
    return final[v] = final[newv];
  }
  else {
    if (newv == v) {
      final[v] = v;
      return v;
    }
    else {
      return final[v] = DFS(newv);
    }
  }
}

void init() {
  for (int i = 0; i < MAX_V; i++) {
    final[i] = -1;
  }
  for (int i = 1; i < MAX_V; i++) {
    if (final[i] == -1) {
      final[i] = DFS(i);
    }
  }
}

class ASCIISum {
  public:
  int total(long long n) {
    init();
    string N = "";
    while (n > 0) {
      int r = n % 10;
      n /= 10;
      N += (char) (r + '0');
    }
    reverse(N.begin(), N.end());
    int len = (int) N.size();
    dp[0][0][0][1] = 1;
    for (int i = 0; i < len; i++) {
      for (int sumDigit = 0; sumDigit <= 57 * 19; sumDigit++) {
        for (int isDiff0 = 0; isDiff0 <= 1; isDiff0++) {
          for (int status = 0; status <= 1; status++) {
            if (dp[i][sumDigit][isDiff0][status] == 0) {
              continue;
            }
            int curVal = dp[i][sumDigit][isDiff0][status];
            for (int digit = 0; digit <= 9; digit++) {
              if (status == 1 && digit > N[i] - '0') {
                continue;
              }
              int newSumDigit = sumDigit;
              int newIsDiff0 = isDiff0;
              if (isDiff0 != 0 || digit != 0) {
                newSumDigit += digit + 48;
                newIsDiff0 = 1;
              }
              int newStatus = status;
              if (status == 1) {
                if (digit < N[i] - '0') {
                  newStatus = 0;
                }
              }
              (dp[i + 1][newSumDigit][newIsDiff0][newStatus] += curVal) %= MOD;
            }
          }
        }
      }
    }
    long long res = 0LL;
    for (int sumDigit = 1; sumDigit <= 57 * 19; sumDigit++) {
      for (int status = 0; status <= 1; status++) {
        if (dp[len][sumDigit][1][status] == 0) {
          continue;
        }
        long long val = dp[len][sumDigit][1][status];
        (val *= final[sumDigit]) %= MOD;
        (res += val) %= MOD;
      }
    }
    return (int) res;
  }
};

ASCIISum A;

int main () {
  cout << A.total(10);
  return 0;
}