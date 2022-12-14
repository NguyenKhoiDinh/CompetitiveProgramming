#include <bits/stdc++.h> 

using namespace std;
int MAX_N = 75;
long long dp[MAX_N][MAX_N];
int k;

struct element {
  int u, v;
  string rela;
};
vector <element> save;
int n, k; 

int main () {
  freopen("input.txt", "r", stdin);
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    int u, v;
    string rela;
    cin >> u >> v >> rela;
    if (u > v) {
      swap(u, v);
      if (rela == ">") {
        rela = "<";
      }
      else if (rela == "<") {
        rela = ">";
      }
      else if (rela == "<=") {
        rela = ">=";
      }
      else if (rela == ">=") {
        rela = "<=";
      }
    }
    save.push_back((element) {u, v, rela});
  }
  return 0; 
}