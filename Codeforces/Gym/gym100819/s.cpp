#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
const int MAX_N = 2000005;

struct wave {
  int begin, funny, waiting;
};
vector <wave> save[MAX_N];
long long dp[MAX_N];
int n;

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int begin, funny, waiting;
    cin >> begin >> funny >> waiting;
    save[begin].push_back((wave) {begin, funny, waiting});
  }
  for (int i = 1; i < MAX_N; i++) {
    dp[i] = -1;
  }
  long long ans = -1;
  dp[1] = 0;
  for (int i = 1; i < MAX_N; i++) {
    ans = max(ans, dp[i]);
    dp[i + 1] = max(dp[i + 1], dp[i]);
    for (int j = 0; j < (int) save[i].size(); j++) {
      dp[i + save[i][j].waiting] = max(dp[i + save[i][j].waiting], dp[i] + save[i][j].funny);
    }
  }
  cout << ans;
  return 0;
}