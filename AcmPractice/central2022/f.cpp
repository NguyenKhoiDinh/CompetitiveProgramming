#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
int n, m; 
std::vector <std::string> a; 
std::map <std::vector <std::string>, int> mymap; 

void modify(const std::vector <std::string> &a) {
  int len = (int) a.size();
  bool check = false; 
  for (int mask = 0; mask < (1 << len); mask++) {
    std::vector <std::string> tmp = a; 
    for (int i = 0; i < len; i++) {
      if ((mask & (1 << i)) > 0) {
        std::swap(tmp[i][0], tmp[i][2]);
        std::swap(tmp[i][3], tmp[i][5]);
        std::swap(tmp[i][6], tmp[i][8]);
        std::swap(tmp[i][0], tmp[i][6]);
        std::swap(tmp[i][1], tmp[i][7]);
        std::swap(tmp[i][2], tmp[i][8]);  
      }
    }
    std::sort(tmp.begin(), tmp.end()); 
    if (mymap.find(tmp) != mymap.end()) {
      mymap[tmp]++; 
      check = true; 
      break; 
    }
  }  
  if (check == false) {
    std::vector <std::string> v = a; 
    std::sort(v.begin(), v.end()); 
    mymap[v] = 1; 
  }
}

int main () {
  std::cin >> n >> m;
  a.resize(n); 
  for (int i = 0; i < n; i++) {
    std::cin >> a[i]; 
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '#') {
        int r1 = i;
        int r2 = i + 4; 
        int c1 = j; 
        int c2 = j + 4; 
        while (c2 < m) {
          int nextc2 = c2 + 4; 
          if (nextc2 >= m) {
            break; 
          }
          bool check = true; 
          for (int x = r1; x <= r2; x++) {
            if (check == false) {
              break; 
            }
            for (int y = c2; y <= nextc2; y++) {
              if ((x == r1 || x == r2 || y == c2 || y == nextc2) && a[x][y] != '#') {
                check = false; 
                break; 
              }
            }
          }
          if (check == true) {
            c2 = nextc2; 
          }
          else {
            break; 
          }
        }
        while (r2 < n) {
          int nextr2 = r2 + 4;
          if (nextr2 >= n) {
            break; 
          }
          bool check = true; 
          for (int x = r2; x <= nextr2; x++) {
            if (check == false) {
              break; 
            }
            for (int y = c1; y <= c2; y++) {
              if ((x == r2 || x == nextr2 || y == c1 || y == c2) && a[x][y] != '#') {
                check = false; 
                break; 
              }
            }
          }
          if (check == true) {
            r2 = nextr2; 
          }
          else {
            break; 
          }
        }
        std::vector <std::string> v; 
        if (r2 - r1 == 4) {
          for (int c = c1; c + 4 <= c2; c += 4) {
            int nextc = c + 4;
            std::string s = ""; 
            for (int x = r1 + 1; x <= r2 - 1; x++) {
              for (int y = c + 1; y <= nextc - 1; y++) {
                s += a[x][y];
              }
            }
            v.push_back(s);    
          }
        }
        else {
          for (int r = r1; r + 4 <= r2; r += 4) {
            int nextr = r + 4; 
            std::string s = "";
            for (int y = c2 - 1; y >= c1 + 1; y--) {
              for (int x = r + 1; x <= nextr - 1; x++) {
                s += a[x][y];
              }
            }
            v.push_back(s); 
          }
        }
        modify(v); 
        for (int x = r1; x <= r2; x++) {
          for (int y = c1; y <= c2; y++) {
            a[x][y] = '.'; 
          }
        }
      }
    }
  }
  std::vector <int> ans; 
  for (std::map <std::vector <std::string>, int> :: iterator it = mymap.begin(); it != mymap.end(); it++) {
    ans.push_back(it->second); 
  }
  std::sort(ans.begin(), ans.end()); 
  std::cout << (int) ans.size() << std::endl;
  for (int i = 0; i < (int) ans.size(); i++) {
    std::cout << ans[i] << ' '; 
  }
  return 0; 
}