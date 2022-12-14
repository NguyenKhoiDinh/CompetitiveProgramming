#include <bits/stdc++.h> 

using namespace std;
struct element {
  int l;
  string in, out;  
};
const int MOD = 1000000007; 
int dp[2][305][305][2][2][2][2][2]; 
int n, L; 
vector <element> a; 

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output2.txt", "w", stdout);
  cin >> n >> L;
  int res = 0; 
  for (int i = 1; i <= n; i++) {
    int len;
    string in, out; 
    cin >> len >> in >> out; 
    if (in == "none" && out == "none") {
      if (len == L) {
        res++; 
      }
      continue; 
    }
    if (out == "in") {
      out = "out"; 
    }
    else if (out == "out") {
      out = "in"; 
    }
    a.push_back((element) {len, in, out}); 
  } 
  n = (int) a.size(); 
  dp[0][0][150][0][0][0][0][0] = 1; 
  for (int i = 0; i < n; i++) {
    int cur = i & 1; 
    int nxt = !cur; 
    memset(dp[nxt], 0, sizeof(dp[nxt])); 
    for (int len = 0; len <= L; len++) {
      for (int diff = 0; diff <= 300; diff++) {
        for (int haveIn = 0; haveIn <= 1; haveIn++) {
          for (int haveOut = 0; haveOut <= 1; haveOut++) {
            for (int haveInOut = 0; haveInOut <= 1; haveInOut++) {
              for (int noneIn = 0; noneIn <= 1; noneIn++) {
                for (int noneOut = 0; noneOut <= 1; noneOut++) {
                  if (dp[cur][len][diff][haveIn][haveOut][haveInOut][noneIn][noneOut] == 0) {
                    continue; 
                  }
                  int curValue = dp[cur][len][diff][haveIn][haveOut][haveInOut][noneIn][noneOut]; 
                  (dp[nxt][len][diff][haveIn][haveOut][haveInOut][noneIn][noneOut] += curValue) %= MOD;
                  if (len + a[i].l > L) {
                    continue; 
                  }
                  if (noneIn == 1 && a[i].in == "none") {
                    continue; 
                  }
                  if (noneOut == 1 && a[i].out == "none") {
                    continue; 
                  }
                  int newDiff = diff; 
                  if (a[i].in == "in") {
                    newDiff++; 
                  }
                  if (a[i].out == "in") {
                    newDiff--; 
                  }
                  if (newDiff < 0 || newDiff > 300) {
                    continue; 
                  }
                  int newHaveIn = haveIn; 
                  if (a[i].in == "in" || a[i].out == "in") {
                    newHaveIn = 1; 
                  }
                  int newHaveOut = haveOut; 
                  if (a[i].in == "out" || a[i].out == "out") {
                    newHaveOut = 1; 
                  }
                  int newHaveInOut = haveInOut; 
                  if ((a[i].in == "in" && a[i].out == "out") || (a[i].in == "out" && a[i].out == "in")) {
                    newHaveInOut = 1; 
                  }
                  int newNoneIn = noneIn; 
                  if (a[i].in == "none") {
                    newNoneIn = 1; 
                  }
                  int newNoneOut = noneOut; 
                  if (a[i].out == "none") {
                    newNoneOut = 1; 
                  }
                  (dp[nxt][len + a[i].l][newDiff][newHaveIn][newHaveOut][newHaveInOut][newNoneIn][newNoneOut] += curValue) %= MOD; 
                }
              }
            }
          }
        }  
      }
    }
  }
  (res += dp[n & 1][L][150][0][0][0][1][1]) %= MOD;
  (res += dp[n & 1][L][150][1][0][0][1][1]) %= MOD;
  (res += dp[n & 1][L][150][0][1][0][1][1]) %= MOD;
  (res += dp[n & 1][L][150][1][1][1][1][1]) %= MOD; 
  cout << res; 
  return 0; 
}
