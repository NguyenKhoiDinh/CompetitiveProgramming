#include <iostream>
#include <string> 
#include <vector>
#include <math.h>
int numTest; 
std::vector <int> listPosition[26];
std::string s;  
int n; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    for (int c = 0; c < 26; c++) {
      listPosition[c].clear(); 
    }
    std::cin >> s;
    for (int i = 0; i < (int) s.size(); i++) {
      listPosition[s[i] - 'a'].push_back(i + 1); 
    }
    int S = s[0] - 'a'; 
    int E = s.back() - 'a';
    int ans = std::abs(E - S); 
    int sum = 0; 
    std::vector <int> save;
    while (S < E) {
      sum += (int) listPosition[S].size();
      for (int i = 0; i < (int) listPosition[S].size(); i++) {
        save.push_back(listPosition[S][i]);
      }
      S++; 
    }
    while (S > E) {
      sum += (int) listPosition[S].size();
      for (int i = 0; i < (int) listPosition[S].size(); i++) {
        save.push_back(listPosition[S][i]);
      }
      S--; 
    }
    sum += (int) listPosition[E].size();
    for (int i = 0; i < (int) listPosition[E].size(); i++) {
      save.push_back(listPosition[E][i]);
    }
    std::cout << ans << ' ' << sum << std::endl;
    for (int i = 0; i < (int) save.size(); i++) {
      std::cout << save[i] << ' '; 
    }
    std::cout << std::endl; 
  }
  return 0; 
}