#include <iostream>
#include <string>
#include <algorithm> 

std::string add(std::string s1, std::string s2) {
  while ((int) s1.size() < (int) s2.size()) {
    s1 = "0" + s1; 
  }
  while ((int) s2.size() < (int) s1.size()) {
    s2 = "0" + s2; 
  }
  std::string ret = "";
  int rem = 0; 
  for (int i = (int) s1.size() - 1; i >= 0; i--) {
    int v1 = s1[i] - '0';
    int v2 = s2[i] - '0';
    int last = (v1 + v2 + rem) % 10;
    ret += (char) (last + '0'); 
    rem = (v1 + v2 + rem) / 10; 
  }
  if (rem == 1) {
    ret += '1'; 
  }
  std::reverse(ret.begin(), ret.end());
  return ret; 
}

int p, q; 

std::string solve(int p, int q) {
  if (p == q) {
    return "0"; 
  }
  else if (q < p) {
    std::string ret = solve(p - q, q);
    ret = add(ret, ret);
    ret = add(ret, "2");
    return ret;   
  }
  else {
    std::string ret = solve(p, q - p);
    ret = add(ret, ret);
    ret = add(ret, "1"); 
    return ret; 
  }
}

int main () {
  while (std::cin >> p >> q) {
    std::cout << solve(p, q) << std::endl;
  }
  return 0; 
}