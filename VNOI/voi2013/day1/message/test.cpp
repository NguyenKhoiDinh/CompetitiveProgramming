#include <iostream>
#include <stack>
#include <vector> 
std::vector <std::vector <int> > a; 
int n, m; 
int ans = 0; 

void solve(const std::vector <std::vector <int> > &a) {
  int r = (int) a.size();
  int c = (int) a[0].size(); 
  std::vector <std::vector <int> > f;
  f.resize(r);
  for (int i = 0; i < r; i++) {
    f[i].resize(c, 0); 
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (a[i][j] == 1) {
        f[i][j] = (i == 0 ? 0 : f[i - 1][j]) + 1; 
      }
    }
  }
  for (int i = 0; i < r; i++) {
    std::vector <int> v(c); 
    for (int j = 0; j < c; j++) {
      v[j] = f[i][j]; 
    }
    std::vector <int> L(c), R(c); 
    std::stack <int> mystack; 
    for (int j = 0; j < c; j++) {
      while (mystack.empty() == false && v[mystack.top()] >= v[j]) {
        mystack.pop(); 
      }  
      if (mystack.empty() == true) {
        L[j] = -1; 
      }
      else {
        L[j] = mystack.top(); 
      }
      mystack.push(j); 
    }
    while (mystack.empty() == false) {
      mystack.pop(); 
    }
    for (int j = c - 1; j >= 0; j--) {
      while (mystack.empty() == false && v[mystack.top()] >= v[j]) {
        mystack.pop(); 
      }  
      if (mystack.empty() == true) {
        R[j] = c; 
      }
      else {
        R[j] = mystack.top(); 
      }
      mystack.push(j); 
    }
    for (int j = 0; j < c; j++) {
      ans = std::max(ans, v[j] * (R[j] - L[j] - 1)); 
    }
  }
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  std::cin >> n >> m;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    a[i].resize(m);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
    }
  }
  solve(a); 
  std::cout << ans; 
  return 0; 
}