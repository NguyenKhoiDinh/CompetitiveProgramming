#include <iostream>
#include <math.h> 
int f[100005]; 
int n, numTest; 
int l[100005], r[100005], val[100005], minVertex[100005], maxVertex[100005]; 
int father[100005]; 
int ans; 
void dfs(int root) {
  f[root] = 1;
  maxVertex[root] = root;
  minVertex[root] = root;  
  if (l[root] != 0) {
    dfs(l[root]);
    f[root] += f[l[root]];
    int prev = -1;
    int cur = maxVertex[l[root]];
    while (cur != root && val[cur] >= val[root]) {
      prev = cur; 
      cur = father[cur];
    }
    if (prev != -1) {
      f[root] -= f[prev]; 
    }
    if (cur != root) {
      minVertex[root] = minVertex[l[root]]; 
    }    
  }
  if (r[root] != 0) {
    dfs(r[root]); 
    f[root] += f[r[root]];
    int prev = -1;
    int cur = minVertex[r[root]];
    while (cur != root && val[cur] <= val[root]) {
      prev = cur;
      cur = father[cur];  
    }
    if (prev != -1) {
      f[root] -= f[prev]; 
    } 
    if (cur != root) {
      maxVertex[root] = maxVertex[r[root]]; 
    }
  }
  ans = std::max(ans, f[root]); 
}

int main () {
  std::ios_base::sync_with_stdio(false); 
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      l[i] = 0;
      r[i] = 0;
      val[i] = 0;
      father[i] = 0; 
      minVertex[i] = 0;
      maxVertex[i] = 0; 
    }
    for (int i = 1; i <= n; i++) {
      std::cin >> l[i] >> r[i] >> val[i]; 
      father[l[i]] = i;
      father[r[i]] = i; 
    }
    ans = -1; 
    dfs(1); 
    std::cout << ans << std::endl; 
  }
  return 0; 
}