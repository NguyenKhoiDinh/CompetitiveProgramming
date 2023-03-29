#include <iostream>
#include <string>  
const int mod = 1000000007; 

int f[10005][100][3]; 
std::string N; 
int d; 

int main () {
  std::cin >> N >> d; 
  N = "0" + N; 
  int len = (int) N.size() - 1;
  f[0][0][1] = 1;
  for (int i = 0; i < len; i++) {
    for (int r = 0; r < d; r++) {
      for (int state = 0; state <= 1; state++) {
        if (f[i][r][state] == 0) {
          continue; 
        }
        for (int digit = 0; digit <= 9; digit++) {
          if (state == 1 && digit > N[i + 1] - '0') {
            continue; 
          }
          int nextState = state;
          if (state == 1 && digit < N[i + 1] - '0') {
            nextState = 0; 
          }
          (f[i + 1][(r + digit) % d][nextState] += f[i][r][state]) %= mod; 
        }
      }
    }
  }
  int ans = f[len][0][0];
  (ans += f[len][0][1]) %= mod;
  ans--;
  (ans += mod) %= mod;
  std::cout << ans;  
  return 0; 
}