#include <iostream>
#include <math.h>
#include <string> 
#include <algorithm>
#include <vector>
std::string s; 
int n, numQueries; 
int cnt[26][1000005];

int main () {
  std::cin >> n >> numQueries; 
  std::cin >> s; 
  for (int i = 0; i < n; i++) {
    cnt[s[i] - 'a'][i + 1]++; 
  }
  for (int c = 0; c < 26; c++) {
    for (int i = 1; i <= n; i++) {
      cnt[c][i] += cnt[c][i - 1]; 
    }
  }
  for (int query = 1; query <= numQueries; query++) {
    int l, r;
    std::cin >> l >> r; 
    l++;
    r++;          
    int numb = 0; 
    for (int c = 0; c < 26; c++) {
      if ((cnt[c][r] - cnt[c][l - 1]) % 2 == 1) {
        numb++; 
      }  
    } 
    std::cout << numb / 2 << std::endl;
  }
  return 0; 
}