#include <iostream>
#include <algorithm>
#include <string> 
#include <cstring>
int numTest; 
long long dp[15][120][120][3]; 
long long A, B; 

std::string convertToString(long long n) {
  std::string ret = ""; 
  if (n == 0) {
    return "0"; 
  }
  while (n > 0) {
    int r = n % 10; 
    n /= 10; 
    ret += (char) (r + '0'); 
  }
  std::reverse(ret.begin(), ret.end()); 
  return ret; 
}

long long calc(long long n, int sumDigit) {
  if (n == 0) {
    return 0; 
  }
  std::string N = convertToString(n); 
  int len = (int) N.size(); 
  std::memset(dp, 0, sizeof(dp)); 
  for (int dig = 1; dig <= 9; dig++) {
    int state = 0; 
    if (dig == N[0] - '0') {
      state = 1; 
    }
    else if (dig > N[0] - '0') {
      state = 2; 
    }
    if (dig <= sumDigit) {
      dp[1][dig % sumDigit][dig][state]++; 
    }
  }
  for (int i = 1; i < len; i++) {
    for (int mulDigit = 0; mulDigit < sumDigit; mulDigit++) {
      for (int totalDigit = 0; totalDigit <= sumDigit; totalDigit++) {
        for (int state = 0; state <= 2; state++) {
          if (dp[i][mulDigit][totalDigit][state] == 0) {
            continue; 
          }
          for (int dig = 0; dig <= 9; dig++) {
            if (totalDigit + dig > sumDigit) {
              continue; 
            }
            int nextTotalDigit = totalDigit + dig; 
            int nextMulDigit = (mulDigit * dig) % sumDigit; 
            int nextState = state; 
            if (state == 1) {
              if (dig < N[i] - '0') {
                nextState = 0; 
              }
              else if (dig > N[i] - '0') {
                nextState = 2; 
              }
            }
            dp[i + 1][nextMulDigit][nextTotalDigit][nextState] += dp[i][mulDigit][totalDigit][state]; 
          }
        }
      }
    }
  }
  long long ret = 0LL; 
  for (int i = 1; i <= len; i++) {
    for (int state = 0; state <= (i < len ? 2 : 1); state++) {
      ret += dp[i][0][sumDigit][state]; 
    }
  }
  return ret; 
}

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> A >> B; 
    long long ans = 0LL; 
    for (int sumDigit = 1; sumDigit <= 110; sumDigit++) {
      ans += calc(B, sumDigit) - calc(A - 1, sumDigit);   
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}