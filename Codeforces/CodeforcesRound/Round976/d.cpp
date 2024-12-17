#include <bits/stdc++.h>

using namespace std;       
int root[200005]; 
vector <pair <int, int> > listSegments[11][11]; 
int n, m;
int findRoot(int u) {
  return root[u] = (u == root[u] ? u : findRoot(root[u])); 
}
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL); 
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      root[i] = i; 
    }
    for (int j = 1; j <= 10; j++) {
      for (int r = 0; r < j; r++) {
        listSegments[j][r].clear(); 
      }
    }
    for (int i = 1; i <= m; i++) {
      int a, d, k; 
      cin >> a >> d >> k; 
      int left = a; 
      int right = a + d * k;
      listSegments[d][a % d].push_back(make_pair(left / d, right / d));              
    }                    
    int ans = n; 
    for (int d = 1; d <= 10; d++) {
      for (int r = 0; r < d; r++) {
        if (listSegments[d][r].empty() == true) {
          continue; 
        }
        vector <pair <int, int> > &v = listSegments[d][r]; 
        sort(v.begin(), v.end());
        vector <pair <int, int> > save;
        save.push_back(v[0]); 
        for (int i = 1; i < (int) v.size(); i++) {
          if (v[i].first > save.back().second) {
            save.push_back(v[i]); 
          }
          else {
            save.back().second = max(save.back().second, v[i].second); 
          }
        }
        for (int i = 0; i < (int) save.size(); i++) {
          for (int j = save[i].first; j <= save[i].second; j++) {
            int rootu = findRoot(save[i].first * d + r); 
            int rootv = findRoot(j * d + r); 
            if (rootu != rootv) {
              ans--; 
              root[rootu] = rootv; 
            }                                       
          }
        }   
      }
    }
    cout << ans << endl; 
  }
  return 0; 
}