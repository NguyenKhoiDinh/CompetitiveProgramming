#include <bits/stdc++.h> 

using namespace std;
int n; 
long long a[2005]; 
long long fw[2005][2005], sum[2005][2005], dp[2005][2005]; 
struct element {
  int l, r, id;
  long long value;
  bool operator < (const element &other) {
    if (value < other.value || (value == other.value && id < other.id)) {
      return true; 
    }
    else {
      return false; 
    }
  }                
};
vector <element> listElement; 
int numQuery; 
long long ans[200005]; 

void update(int x, int y, long long value) {
  for (; x <= 2000; x += x & -x) {
    for (int yy = y; yy <= 2000; yy += yy & -yy) {
      fw[x][yy] += value; 
    }
  }
}

long long get(int x, int y) {
  long long ret = 0LL; 
  for (; x > 0; x -= x & -x) {
    for (int yy = y; yy > 0; yy -= yy & -yy) {
      ret += fw[x][yy]; 
    }
  }
  return ret; 
}

int main () {
  //freopen("input.txt", "r", stdin); 
  //freopen("output.txt", "w", stdout); 
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; 
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      sum[i][j] = sum[i][j - 1] + abs(a[j] - a[i]); 
    }
  }
  for (int j = 1; j <= n; j++) {
    for (int i = j; i >= 1; i--) {
      dp[i][j] = dp[i + 1][j] + sum[i][j]; 
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      listElement.push_back((element) {i, j, -1, dp[i][j]}); 
    }
  }
  cin >> numQuery; 
  for (int query = 1; query <= numQuery; query++) {
    int l, r;
    long long k;
    cin >> l >> r >> k;
    listElement.push_back((element) {l, r, query, k});   
  }
  sort(listElement.begin(), listElement.end()); 
  for (int i = 0; i < (int) listElement.size(); i++) {
    int l = listElement[i].l; 
    int r = listElement[i].r; 
    int id = listElement[i].id; 
    if (id == -1) {
      update(l, r, 1LL); 
    }
    else {
      ans[id] = get(r, r) - get(l - 1, r) - get(r, l - 1) + get(l - 1, l - 1); 
    }
  }
  for (int i = 1; i <= numQuery; i++) {
    cout << ans[i] << endl; 
  }
  return 0; 
}