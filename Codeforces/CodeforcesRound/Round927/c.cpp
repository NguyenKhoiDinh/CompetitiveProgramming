#include <iostream>
#include <string> 
int numTest; 
int a[200005];
int ans[200005];  
std::string s; 
int n, m; 

int solve(int l, int r, int step) {
  if (l == r) {
    ans[step] = a[l] % m; 
    return ans[step];   
  }
  int value; 
  if (s[step] == 'L') {
    value = (solve(l + 1, r, step + 1) * a[l]) % m; 
  }
  else {
    value = (solve(l, r - 1, step + 1) * a[r]) % m; 
  }
  ans[step] = value;
  return value; 
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {                  
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
    }
    std::cin >> s; 
    solve(1, n, 0);
    for (int i = 0; i < n; i++) {
      std::cout << ans[i] << ' '; 
    } 
    std::cout << std::endl; 
  }
  return 0; 
}