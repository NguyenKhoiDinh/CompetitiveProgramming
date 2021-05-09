#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 30005; 
int a[MAX_N];
int n; 
int numTest; 
pair <int, int> b[MAX_N];

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    a[0] = 0; 
    a[n + 1] = 0;
    stack <int> st;
    st.push(0);
    for (int i = 1; i <= n; i++) {
      while (a[st.top()] >= a[i]) {
        st.pop();
      }
      b[i].first = st.top();
      st.push(i);
    }
    while (!st.empty()) {
      st.pop();
    }
    st.push(n + 1);
    for (int i = n; i >= 1; i--) {
      while (a[st.top()] >= a[i]) {
        st.pop();
      }
      b[i].second = st.top();
      st.push(i);
    }
    int position = -1; 
    int ans = -1; 
    for (int i = 1; i <= n; i++) {
      if (ans < a[i] * (b[i].second - 1 - b[i].first)) {
        ans = a[i] * (b[i].second - 1 - b[i].first);
        position = i;
      }
    }
    cout << ans << ' ' << b[position].first + 1 << ' ' << b[position].second - 1 << endl;
  } 
  return 0; 
}