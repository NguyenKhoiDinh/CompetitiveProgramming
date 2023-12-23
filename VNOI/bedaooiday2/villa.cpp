#include <iostream> 
#include <vector>
#include <string>
#include <vector> 
#include <algorithm> 
std::string a[2005]; 
long long ans = 0LL; 
long long sum = 0LL; 
long long sumSquare = 0LL; 
std::vector <std::pair <int, int> > v; 
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int cnt = 0; 
int n, m; 
int fw[2005]; 

void dfs(int x, int y) {
  a[x][y] = '#';
  cnt++; 
  v.push_back(std::make_pair(x + 1, y + 1)); 
  for (int i = 0; i < 4; i++) {
    int nextx = x + dx[i];
    int nexty = y + dy[i]; 
    if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < m && a[nextx][nexty] == '.') {
      dfs(nextx, nexty); 
    }
  }
} 

bool compare(const std::pair <int, int> &a, const std::pair <int, int> &b) {
  return a.first > b.first; 
}

void update(int index, const int &value) {
  for (; index <= 2000; index += index & -index) {
    fw[index] += value; 
  }
}

int get(int index) {
  int ret = 0;
  for (; index > 0; index -= index & -index) {
    ret += fw[index]; 
  }
  return ret; 
}

void solve(std::vector <std::pair <int, int> > &v) {
  std::sort(v.begin(), v.end(), compare);
  int l = 0;
  for (int i = 1; i < (int) v.size(); i++) {
    while (v[l].first > v[i].first) {
      update(v[l].second, 1); 
      l++; 
    }
    ans += (long long) get(v[i].second - 1); 
  }     
}

int main () {
  freopen("villa.inp", "r", stdin);
  freopen("villa.out", "w", stdout);
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i]; 
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.') {
        cnt = 0; 
        v.clear(); 
        dfs(i, j);
        sum += cnt;
        sumSquare += 1LL * cnt * cnt;
        solve(v);   
      }
    }
  }
  ans += ((long long) sum * sum - sumSquare) / 2; 
  std::cout << ans; 
  return 0; 
}