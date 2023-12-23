#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stack>
int numTest; 
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

void process(const std::vector <std::string> &a, const std::vector <std::string> &b) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::vector <std::vector <int> > match; 
      match.resize(i + 1);
      for (int k = 0; k <= i; k++) {
        match[k].resize(j + 1, 0); 
      }
      for (int x = 0; x <= i; x++) {
        for (int y = 0; y <= j; y++) {
          if (a[n - 1 - i + x][m - 1 - j + y] == b[x][y]) {
            match[x][y] = 1; 
          }
        }
      }
      solve(match); 
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::vector <std::vector <int> > match; 
      match.resize(i + 1);
      for (int k = 0; k <= i; k++) {
        match[k].resize(m - j, 0); 
      }
      for (int x = 0; x <= i; x++) {
        for (int y = j; y <= m - 1; y++) {
          if (a[n - 1 - i + x][y - j] == b[x][y]) {
            match[x][y - j] = 1; 
          }  
        }
      }
      solve(match); 
    }
  }  
}

int main () {
  //freopen("MESSAGE.INP", "r", stdin);
  //freopen("MESSAGE.OUT", "w", stdout);
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m;
    ans = 0; 
    std::vector <std::string> a, b; 
    a.resize(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    b.resize(n);
    for (int i = 0; i < n; i++) {
      std::cin >> b[i];
    }
    process(a, b);
    process(b, a); 
    std::cout << ans << std::endl; 
  }
  return 0; 
}