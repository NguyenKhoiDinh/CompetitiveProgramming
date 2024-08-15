#include <iostream>
#include <string> 
int n, numQueries; 
std::string s[1005]; 
bool ok[26]; 

int main () {
  std::cin >> n; 
  for (int i = 1; i <= n; i++) {
    std::cin >> s[i]; 
  }
  std::string secret = s[1]; 
  for (int i = 0; i < (int) secret.size(); i++) {
    ok[secret[i] - 'a'] = true; 
  }
  std::cin >> numQueries; 
  for (int query = 1; query <= numQueries; query++) {
    std::string state;
    std::cin >> state; 
    int ans = 0; 
    for (int i = 1; i <= n; i++) {
      std::string createState = "";
      for (int j = 0; j < 5; j++) {
        if (s[i][j] == secret[j]) {
          createState += '*'; 
        }
        else if (ok[s[i][j] - 'a'] == true) {
          createState += '!'; 
        }
        else {
          createState += 'X'; 
        }
      }
      ans += (state == createState);     
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}