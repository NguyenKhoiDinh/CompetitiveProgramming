#include <iostream>
#include <string> 
const int smalls[6] = {0, 1, 3, 4, 2, 3};
const std::string sms[6] = {"", "1", "01", "001", "0001", "01001"};
int numTest; 

void solve(){
  std::string s[25];
  s[6] = "101001";
  s[7] = "0010110";
  s[8] = "01101001";
  s[9] = "011100110";
  s[10] = "0111000101";
  s[11] = "10111000101";
  s[12] = "010111000101";
  s[13] = "0000000110110";
  s[14] = "11111100011001";
  s[15] = "111111010100110";
  s[16] = "1111011100011001";
  s[17] = "11111111000100011";
  int n, orn;
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n; 
    long long sum = 0LL;
    for (int i = 1; i <= n; i++) {
      sum += 1LL * i * i; 
    }
    if (sum % 2 == 1) {
      std::cout << "NO" << std::endl;
      continue; 
    }
    orn = n; 
    if (n <= 5) {
      std::cout << "NO" << std::endl;
      continue;  
    }
    int rem = n % 12; 
    std::string ans; 
    if (rem > 5) {
      ans = s[rem]; 
      n -= rem; 
    }
    else {
      rem = 12 + rem; 
      ans = s[rem];
      n -= rem;
    }
    while (n > 0) {
      ans += s[12];
      n -= 12; 
    }
    long long res;
    n = orn; 
    if (n % 4 == 0 || n % 4 == 3) {
      res = 0LL; 
    }
    else {
      res = 1LL; 
    }
    if (res == 1) {
      std::cout << "NO" << std::endl; 
      continue; 
    }
    else {
      std::cout << "YES" << std::endl;
      for (int i = 0; i < (int) ans.size(); i++) {
        std::cout << ans[i] << ' '; 
      } 
      std::cout << std::endl;
      continue; 
    }
  } 
}

int main () {
  solve(); 
  return 0; 
}
