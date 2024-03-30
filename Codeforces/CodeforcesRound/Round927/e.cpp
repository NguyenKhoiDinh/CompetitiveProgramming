#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
int numTest; 
int n;
std::string s; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {                  
    std::cin >> n >> s;
    std::string st = ""; 
    int p = 0; 
    while (p < n && s[p] == '0') {
      p++; 
    } 
    if (p < n) {
      for (int i = p; i < n; i++) {
        st += s[i]; 
      }
    }
    s = st; 
    n = (int) s.size();
    std::vector <int> ans; 
    int rem = 0;
    int sum = 0; 
    for (int i = 0; i < n; i++) {
      sum += s[i] - '0'; 
    }
    for (int i = n - 1; i >= 0; i--) {
      ans.push_back((sum + rem) % 10);
      rem = (sum + rem) / 10;
      sum -= s[i] - '0';   
    }            
    while (rem > 0) {
      ans.push_back(rem % 10); 
      rem /= 10; 
    }
    std::reverse(ans.begin(), ans.end()); 
    for (int i = 0; i < (int) ans.size(); i++) {
      std::cout << ans[i];
    }
    std::cout << std::endl; 
  }
  return 0; 
}