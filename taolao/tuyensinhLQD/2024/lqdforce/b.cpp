#include <iostream>
#include <vector>
#include <math.h> 
#include <utility> 
#include <string> 
std::string s; 
int n, m, numQueries; 
const int alphabet = 256; 
std::vector <int> p, c, cnt; 
std::vector <std::string> a; 

int main () {
  std::cin >> n >> m >> numQueries;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i]; 
  }
  s = "";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      s += a[i][j]; 
    }
    s += '$'; 
  }  
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      s += a[i][j]; 
    }
    s += '$'; 
  }         
  n = (int) s.size(); 
  p.resize(n);
  c.resize(n); 
  cnt.resize(std::max(alphabet, n), 0);
  for (int i = 0; i < n; i++) {
    cnt[s[i]]++; 
  }
  for (int i = 1; i < alphabet; i++) {
    cnt[i] += cnt[i - 1]; 
  } 
  for (int i = 0; i < n; i++) {
    p[--cnt[s[i]]] = i; 
  }
  int classes = 1; 
  c[p[0]] = 0; 
  for (int i = 1; i < n; i++) {
    if (s[p[i]] != s[p[i - 1]]) {
      classes++; 
    }
    c[p[i]] = classes - 1; 
  }
  std::vector <int> pn(n), cn(n); 
  for (int h = 0; (1 << h) < n; h++) {
    for (int i = 0; i < n; i++) {
      pn[i] = p[i] - (1 << h); 
      if (pn[i] < 0) {
        pn[i] += n; 
      }
    }
    for (int i = 0; i < classes; i++) {
      cnt[i] = 0; 
    }
    for (int i = 0; i < n; i++) {
      cnt[c[pn[i]]]++; 
    }
    for (int i = 1; i < classes; i++) {
      cnt[i] += cnt[i - 1]; 
    }
    for (int i = n - 1; i >= 0; i--) {
      p[--cnt[c[pn[i]]]] = pn[i]; 
    }            
    classes = 1; 
    cn[p[0]] = 0;
    for (int i = 1; i < n; i++) {
      std::pair <int, int> cur = std::make_pair(c[p[i]], c[(p[i] + (1 << h)) % n]); 
      std::pair <int, int> prev = std::make_pair(c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]); 
      if (cur != prev) {
        classes++; 
      }
      cn[p[i]] = classes - 1; 
    }
    c.swap(cn); 
  }
  p.erase(p.begin());
  n--; 
  for (int query = 1; query <= numQueries; query++) {
    std::string st;
    std::cin >> st;
    if ((int) st.size() > (int) s.size()) {
      std::cout << 0 << std::endl;
      continue; 
    }
    int maxLeft = 0; 
    int minRight = n - 1; 
    bool check = true; 
    for (int i = 0; i < (int) st.size(); i++) {
      int lo = maxLeft;
      int hi = minRight;
      int pLeft = -1; 
      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (p[mid] + i >= n) {
          lo = mid + 1; 
          continue; 
        }   
        if (s[p[mid] + i] == st[i]) {
          pLeft = mid; 
          hi = mid - 1; 
        }                        
        else if (s[p[mid] + i] > st[i]) {
          hi = mid - 1; 
        }
        else {
          lo = mid + 1; 
        }
      }  
      if (pLeft == -1) {
        check = false; 
        break; 
      }
      lo = maxLeft; 
      hi = minRight;
      int pRight = -1; 
      while (lo <= hi) {
        int mid = (lo + hi) / 2; 
        if (p[mid] + i >= n) {
          lo = mid + 1; 
          continue; 
        }
        if (s[(p[mid] + i) % n] == st[i]) {
          pRight = mid;
          lo = mid + 1; 
        }
        else if (s[(p[mid] + i) % n] < st[i]) {
          lo = mid + 1; 
        }
        else {
          hi = mid - 1; 
        }
      }
      if (pRight == -1) {
        check = false; 
        break; 
      }
      maxLeft = pLeft;
      minRight = pRight; 
    }
    if (check == false) {
      std::cout << 0; 
    }
    else {
      std::cout << 1; 
    }
  }
  return 0; 
}