#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 100005;
int numTest;
struct node {
  int cnt;
  node *child[26];
};
int n, K;
string s[MAX_N];
int ans = 0;
int dp[MAX_N][26];

node *createNode() {
  node *ret = new node();
  ret->cnt = 0;
  for (int c = 0; c < 26; c++) {
    ret->child[c] = NULL;
  }
  return ret;
}

void add(node *root, string &s) {
  node *p = root;
  for (int i = 0; i < (int) s.size(); i++) {
    int c = s[i] - 'A';
    if (p->child[c] == NULL) {
      p->child[c] = createNode();
    }
    p = p->child[c];
    p->cnt++;
  }
}

void dfs(node *root, int currentChar, int len) {
  node *p = root;
  if (len > 0) {
    dp[len][currentChar] = p->cnt;
  }
  for (int c = 0; c < 26; c++) {
    if (p->child[c] == NULL) {
      continue;
    }
    dfs(p->child[c], c, len + 1);
    dp[len][currentChar] -= p->child[c]->cnt / K * K;
  }
  ans += len * (dp[len][currentChar] / K);
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n >> K;
    node *root = createNode();
    for (int i = 1; i <= n; i++) {
      string s;
      cin >> s;
      add(root, s);
    }
    ans = 0;
    dfs(root, '.', 0);
    cout << ans << endl;
  }
  return 0;
}