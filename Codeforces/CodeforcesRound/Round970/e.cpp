#include <iostream> 
#include <vector> 
#include <string> 
#include <math.h> 
int numTest; 
int n;
std::string s;
int prefix_odd[200005][26], prefix_even[200005][26], suffix_odd[200005][26], suffix_even[200005][26];  

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    std::cin >> s; 
    if (n % 2 == 0) {
      std::vector <int> cnt_odd(26, 0), cnt_even(26, 0);
      for (int i = 0; i < n; i += 2) {
        cnt_even[s[i] - 'a']++; 
      }
      for (int i = 1; i < n; i += 2) {
        cnt_odd[s[i] - 'a']++; 
      }
      int ans = n + 5; 
      for (int c1 = 0; c1 < 26; c1++) {
        for (int c2 = 0; c2 < 26; c2++) {
          ans = std::min(ans, n - cnt_odd[c1] - cnt_even[c2]);   
        }
      }
      std::cout << ans << std::endl; 
    }
    else {
      for (int c = 0; c < 26; c++) {
        prefix_odd[0][c] = 0; 
        prefix_even[0][c] = 0;
        suffix_odd[n + 1][c] = 0;
        suffix_even[n + 1][c] = 0;  
      }  
      for (int i = 1; i <= n; i++) {
        for (int c = 0; c < 26; c++) {
          prefix_odd[i][c] = prefix_odd[i - 1][c];
          prefix_even[i][c] = prefix_even[i - 1][c];
        }
        if (i % 2 == 1) {
          prefix_odd[i][s[i - 1] - 'a']++; 
        } 
        else {
          prefix_even[i][s[i - 1] - 'a']++; 
        }
      }
      for (int i = n; i >= 1; i--) {
        for (int c = 0; c < 26; c++) {
          suffix_odd[i][c] = suffix_odd[i + 1][c];
          suffix_even[i][c] = suffix_even[i + 1][c];
        }
        if (i % 2 == 1) {
          suffix_odd[i][s[i - 1] - 'a']++; 
        } 
        else {
          suffix_even[i][s[i - 1] - 'a']++; 
        }
      }
      int ans = n + 5; 
      for (int i = 1; i <= n; i++) {
        for (int c1 = 0; c1 < 26; c1++) {
          for (int c2 = 0; c2 < 26; c2++) {
            ans = std::min(ans, n - prefix_odd[i - 1][c1] - suffix_even[i + 1][c1] - prefix_even[i - 1][c2] - suffix_odd[i + 1][c2]);   
          }
        }
      }
      std::cout << ans << std::endl;
    }
  }
  return 0; 
}