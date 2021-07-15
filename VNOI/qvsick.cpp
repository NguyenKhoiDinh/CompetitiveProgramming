#include <iostream> 
#include <string>
#include <cstring>
#include <algorithm>

using namespace std; 

const int MAX_SUM = 182;
const int MAX_LENGTH = 20;

long long dp[MAX_LENGTH][MAX_SUM][MAX_SUM][2][2];
long long L, R;

string convert(long long N) {
  if (N == 0) {
    return "0";
  }
  string ans = "";
  while (N > 0) {
    int r = N % 10;
    ans += (char) (r + '0');
    N /= 10;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

long long dynamicProgramming(int sum, const string &N) {
  memset(dp, 0, sizeof(dp));
  long long total = 0LL;
  int len = (int) N.size();
  dp[0][0][0][0][1] = 1LL;
  for (int i = 0; i < len; i++) {
    for (int digitProd = 0; digitProd <= sum; digitProd++) {
      for (int rem = 0; rem < sum; rem++) {
        for (int positive = 0; positive <= 1; positive++) {
          for (int status = 0; status <= 1; status++) {
            if (dp[i][digitProd][rem][positive][status] == 0) {
              continue;
            }
            long long cur = dp[i][digitProd][rem][positive][status];
            for (int dig = 0; dig <= 9; dig++) {
              int value = rem * 10 + dig;
              int div = value / sum;
              int r = value % sum;
              int nextPositive = positive;
              int nextDigitProd = digitProd;
              if (positive == 0) {
                if (dig > 0) {
                  nextPositive = 1;
                  nextDigitProd = div;
                  if (div > sum) {
                    continue;
                  }
                }
              }
              else {
                if (digitProd * div > sum) {
                  continue;
                }
                nextDigitProd *= div;
              }
              int nextStatus = status;
              if (status == 1) {
                if (dig < N[i] - '0') {
                  nextStatus = 0;
                }
              }
              dp[i + 1][nextDigitProd][r][nextPositive][nextStatus] += cur;
            }
          }
        }
      }
    }
  }
  total = dp[len][sum][0][1][1] + dp[len][sum][0][1][0];
  return total;
}

long long calc(long long X) {
  string N = convert(X);
  int len = (int) N.size();
  int maxSum = 9 * len;
  long long total = 0LL;
  for (int sum = 1; sum <= maxSum; sum++) {
    total += dynamicProgramming(sum, N);
  }
  return total;
}

int main () {
  cin >> L >> R;
  cout << calc(R) - calc(L - 1);
  return 0;
}