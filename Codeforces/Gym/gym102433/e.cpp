#include <iostream>
#include <string> 
const long long mod = 11092019LL; 
long long freq[26]; 
std::string s; 

int main () {
  std::cin >> s;
  for (int i = 0; i < (int) s.size(); i++) {
    freq[s[i] - 'a']++; 
  }
  long long ans = 1LL; 
  for (int ch = 0; ch < 26; ch++) {
    (ans *= freq[ch] + 1) %= mod; 
  }
  std::cout << ans;
  return 0;   
}