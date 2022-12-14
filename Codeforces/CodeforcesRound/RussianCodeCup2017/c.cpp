#include <iostream> 
#include <string> 
#include <vector> 
#include <cstring> 
#include <fstream> 

const long long mod = 998244353LL;
int numTest; 
int n;
std::vector <int> odd, even;     
long long dp_odd[2][2005][11], dp_even[2][2005][11];
long long ways[2005][2005];  
long long fact[2005]; 
                                       
void dynamicProgrammingForOddNumbers(const std::vector <int> &a) {
  int n = (int) a.size(); 
  dp_odd[0][0][0] = 1; 
  for (int i = 0; i < n; i++) {
    int now = i & 1; 
    int nxt = !now; 
    std::memset(dp_odd[nxt], 0, sizeof(dp_odd[nxt])); 
    for (int group = 0; group <= i; group++) {
      for (int r = 0; r < 11; r++) {
        if (dp_odd[now][group][r] == 0) {
          continue; 
        }
        (dp_odd[nxt][group][(r - a[i] + 11) % 11] += dp_odd[now][group][r]) %= mod; 
        (dp_odd[nxt][group + 1][(r + a[i]) % 11] += dp_odd[now][group][r]) %= mod; 
      }
    }
  }
}

void dynamicProgrammingForEvenNumbers(const std::vector <int> &a) {
  int n = (int) a.size(); 
  dp_even[0][0][0] = 1; 
  for (int i = 0; i < n; i++) {
    int now = i & 1; 
    int nxt = !now; 
    std::memset(dp_even[nxt], 0, sizeof(dp_even[nxt])); 
    for (int group = 0; group <= i; group++) {
      for (int r = 0; r < 11; r++) {
        if (dp_even[now][group][r] == 0) {
          continue;                                            
        }
        (dp_even[nxt][group + 1][(r - a[i] + 11) % 11] += dp_even[now][group][r]) %= mod; 
        (dp_even[nxt][group][(r + a[i]) % 11] += dp_even[now][group][r]) %= mod; 
      }
    }
  }
}

void initWays() {
  fact[0] = 1LL; 
  for (int i = 1; i <= 2000; i++) {
    fact[i] = (1LL * fact[i - 1] * i) % mod; 
  }
  for (int i = 0; i <= 2000; i++) {
    ways[i][1] = 1; 
  }  
  for (int j = 0; j <= 2000; j++) {
    ways[0][j] = 1; 
  }
  for (int i = 1; i <= 2000; i++) {
    for (int j = 2; j <= 2000; j++) {
      ways[i][j] = (ways[i - 1][j] + ways[i][j - 1]) % mod; 
    }
  }
}

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  initWays(); 
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::memset(dp_odd, 0, sizeof(dp_odd)); 
    std::memset(dp_even, 0, sizeof(dp_even)); 
    std::cin >> n;
    odd.clear(); 
    even.clear(); 
    for (int i = 1; i <= n; i++) {
      std::string s; 
      std::cin >> s; 
      int len = (int) s.size(); 
      int sum = 0; 
      for (int j = 0; j < len; j++) {
        if (j % 2 == 0) {
          (sum += s[j] - '0') %= 11; 
        }
        else {
          sum -= s[j] - '0'; 
          (sum += 11) %= 11; 
        }
      }
      if (len % 2 == 1) {
        odd.push_back(sum); 
      }
      else {
        even.push_back(sum); 
      }
    }
    dynamicProgrammingForOddNumbers(odd);
    dynamicProgrammingForEvenNumbers(even);
    int szOdd = (int) odd.size(); 
    int szEven = (int) even.size(); 
    int halfOdd = (szOdd + 1) / 2; 
    long long ans = 0LL;
    for (int rOdd = 0; rOdd < 11; rOdd++) {
      int rEven = (11 - rOdd) % 11; 
      for (int evenInOddGroup = 0; evenInOddGroup <= szEven; evenInOddGroup++) {
        long long mul = dp_odd[szOdd & 1][halfOdd][rOdd];
        (mul *= fact[halfOdd]) %= mod;              
        (mul *= fact[szOdd - halfOdd]) %= mod; 
        (mul *= dp_even[szEven & 1][evenInOddGroup][rEven]) %= mod; 
        (mul *= ways[evenInOddGroup][halfOdd]) %= mod; 
        (mul *= ways[szEven - evenInOddGroup][szOdd + 1 - halfOdd]) %= mod; 
        (mul *= fact[evenInOddGroup]) %= mod; 
        (mul *= fact[szEven - evenInOddGroup]) %= mod;
        (ans += mul) %= mod; 
      } 
    }
    std::cout << ans << std::endl;  
  }
  return 0; 
}