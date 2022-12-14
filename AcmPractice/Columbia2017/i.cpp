#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 100005;
const int MAX_K = 22; 
int dp[2][MAX_K][MAX_K][3][3];
string a[MAX_N];
vector <int> type[MAX_N];
int n, k;

bool isPalindrome(string s) {
  string revs = s;
  reverse(revs.begin(), revs.end());
  return (s == revs);
}

bool isLucky(string s) {
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] != '4' && s[i] != '7') {
      return false; 
    }
  }
  return true;
}

int main () {
  //freopen("input.txt", "r", stdin);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (isPalindrome(a[i]) == true) {
      type[i].push_back(0); 
    }
    if (isLucky(a[i]) == true) {
      type[i].push_back(1);
    }
    if (type[i].empty() == true) {
      cout << "No";
      return 0; 
    }
  }
  dp[0][0][0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    int cur = i & 1;
    int nxt = !cur;
    memset(dp[nxt], 0, sizeof(dp[nxt]));
    for (int d1 = 0; d1 <= k; d1++) {
      for (int d2 = 0; d2 <= k; d2++) {
        for (int friend1 = 0; friend1 <= 2; friend1++) {
          for (int friend2 = 0; friend2 <= 2; friend2++) {
            if (dp[cur][d1][d2][friend1][friend2] == 0) {
              continue; 
            }
            if (type[i + 1][0] == 0) {
              if (friend1 == 0) {
                dp[nxt][0][friend2 == 0 ? 0 : min(d2 + 1, k)][1][friend2] = 1;
              }
              if (d1 < k) {
                dp[nxt][0][friend2 == 0 ? 0 : min(d2 + 1, k)][friend1 == 0 ? 1 : 2][friend2] = 1;
              }
              if (friend1 == 2 && d1 == k) {
                dp[nxt][0][friend2 == 0 ? 0 : min(d2 + 1, k)][1][friend2] = 1;
              }
            }
            if (type[i + 1][0] == 1 || (int) type[i + 1].size() == 2) {
              if (friend2 == 0) {
                dp[nxt][friend1 == 0 ? 0 : min(d1 + 1, k)][0][friend1][1] = 1;
              }
              if (d2 < k) {
                dp[nxt][friend1 == 0 ? 0 : min(d1 + 1, k)][0][friend1][friend2 == 0 ? 1 : 2] = 1;
              }
              if (friend2 == 2 && d2 == k) {
                dp[nxt][friend1 == 0 ? 0 : min(d1 + 1, k)][0][friend1][1] = 1;
              }
            }
          }
        }
      }
    }
  }
  for (int d1 = 0; d1 <= k; d1++) {
    for (int d2 = 0; d2 <= k; d2++) {
      if (dp[n & 1][d1][d2][2][2] == 1) {
        cout << "Yes"; 
        return 0; 
      }
    }
  }
  cout << "No";
  return 0; 
}