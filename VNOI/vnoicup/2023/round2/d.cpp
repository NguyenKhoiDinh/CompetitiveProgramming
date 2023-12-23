#include <iostream> 
#include <vector> 
#include <math.h> 
#include <algorithm> 
#include <utility> 
int n, m;
std::vector <std::vector <int> > a; 

std::vector <std::vector <int> > rotateMatrix(const std::vector <std::vector <int> > &a) {
  int n = (int) a.size();
  int m = (int) a[0].size();
  std::vector <std::vector <int> > ret;
  for (int i = m - 1; i >= 0; i--) {
    std::vector <int> v; 
    for (int j = 0; j < n; j++) {
      v.push_back(a[j][i]);  
    }
    ret.push_back(v); 
  }  
  return ret; 
}

void update(int index, int value, std::vector <int> &fw) {
  for (; index <= 2 * m; index += index & -index) {
    fw[index] += value;   
  }
}

long long get(int index, const std::vector <int> &fw) {
  long long ret = 0LL; 
  for (; index > 0; index -= index & -index) {
    ret += fw[index]; 
  }
  return ret; 
}

bool compare1(const std::pair <int, int> &a, const std::pair <int, int> &b) {
  return a.first < b.first; 
}

bool compare2(const std::pair <int, int> &a, const std::pair <int, int> &b) {
  return a.second < b.second; 
}

int main () {
  std::cin >> n >> m;
  a.resize(n); 
  for (int i = 0; i < n; i++) {
    a[i].resize(m, 0); 
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j]; 
      a[i][j] = std::min(a[i][j], std::max(n, m) + 1); 
    }
  }
  if (n > m) {
    a = rotateMatrix(a); 
    std::swap(n, m); 
  }
  long long ans = 0LL; 
  for (int r1 = 0; r1 < n; r1++) {
    for (int r2 = r1 + 1; r2 < n; r2++) {
      std::vector <int> fw;
      fw.resize(2 * m + 2, 0);
      std::vector <std::pair <int, int> > save1, save2;  
      for (int c = 0; c < m; c++) {
        bool ok1 = false;
        bool ok2 = false;
        if (a[r2][c] >= r2 - r1) {
          ok1 = true; 
        }  
        if (a[r1][c] >= r2 - r1) {
          ok2 = true; 
        }
        if (ok1 == true) {
          save1.push_back(std::make_pair(c, a[r1][c] + c)); 
        }
        if (ok2 == true) {
          save2.push_back(std::make_pair(c, c - a[r2][c])); 
        }
      }                                
      std::sort(save1.begin(), save1.end(), compare1);
      std::sort(save2.begin(), save2.end(), compare2);
      int p2 = 0;
      for (int i = 0; i < (int) save1.size(); i++) {
        while (p2 < (int) save2.size() && save2[p2].second <= save1[i].first) {
          if (save2[p2].first > save1[i].first) {
            update(save2[p2].first + 1, 1, fw); 
          }
          p2++; 
        }
        if (save1[i].second >= 0) {
          ans += get(save1[i].second + 1, fw); 
          ans -= get(save1[i].first + 1, fw); 
        }
      }                  
    }
  }
  std::cout << ans; 
  return 0;
}