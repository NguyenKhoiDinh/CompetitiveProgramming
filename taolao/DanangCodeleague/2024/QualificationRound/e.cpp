#include <iostream>
#include <string> 
#include <math.h> 
#include <algorithm>
#include <utility>
const long long mod = 1000000007LL; 
int numTest;
long long f[20][10][3];
long long sum[20][10][3], sum2[20][10][3];  
std::string convertToString(long long N) {
  if (N == 0) {
    return "0"; 
  }
  std::string ret = ""; 
  while (N > 0) {
    int r = N % 10; 
    ret += (char) (r + '0'); 
    N /= 10; 
  }
  std::reverse(ret.begin(), ret.end()); 
  return ret; 
}
std::pair <long long, long long> calc(long long n) {
  std::string N = convertToString(n); 
  int len = (int) N.size(); 
  for (int i = 0; i <= len; i++) {
    for (int j = 0; j <= len; j++) {
      for (int state = 0; state <= 2; state++) {
        f[i][j][state] = 0;
        sum[i][j][state] = 0LL; 
        sum2[i][j][state] = 0LL; 
      }
    }
  }
  for (int dig = 1; dig <= 9; dig++) {
    if (dig % 2 == 1) {
      continue; 
    }
    int state = 0;
    if (dig == N[0] - '0') {
      state = 1; 
    }
    else if (dig > N[0] - '0') {
      state = 2; 
    }
    f[1][1][state]++; 
    sum[1][1][state] += dig; 
    sum2[1][1][state] += dig * dig; 
  }
  for (int i = 1; i < len; i++) {
    for (int freeOpen = 0; freeOpen <= std::min(i, len / 2); freeOpen++) {
      for (int state = 0; state <= 2; state++) {
        if (f[i][freeOpen][state] == 0) {
          continue; 
        }
        for (int dig = 0; dig <= 9; (freeOpen == 0 ? dig += 2 : dig++)) {
          int nextState = state;
          if (state == 1 && dig < N[i] - '0') {
            nextState = 0; 
          }
          else if (state == 1 && dig > N[i] - '0') {
            nextState = 2; 
          }  
          int nextFreeOpen = freeOpen + (dig % 2 == 0 ? 1 : -1);
          if (2LL * nextFreeOpen > len) {
            continue; 
          }
          (f[i + 1][nextFreeOpen][nextState] += f[i][freeOpen][state]) %= mod;
          long long ssum = 0LL; 
          ssum += sum[i][freeOpen][state] * 10LL; 
          ssum += f[i][freeOpen][state] * dig; 
          (sum[i + 1][nextFreeOpen][nextState] += ssum) %= mod; 
          ssum = 0LL; 
          ssum += sum2[i][freeOpen][state] * 100LL; 
          ssum += sum[i][freeOpen][state] * (long long) dig * 20LL; 
          ssum += f[i][freeOpen][state] * dig * dig; 
          (sum2[i + 1][nextFreeOpen][nextState] += ssum) %= mod;
        }
      }
    }
  }
  long long f1 = 0LL;          
  long long f2 = 0LL;
  for (int i = 1; i <= len; i++) {
    for (int state = 0; state <= (i < len ? 2 : 1); state++) {
      (f1 += f[i][0][state]) %= mod;
      (f2 += sum2[i][0][state]) %= mod; 
    }
  }    
  return std::make_pair(f1, f2); 
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    long long a, b;
    std::cin >> a >> b;
    std::pair <long long, long long> fb = calc(b);
    std::pair <long long, long long> fa = calc(a - 1);
    std::cout << (fb.first - fa.first + mod) % mod << ' ' << (fb.second - fa.second + mod) % mod << std::endl;  
  } 
  return 0; 
}