#include <iostream>
#include <algorithm>
#include <vector> 
#include <string> 
std::vector <int> v;
std::vector <std::string> ans[11];
void check(const std::vector <int> &v, int lim) {
  std::vector <int> freq(10, 0); 
  for (int i = 0; i < (int) v.size(); i++) {
    freq[v[i]]++; 
  }               
  for (int i = 0; i < (int) v.size(); i++) {
    if (v[i] != freq[i]) {
      return;  
    }
  }
  std::string ret = ""; 
  for (int i = 0; i < (int) v.size(); i++) {
    ret += (char) (v[i] + '0'); 
  }
  ans[lim].push_back(ret); 
} 

void backTrack(int pos, int lim) {
  for (int dig = 0; dig < std::min(lim - 1, 7); dig++) {
    v.push_back(dig);
    if (pos + 1 == lim) {
      check(v, lim);       
    }
    else {
      backTrack(pos + 1, lim); 
    } 
    v.pop_back();
  }
} 

int main () {
  freopen("output.txt", "w", stdout);
  for (int i = 1; i <= 10; i++) {
    v.clear();
    backTrack(0, i);
    std::cerr << i << "  DONE!!!!" << std::endl; 
  }
  for (int i = 1; i <= 10; i++) {
    std::cout << "ans[" << i << "] = {";
    for (int j = 0; j < (int) ans[i].size(); j++) {
      std::cout << ans[i][j];
      if (j < (int) ans[i].size() - 1) {
        std::cout << ", "; 
      }
    }
    std::cout << "};" << std::endl; 
  } 
  return 0; 
}