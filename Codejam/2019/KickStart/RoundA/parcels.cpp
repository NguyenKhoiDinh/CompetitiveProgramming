#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 255; 
const int inf = 100005; 
int numTest; 
int dist[MAX_N][MAX_N];
string a[MAX_N];
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool check(int value) {
  int maxPlus = inf, maxMinus = inf, minPlus = -inf, minMinus = -inf;
  bool check = false; 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dist[i][j] > value) {
        maxPlus = min(maxPlus, i + j + value);
        minPlus = max(minPlus, i + j - value);
        maxMinus = min(maxMinus, i - j + value); 
        minMinus = max(minMinus, i - j - value);
        check = true; 
      }
    }
  }
  if (check == false) {
    return true; 
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '0') {
        if (i + j <= maxPlus && i + j >= minPlus && i - j <= maxMinus && i - j >= minMinus) {
          return true; 
        }
      }
    }
  }
  return false; 
}

int main () {
  //freopen("input.txt", "r", stdin); 
  //freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        dist[i][j] = -1; 
      }
    }
    queue <pair <int, int> > myqueue; 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == '1') {
          myqueue.push(make_pair(i, j));
          dist[i][j] = 0; 
        }
      }
    }
    while (!myqueue.empty()) {
      pair <int, int> pr = myqueue.front();
      myqueue.pop(); 
      for (int i = 0; i < 4; i++) {
        int nextx = pr.first + dx[i];
        int nexty = pr.second + dy[i];
        if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < m && dist[nextx][nexty] == -1) {
          dist[nextx][nexty] = dist[pr.first][pr.second] + 1; 
          myqueue.push(make_pair(nextx, nexty));
        }
      }
    }
    int l = 0; 
    int r = 2 * (n + m + 5); 
    int ans = -1; 
    while (l <= r) {
      int mid = (l + r) >> 1; 
      if (check(mid) == true) {
        ans = mid; 
        r = mid - 1; 
      }
      else {
        l = mid + 1; 
      }
    }
    cout << ans << endl; 
  }
  return 0; 
}