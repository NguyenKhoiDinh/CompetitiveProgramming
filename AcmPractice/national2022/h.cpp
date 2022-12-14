#include <iostream> 
#include <vector>
const long long mod = 998244353LL; 
struct matrix {
  int row, col; 
  std::vector <std::vector <long long> > data; 
  matrix(int _row, int _col) {
    row = _row; 
    col = _col; 
    data.resize(row);
    for (int i = 0; i < row; i++) {
      data[i].resize(col, 0LL); 
    } 
  }
  matrix operator * (const matrix &other) {
    matrix ret(row, other.col);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < other.col; j++) {           
        for (int k = 0; k < col; k++) {
          (ret.data[i][j] += (data[i][k] * other.data[k][j]) % mod) %= mod; 
        }
      }
    } 
    return ret; 
  }
};
long long n; 
long long ways[5][4], dp[5][4]; 

void dynamicProgramming() {
  ways[0][0] = 1;
  dp[0][0] = 0;  
  for (int i = 1; i <= 4; i++) {
    ways[i][0] = (ways[i - 1][0] + ways[i - 1][1] + ways[i - 1][2] + ways[i - 1][3]) % mod;
    dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % mod;  
    if (i >= 2) {
      ways[i][1] = (ways[i - 2][0] + ways[i - 2][1] + ways[i - 2][2] + ways[i - 2][3]) % mod;
      dp[i][1] = (dp[i - 2][0] + dp[i - 2][1] + dp[i - 2][2] + dp[i - 2][3] + 3LL * (ways[i - 2][0] + ways[i - 2][1] + ways[i - 2][2] + ways[i - 2][3])) % mod; 
      ways[i][2] = (ways[i - 2][0] + ways[i - 2][1] + ways[i - 2][2] + ways[i - 2][3]) % mod;
      dp[i][2] = (dp[i - 2][0] + dp[i - 2][1] + dp[i - 2][2] + dp[i - 2][3] + 3LL * (ways[i - 2][0] + ways[i - 2][1] + ways[i - 2][2] + ways[i - 2][3])) % mod; 
      ways[i][3] = (2LL * (ways[i - 2][0] + ways[i - 2][1] + ways[i - 2][2] + ways[i - 2][3])) % mod; 
      dp[i][3] = (2LL * (dp[i - 2][0] + dp[i - 2][1] + dp[i - 2][2] + dp[i - 2][3]) + 6LL * (ways[i - 2][0] + ways[i - 2][1] + ways[i - 2][2] + ways[i - 2][3])) % mod;
    } 
    if (i >= 3) {
      (ways[i][3] += (2LL * (ways[i - 3][0] + ways[i - 3][1] + ways[i - 3][2] + ways[i - 3][3])) % mod) %= mod;  
      (dp[i][3] += (2LL * (dp[i - 3][0] + dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3]) + 12LL * (ways[i - 3][0] + ways[i - 3][1] + ways[i - 3][2] + ways[i - 3][3])) % mod) %= mod;
    }
  }
}

matrix pow_matrix(const matrix &M, const long long n) {
  if (n == 1) {
    return M; 
  }
  matrix ret = pow_matrix(M, n / 2); 
  ret = ret * ret; 
  if (n % 2 == 1) {
    ret = ret * M; 
  }
  return ret; 
}

int main () {
  std::cin >> n;
  if (n == 1) {
    std::cout << 0;
    return 0;  
  }
  if (n == 2) {
    std::cout << 12;
    return 0; 
  }
  if (n == 3) {
    std::cout << 36;
    return 0; 
  }
  dynamicProgramming(); 
  matrix ans(1, 24);
  for (int i = 1; i <= 3; i++) {
    for (int j = 0; j <= 3; j++) {
      ans.data[0][(i - 1) * 4 + j] = ways[i][j];   
    }
  }
  for (int i = 1; i <= 3; i++) {
    for (int j = 0; j <= 3; j++) {
      ans.data[0][(i - 1) * 4 + j + 12] = dp[i][j];   
    }
  }
  matrix base(24, 24);
  long long d[24][24] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 6,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 6,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 6,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 6,
    0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 2,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 2,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0
  };  
  for (int i = 0; i < 24; i++) {
    for (int j = 0; j < 24; j++) {
      base.data[i][j] = d[i][j]; 
    }
  }
  base = pow_matrix(base, n - 3); 
  ans = ans * base; 
  long long ret = 0LL; 
  for (int j = 20; j <= 23; j++) {
    (ret += ans.data[0][j]) %= mod;   
  }
  std::cout << ret; 
  return 0; 
}