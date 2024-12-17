#include <iostream> 
#include <set>
#include <string>
#include <math.h> 
int numTest; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, m, k;
    std::cin >> n >> m >> k; 
    std::set <std::string> S1, S2, S3; 
    for (int i = 1; i <= n; i++) {
      std::string s;
      std::cin >> s; 
      S1.insert(s); 
    }
    for (int i = 1; i <= m; i++) {
      std::string s;
      std::cin >> s;
      S2.insert(s); 
    }
    for (int i = 1; i <= k; i++) {
      std::string s;
      std::cin >> s; 
      S3.insert(s); 
    }
    if (m == n) { // all current in stage
      std::cout << std::min(n - k, 1 + k) << std::endl;     
    }
    else if (m == 0) {  // all current in workspace
      std::cout << std::min(k, 1 + n - k) << std::endl; 
    }
    else {
      int ans = 1 + n - k;
      ans = std::min(ans, 1 + k);
      int numb = 0;
      for (std::set <std::string>::iterator it = S1.begin(); it != S1.end(); it++) {
        std::string s = *it; 
        if (S2.find(s) != S2.end() && S3.find(s) != S3.end()) {
          continue; 
        }
        if (S2.find(s) != S2.end() && S3.find(s) == S3.end()) {
          numb++;   
        }
        if (S2.find(s) == S2.end() && S3.find(s) != S3.end()) {
          numb++; 
        }
      }
      ans = std::min(ans, numb);  
      std::cout << ans << std::endl;
    }
  }
  return 0; 
}