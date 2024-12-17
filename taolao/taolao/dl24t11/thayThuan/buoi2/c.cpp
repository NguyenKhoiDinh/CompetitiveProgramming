#include <iostream> 
#include <math.h>
#include <vector> 
#include <map>
int n, m;
std::vector <std::vector <int> > a, b; 
int longestIncreasingSubsequence(const std::vector <int> &pos) {
  int sz = (int) pos.size(); 
  std::vector <int> f(sz + 5, sz + 5);
  f[0] = 0;
  int maxLength = 0; 
  for (int i = 1; i < sz; i++) {
    if (pos[f[maxLength]] < pos[i]) {
      maxLength++; 
      f[maxLength] = i; 
    }
    else {
      int lo = 0;
      int hi = maxLength - 1; 
      int len = -1; 
      while (lo <= hi) {
        int mid = (lo + hi) / 2; 
        if (pos[f[mid]] < pos[i]) {
          len = mid;
          lo = mid + 1;  
        }
        else {
          hi = mid - 1; 
        }
      }
      if (pos[f[len + 1]] > pos[i]) {
        f[len + 1] = i; 
      }
    }  
  }
  return maxLength;    
}

int main () {
  std::ios_base::sync_with_stdio(false);
  freopen("LIBRARIAN.INP", "r", stdin);
  freopen("LIBRARIAN.OUT", "w", stdout);
  std::cin >> n >> m;
  a.resize(n);
  b.resize(n); 
  for (int i = 0; i < n; i++) {
    a[i].resize(m); 
    b[i].resize(m); 
  }  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j]; 
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> b[i][j]; 
    }
  }
  int numbZero = 0;
  int fail = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] != b[i][j]) {
        fail++; 
      }
      if (a[i][j] == 0) {
        numbZero++; 
      }
    }
  } 
  if (fail == 0) {
    std::cout << 0;
    return 0; 
  }
  if (numbZero == 0) {
    std::cout << -1; 
    return 0; 
  }
  int ans = 0; 
  for (int i = 0; i < n; i++) {
    std::vector <int> &geta = a[i];
    std::vector <int> &getb = b[i];
    std::map <int, int> position;
    for (int j = 0; j < m; j++) {
      if (geta[j] > 0) {
        position[geta[j]] = j; 
      }
    }  
    std::vector <int> posb;
    posb.push_back(-1); 
    for (int j = 0; j < m; j++) {
      if (getb[j] > 0) {
        posb.push_back(position[getb[j]]); 
      }
    }
    int correct = longestIncreasingSubsequence(posb);
    bool have = false; 
    for (int j = 0; j < m; j++) {
      if (geta[j] == 0) {
        have = true; 
        break;
      }
    }
    if (have == true) {
      ans += (int) posb.size() - 1 - correct; 
    }   
    else {
      if (correct < (int) posb.size() - 1) {
        ans += (int) posb.size() - correct; 
      }
    }
  }
  std::cout << ans; 
  return 0; 
}