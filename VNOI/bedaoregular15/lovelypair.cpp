#include <iostream> 
#include <string> 
#include <algorithm>
const int mod = 1000000007LL; 
long long l, r;
int k;  
int dp[70][10005][2][2][2][2][2]; 
std::string convert(long long N) {
  std::string ret = "";
  while (N > 0) {
    int r = N % 2;
    N /= 2; 
    ret += (char) (r + '0'); 
  } 
  std::reverse(ret.begin(), ret.end()); 
  return ret; 
}

void dynamicProgramming() {
  std::string L = convert(l);
  std::string R = convert(r);
  while ((int) L.size() < (int) R.size()) {
    L = "0" + L; 
  }
  int len = (int) R.size(); 
  dp[0][0][1][1][1][1][1] = 1;
  for (int i = 0; i < len; i++) {
    for (int remainder = 0; remainder < k; remainder++) {
      for (int lowa = 0; lowa <= 1; lowa++) {
        for (int upa = 0; upa <= 1; upa++) {
          for (int lowb = 0; lowb <= 1; lowb++) {
            for (int upb = 0; upb <= 1; upb++) {
              for (int smaller = 0; smaller <= 1; smaller++) {
                if (dp[i][remainder][lowa][upa][lowb][upb][smaller] == 0) {
                  continue; 
                }
                int cur = dp[i][remainder][lowa][upa][lowb][upb][smaller]; 
                for (int ba = 0; ba <= 1; ba++) {
                  if (lowa == 1 && ba < (L[i] - '0')) {
                    continue; 
                  }   
                  if (upa == 1 && ba > (R[i] - '0')) {
                    continue; 
                  }
                  for (int bb = 0; bb <= 1; bb++) {
                    if (lowb == 1 && bb < (L[i] - '0')) {
                      continue; 
                    }
                    if (upb == 1 && bb > (R[i] - '0')) {                
                      continue; 
                    }
                    if (smaller == 1 && ba > bb) {
                      continue; 
                    }
                    int valuea = ba ^ bb; 
                    int valueb = ba & bb; 
                    int nextRemainder = ((remainder * 2) % k + (valuea - valueb) + k) % k;
                    int nextLowa = lowa;
                    if (lowa == 1 && ba > L[i] - '0') {
                      nextLowa = 0; 
                    } 
                    int nextUpa = upa; 
                    if (upa == 1 && ba < R[i] - '0') {
                      nextUpa = 0; 
                    }
                    int nextLowb = lowb;                             
                    if (lowb == 1 && bb > L[i] - '0') {
                      nextLowb = 0; 
                    } 
                    int nextUpb = upb; 
                    if (upb == 1 && bb < R[i] - '0') {
                      nextUpb = 0;   
                    }
                    int nextSmaller = smaller;
                    if (smaller == 1 && ba < bb) {
                      nextSmaller = 0; 
                    }  
                    (dp[i + 1][nextRemainder][nextLowa][nextUpa][nextLowb][nextUpb][nextSmaller] += cur) %= mod; 
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  int ans = 0LL;
  for (int lowa = 0; lowa <= 1; lowa++) {
    for (int upa = 0; upa <= 1; upa++) {
      for (int lowb = 0; lowb <= 1; lowb++) {
        for (int upb = 0; upb <= 1; upb++) {
          (ans += dp[len][0][lowa][upa][lowb][upb][0]) %= mod; 
        }
      }
    }
  }  
  std::cout << ans; 
}

int main () {     
  std::cin >> l >> r >> k;   
  dynamicProgramming(); 
  return 0; 
}