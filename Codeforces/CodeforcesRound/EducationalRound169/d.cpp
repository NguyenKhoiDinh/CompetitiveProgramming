#include <bits/stdc++.h>

using namespace std;
string s[200005]; 
int n, numQueries; 
vector <int> v[26][26];
bool ok[200005][26]; 
int solve(int c1, int c2, int x, int y) {
  if (c1 > c2) {
    swap(c1, c2); 
  }
  int ret = 1000000007; 
  vector <int> &save = v[c1][c2]; 
  vector <int>::iterator big, small; 
  big = upper_bound(save.begin(), save.end(), x);
  if (big != save.end()) {
    int vBig = *big; 
    if (vBig < y) {
      return y - x; 
    }
    ret = min(ret, vBig - y + vBig - x); 
  }
  small = lower_bound(save.begin(), save.end(), x);
  if (small != save.begin()) {
    small--;
    int vSmall = *small;
    if (vSmall > y) {
      return x - y;   
    }
    else {
      ret = min(ret, y - vSmall + x - vSmall); 
    }
  }  
  return ret; 
}

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> numQueries;
    for (int i = 1; i <= n; i++) {
      for (int ch = 0; ch < 26; ch++) {
        ok[i][ch] = false; 
      }
    }      
    for (int ch1 = 0; ch1 < 26; ch1++) {
      for (int ch2 = 0; ch2 < 26; ch2++) {
        v[ch1][ch2].clear(); 
      }
    }
    for (int i = 1; i <= n; i++) {
      cin >> s[i];
      ok[i][s[i][0] - 'A'] = true;
      ok[i][s[i][1] - 'A'] = true;
      v[s[i][0] - 'A'][s[i][1] - 'A'].push_back(i);   
    }
    for (int ch1 = 0; ch1 < 26; ch1++) {
      for (int ch2 = 0; ch2 < 26; ch2++) {
        sort(v[ch1][ch2].begin(), v[ch1][ch2].end()); 
      }
    }
    for (int query = 1; query <= numQueries; query++) {
      int u, v;
      cin >> u >> v; 
      if (ok[v][s[u][0] - 'A'] == true || ok[v][s[u][1] - 'A'] == true) {
        cout << abs(u - v); 
      }
      else {
        int ans = solve(s[u][0] - 'A', s[v][0] - 'A', u, v);
        ans = min(ans, solve(s[u][0] - 'A', s[v][1] - 'A', u, v));
        ans = min(ans, solve(s[u][1] - 'A', s[v][0] - 'A', u, v));
        ans = min(ans, solve(s[u][1] - 'A', s[v][1] - 'A', u, v));

        ans = min(ans, solve(s[v][0] - 'A', s[u][0] - 'A', v, u));
        ans = min(ans, solve(s[v][0] - 'A', s[u][1] - 'A', v, u));
        ans = min(ans, solve(s[v][1] - 'A', s[u][0] - 'A', v, u));
        ans = min(ans, solve(s[v][1] - 'A', s[u][1] - 'A', v, u));
        cout << (ans == 1000000007 ? -1 : ans); 
      }
      cout << endl;
    }             
  }
  return 0; 
}