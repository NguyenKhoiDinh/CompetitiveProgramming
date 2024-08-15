#include <iostream> 
#include <string> 
const int mod = 1000000007; 
int f[200005][2][2][2]; 
std::string s; 

int main () {
  int numTest;
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> s; 
    int n = (int) s.size();
    for (int i = 0; i <= n; i++) {
      for (int even = 0; even <= 1; even++) {
        for (int lastChar = 0; lastChar <= 1; lastChar++) {
          for (int state = 0; state <= 1; state++) {
            f[i][even][lastChar][state] = 0; 
          }
        }
      }
    } 
    f[0][0][0][0] = 1; 
    for (int i = 0; i < n; i++) {
      for (int even = 0; even <= 1; even++) {
        for (int lastChar = 0; lastChar <= 1; lastChar++) {
          for (int state = 0; state <= 1; state++) {
            if (f[i][even][lastChar][state] == 0) {
              continue; 
            }
            int value = f[i][even][lastChar][state]; 
            (f[i + 1][even][lastChar][state] += value) %= mod; 
            if (state == 0) {
              (f[i + 1][even][s[i] == 'K'][1] += value) %= mod; 
            }
            else {
              if (lastChar == 0 && s[i] == 'K') {
                (f[i + 1][even][1][0] += value) %= mod;   
              }
              else if (lastChar == 1 && s[i] == 'O') {
                (f[i + 1][(even + 1) % 2][0][0] += value) %= mod; 
              }
            }
          }
        }
      }
    }
    int ans = f[n][0][0][0];
    (ans += f[n][0][1][0]) %= mod; 
    std::cout << ans << std::endl;
  }
  return 0; 
}