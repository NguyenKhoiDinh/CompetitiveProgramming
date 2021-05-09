#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 1005; 
int a[MAX_N][MAX_N];
int sumCol[MAX_N][MAX_N];
int n, m;
int value[MAX_N];
pair <int, int> b[MAX_N];
int ans = 0; 

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 1) {
        sumCol[i][j] = sumCol[i - 1][j] + 1; 
      }
    }
    for (int j = 1; j <= m; j++) {
      value[j] = sumCol[i][j];
    }
    value[0] = value[m + 1] = -1;
    for (int j = 1; j <= m; j++) {
      b[j].first = -1; 
      b[j].second = -1; 
    }
    stack <int> st;
    st.push(0);
    for (int j = 1; j <= m; j++) {
      while (value[st.top()] >= value[j]) {
        st.pop();
      }
      b[j].first = st.top();
      st.push(j);
    }
    while (!st.empty()) {
      st.pop();
    }
    st.push(m + 1);
    for (int j = m; j >= 1; j--) {
      while (value[st.top()] >= value[j]) {
        st.pop();
      }
      b[j].second = st.top();
      st.push(j);
    }
    for (int j = 1; j <= m; j++) {
      ans = max(ans, value[j] * (b[j].second - 1 - b[j].first));
    }
  }
  cout << ans;
  return 0; 
}