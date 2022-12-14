#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 2005;
const long long MOD = 1000000007;
struct coordinate {
  int x, y;
  bool operator < (const coordinate &other) {
    return x > other.x;
  }
};
vector <int> save;
int n;
map <int, int> M;  
coordinate a[MAX_N];
long long dp[MAX_N][MAX_N];
long long fw[MAX_N][MAX_N];

void update(int index, long long value) {
  for (; index > 0; index -= index & -index) {
    (fw[index][
  }
}

int main () {
  freopen("input.txt", "r", stdin);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
    save.push_back(a[i].y);    
  }                      
  sort(save.begin(), save.end());
  int value = 1; 
  for (int i = 0; i < (int) save.size(); i++) {
    M[save[i]] = value;
    if (save[i] != save[i + 1]) {
      value++;
    }
  }
  for (int i = 1; i <= n; i++) {
    a[i].y = M[a[i].y];
  }
  sort(a + 1, a + n + 1);
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      
    }
  }
  return 0;
}