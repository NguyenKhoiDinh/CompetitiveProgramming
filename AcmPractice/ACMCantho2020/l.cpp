#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;
const long long inf = 1000000000000007;
const int MAX_N = 17;
string N, A, B, C;
long long ans = inf;
long long dp[MAX_N][MAX_N][MAX_N][MAX_N][3][3][3];
long long POW10[MAX_N];

void updateMin(long long &a, long long b) {
  a = min(a, b);
}

bool check(const string &s, int dig, int fill, int increase) {
  int len = (int) s.size();
  if (fill > 0 && fill < len && dig != s[fill] - '0') {
    return false;
  }
  if (increase == 0) {
    if (fill > 0 && fill < len && dig == s[fill] - '0') {
      return false;
    }
  }
  else {
    if (fill == len) {
      return false;
    }
    if (fill < len && dig != s[fill] - '0') {
      return false;
    }
  }
  return true;
}

void DynamicProgramming(const string &A, const string &B, const string &C) {
  int numDigit = (int) N.size();
  int lenA = (int) A.size();
  int lenB = (int) B.size();
  int lenC = (int) C.size();
  for (int i = 0; i <= numDigit; i++) {
    for (int fillA = 0; fillA <= lenA; fillA++) {
      for (int fillB = 0; fillB <= lenB; fillB++) {
        for (int fillC = 0; fillC <= lenC; fillC++) {
          for (int remain = 0; remain <= 2; remain++) {
            for (int status1 = 0; status1 <= 2; status1++) {
              for (int status2 = 0; status2 <= 2; status2++) {
                dp[i][fillA][fillB][fillC][remain][status1][status2] = inf;
              }
            }
          }
        }
      }
    }
  }
  dp[0][0][0][0][0][1][1] = 0;
  for (int i = 0; i < numDigit; i++) {
    for (int fillA = 0; fillA <= lenA; fillA++) {
      for (int fillB = 0; fillB <= lenB; fillB++) {
        for (int fillC = 0; fillC <= lenC; fillC++) {
          for (int remain = 0; remain <= 2; remain++) {
            for (int status1 = 0; status1 <= 2; status1++) {
              for (int status2 = 0; status2 <= 2; status2++) {
                if (dp[i][fillA][fillB][fillC][remain][status1][status2] == inf) {
                  continue;
                }
                long long curVal = dp[i][fillA][fillB][fillC][remain][status1][status2];
                for (int digA = 0; digA <= (i == numDigit - 1 ? (int) N.back() - '0' - remain : 9); digA++) {
                  for (int digB = 0; digB <= (i == numDigit - 1 ? (int) N.back() - '0' - remain - digA : 9); digB++) {
                    for (int increaseA = 0; increaseA <= 1; increaseA++) {
                      for (int increaseB = 0; increaseB <= 1; increaseB++) {
                        for (int increaseC = 0; increaseC <= 1; increaseC++) {
                          int digC = ((int) N[i] - '0' - remain - digA - digB + 30) % 10;
                          if (check(A, digA, fillA, increaseA) == false) {
                            continue;
                          }
                          if (check(B, digB, fillB, increaseB) == false) {
                            continue;
                          }
                          if (check(C, digC, fillC, increaseC) == false) {
                            continue;
                          }
                          int nextFillA = fillA + increaseA;
                          int nextFillB = fillB + increaseB;
                          int nextFillC = fillC + increaseC;
                          int nextStatus1 = status1;
                          int nextStatus2 = status2;
                          if (digB > digA) {
                            nextStatus1 = 2;
                          }
                          else if (digB < digA) {
                            nextStatus1 = 0;
                          }
                          if (digC > digB) {
                            nextStatus2 = 2;
                          }
                          else if (digC < digB) {
                            nextStatus2 = 0;
                          }
                          int total = digA + digB + digC + remain;
                          int nextRemain = total / 10;
                          updateMin(dp[i + 1][nextFillA][nextFillB][nextFillC][nextRemain][nextStatus1][nextStatus2], curVal + POW10[i] * (digC - digA));
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  for (int status1 = 1; status1 <= 2; status1++) {
    for (int status2 = 1; status2 <= 2; status2++) {
      if (ans > dp[numDigit][lenA][lenB][lenC][0][status1][status2]) {
        ans = dp[numDigit][lenA][lenB][lenC][0][status1][status2];
      }
    }
  }
}

int main () {
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
  POW10[0] = 1;
  for (int i = 1; i <= 16; i++) {
    POW10[i] = POW10[i - 1] * 10LL;
  }
  cin >> N >> A >> B >> C;
  reverse(N.begin(), N.end());
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());
  reverse(C.begin(), C.end());
  DynamicProgramming(A, B, C);
  DynamicProgramming(A, C, B);
  DynamicProgramming(B, A, C);
  DynamicProgramming(B, C, A);
  DynamicProgramming(C, A, B);
  DynamicProgramming(C, B, A);
  cout << (ans == inf ? -1 : ans);
  return 0;
}