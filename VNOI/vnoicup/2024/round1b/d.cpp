#include <iostream>
#include <string> 
#include <math.h> 
int f[2][12][12][3][3]; 
int n, k; 
std::string s; 
void updateMax(int &a, int b) {
  a = std::max(a, b); 
}

int main () {
  int numTest;
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k;
    std::cin >> s; 
    for (int i = 0; i <= 1; i++) {
      for (int changeK = 0; changeK <= k; changeK++) {
        for (int changeO = 0; changeO <= k; changeO++) {
          for (int diff = 0; diff <= 2; diff++) {
            for (int ch = 0; ch <= 2; ch++) {
              f[i][changeK][changeO][diff][ch] = -2; 
            } 
          }
        }
      }
    }
    f[0][0][0][1][0] = 0;
    for (int i = 0; i < n; i++) {
      int now = i % 2; 
      int nxt = !now; 
      for (int changeK = 0; changeK <= k; changeK++) {
        for (int changeO = 0; changeO <= k; changeO++) {
          for (int diff = 0; diff <= 2; diff++) {
            for (int ch = 0; ch <= 2; ch++) {
              f[nxt][changeK][changeO][diff][ch] = -2; 
            }
          }
        }
      }
      for (int changeK = 0; changeK <= k; changeK++) {
        for (int changeO = 0; changeO <= k; changeO++) {
          for (int diff = 0; diff <= 2; diff++) {
            for (int ch = 0; ch <= 2; ch++) {
              if (f[now][changeK][changeO][diff][ch] == -2) {
                continue; 
              }
              if (ch == 0) {
                updateMax(f[nxt][changeK][changeO + (s[i] == 'K')][diff][1], f[now][changeK][changeO][diff][ch]);
                updateMax(f[nxt][changeK + (s[i] == 'O')][changeO][diff][2], f[now][changeK][changeO][diff][ch]);    
              }
              else if (ch == 1) {
                if (s[i] == 'O' || (s[i] == 'K' && changeO < k)) {
                  updateMax(f[nxt][changeK][changeO + (s[i] == 'K')][diff][1], f[now][changeK][changeO][diff][ch]); 
                }
                if (s[i] == 'K' || (s[i] == 'O' && changeK < k)) {
                  updateMax(f[nxt][changeK + (s[i] == 'O')][changeO][diff + 1][2], f[now][changeK][changeO][diff][ch] + 1); 
                }
              }
              else {
                if (s[i] == 'O' || (s[i] == 'K' && changeO < k)) {
                  updateMax(f[nxt][changeK][changeO + (s[i] == 'K')][diff - 1][1], f[now][changeK][changeO][diff][ch] + 1); 
                }
                if (s[i] == 'K' || (s[i] == 'O' && changeK < k)) {
                  updateMax(f[nxt][changeK + (s[i] == 'O')][changeO][diff][2], f[now][changeK][changeO][diff][ch]);
                }
              }
            }
          }
        }
      }
    } 
    int ans = -2;
    for (int change = 0; change <= k; change++) {
      for (int diff = 1; diff <= 2; diff++) {
        for (int ch = 1; ch <= 2; ch++) {
          if (f[n % 2][change][change][diff][ch] == -2) {
            continue; 
          }
          int realDiff = diff - 1; 
          updateMax(ans, realDiff * f[n % 2][change][change][diff][ch]); 
        }
      }
    }
    std::cout << ans << std::endl;                                                                     
  }
  return 0; 
}