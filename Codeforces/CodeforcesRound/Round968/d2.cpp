#include <bits/stdc++.h>

using namespace std;
vector <int> adj[200005]; 
long long f[200005];
int numb[200005];  
int dist[200005]; 
int n, m; 
long long sum(const long long &l, const long long &r) {
  if (l > r) {
    return 0LL; 
  }
  long long ret = 1LL * r * (r + 1) / 2;
  ret -= 1LL * l * (l - 1) / 2; 
  return ret; 
}

pair <int, int> calc(vector <int> &a) {
  pair <int, int> ret; 
  set <int> S; 
  for (int i = 0; i < (int) a.size(); i++) {
    S.insert(a[i]); 
  }
  int mex = 0; 
  for (set <int>::iterator it = S.begin(); it != S.end(); it++) {
    int v = *it; 
    if (mex == v) {
      mex++; 
    }
    else {
      break; 
    }
  }
  ret.first = mex; 
  S.insert(mex); 
  mex = 0; 
  for (set <int>::iterator it = S.begin(); it != S.end(); it++) {
    int v = *it; 
    if (mex == v) {
      mex++; 
    }
    else {
      break; 
    }
  }
  ret.second = mex;
  return ret; 
}
void dfs(int u, int value) {
  f[u] = value;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (f[v] == -1) {
      dist[v] = dist[u] + 1; 
      dfs(v, value); 
    }
  }
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  for (int i = 0; i <= 200000; i++) {
    f[i] = -1; 
  }
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m;
    int maxValue = -1;
    for (int i = 1; i <= n; i++) {
      vector <int> a; 
      int cnt;
      cin >> cnt;
      for (int j = 0; j < cnt; j++) {
        int x;
        cin >> x; 
        a.push_back(x); 
      }
      pair <int, int> tmp = calc(a);
      int mex = tmp.first;
      int finalMex = tmp.second;
      cout << mex << "     " << finalMex << endl;
      maxValue = max(maxValue, finalMex);       
      adj[finalMex].push_back(mex);
      numb[mex]++;    
    }
    for (int i = maxValue; i >= 0; i--) {
      if (f[i] == -1 && adj[i].empty() == false) {   
        dfs(i, i);   
      } 
    }
    for (int i = 0; i <= min(m, maxValue); i++) {
      if (f[i] < i) {
        f[i] = i;
      }
      if (dist[0] + numb[i] < n) {
        f[i] = max(f[i], f[0]);  
      }
    }
    for (int i = 0; i <= maxValue; i++) {
      cout << f[i] << "     "; 
    }
    cout << endl;
    long long ans = 0LL;
    for (int i = 0; i <= min(m, maxValue); i++) {
      ans += f[i];
    }
    if (maxValue < m) {
      ans += sum(maxValue + 1, m); 
    }
    cout << ans << endl; 
    for (int i = 0; i <= maxValue; i++) {
      adj[i].clear();
      f[i] = -1;
      dist[i] = 0;
      numb[i] = 0;      
    }
  }
  return 0; 
}