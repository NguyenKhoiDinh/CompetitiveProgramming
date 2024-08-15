#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>  

const std::string inf = "10000000000000000000007LL";  
int numTest; 
std::string f[22][2];
std::string N;  
std::string cost[22][22][2]; 
int n; 

std::string add(std::string s1, std::string s2) {
  std::string ret = ""; 
  while ((int) s1.size() < (int) s2.size()) {
    s1 = "0" + s1; 
  }
  while ((int) s2.size() < (int) s1.size()) {
    s2 = "0" + s2; 
  }
  int rem = 0; 
  for (int i = (int) s1.size() - 1; i >= 0; i--) {
    int x = s1[i] - '0';
    int y = s2[i] - '0'; 
    ret += (char) ((x + y + rem) % 10 + '0');
    rem = (x + y + rem) / 10;  
  }
  std::reverse(ret.begin(), ret.end()); 
  if (rem == 1) {
    ret = "1" + ret; 
  }
  return ret; 
}
std::string getMin(std::string s1, std::string s2) {
  std::string ret = s1; 
  if ((int) ret.size() > (int) s2.size()) {
    ret = s2; 
  }
  if ((int) ret.size() < (int) s2.size()) {
    return ret; 
  }
  if (ret > s2) {
    ret = s2; 
  } 
  return ret; 
}

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> N;
    for (int l = 1; l <= n; l++) {
      for (int r = l; r <= n; r++) {
        std::string mul = "1"; 
        for (int i = l; i <= r; i++) {
          std::string more = mul; 
          for (int t = 1; t <= N[i - 1] - '0'; t++) {
            more = add(more, mul);  
          }
          mul = more; 
        }  
        cost[l][r][0] = mul;
      }
    }
    for (int l = 1; l <= n; l++) {
      for (int r = l + 1; r <= n; r++) { 
        if (r > l) {
          long long mini = inf; 
          for (int i = l; i < r; i++) {
            long long numb = (N[i - 1] - '0') * 10 + N[i] - '0'; 
            long long mul = numb;
            if (i > l) {
              mul *= cost[l][i - 1][0]; 
            } 
            if (i + 1 < r) {
              mul *= cost[i + 2][r][0]; 
            }
            mini = std::min(mini, mul); 
          }
          cost[l][r][1] = mini; 
        }
      }
    }
    for (int i = 0; i <= n; i++) {
      f[i][0] = f[i][1] = inf; 
    }   
    f[0][0] = 0; 
    for (int i = 0; i < n; i++) {
      for (int state = 0; state <= 1; state++) {
        if (f[i][state] == inf) {
          continue; 
        }
        if (state == 0) {
          for (int j = i + 1; j <= n; j++) {
            if (j - i > 18) {
              continue; 
            }
            f[j][0] = std::min(f[j][0], f[i][state] + cost[i + 1][j][0]); 
          }
          for (int j = i + 2; j <= n; j++) {
            if (j - i - 1 > 18) {
              continue;
            }
            f[j][1] = std::min(f[j][1], f[i][state] + cost[i + 1][j][1]); 
          }
        }
        else {
          for (int j = i + 1; j <= n; j++) {
            if (j - i > 18) {
              continue; 
            }
            f[j][1] = std::min(f[j][1], f[i][state] + cost[i + 1][j][0]); 
          }
        }
      }
    }
    std::cout << f[n][1] << std::endl;
  }
  return 0; 
}