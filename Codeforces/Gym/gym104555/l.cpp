#include <iostream>
#include <string>
#include <vector> 
#include <algorithm> 
std::string s; 
int k; 
std::vector <char> pos[100005]; 

int main () {
  std::cin >> s;
  std::cin >> k; 
  int n = (int) s.size(); 
  for (int i = 0; i < n; i++) {
    pos[i % k].push_back(s[i]);     
  }
  for (int i = 0; i < k; i++) {
    std::sort(pos[i].begin(), pos[i].end()); 
    std::reverse(pos[i].begin(), pos[i].end()); 
  }
  for (int i = 0; i < n; i++) {
    std::cout << pos[i % k].back();
    pos[i % k].pop_back(); 
  }
  return 0; 
}