#include <iostream>
#include <vector> 
#include <string> 
int numTest; 
std::vector <int> listDivisors[200005]; 
void erathones() {
  for (int i = 1; i <= 200000; i++) {
    for (int j = i; j <= 200000; j += i) {
      listDivisors[j].push_back(i); 
    }
  }
}

int main () {
  erathones(); 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::string s;
    int n; 
    std::cin >> n >> s; 
    for (int i = 0; i < (int) listDivisors[n].size(); i++) {
      int total = 0; 
      int d = listDivisors[n][i];
      for (int j = 0; j < d; j++) {
        std::vector <int> cnt(26, 0); 
        for (int k = j; k < n; k += d) {
          cnt[s[k] - 'a']++;    
        }
        int maxi = -1; 
        for (int ch = 0; ch < 26; ch++) {
          if (cnt[ch] > 0) {
            if (maxi < cnt[ch]) {
              maxi = cnt[ch]; 
            }
          }
        }
        total += n / d - maxi;   
      }
      if (total <= 1) {
        std::cout << d << std::endl;
        break; 
      } 
    }
  }
  return 0; 
}