#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
const int MAX_N = 3005;
int dp[MAX_N][MAX_N];
string s1, s2;
int len1, len2;

int main () {
  cin >> s1 >> s2;
  len1 = (int) s1.size();
  len2 = (int) s2.size();
  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
      }
    }
  }
  vector <char> res;
  int i = len1;
  int j = len2;
  while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1]) {
      res.push_back(s1[i - 1]);
      i--;
      j--;
    }
    else if (dp[i][j] == dp[i - 1][j]) {
      i--;
    }
    else {
      j--;
    }
  }
  reverse(res.begin(), res.end());
  for (int i = 0; i < (int) res.size(); i++) {
    cout << res[i];
  }
  return 0;
}