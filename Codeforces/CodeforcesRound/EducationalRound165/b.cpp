#include <iostream>
#include <string>
#include <deque>
int numTest; 
std::string s; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> s; 
    int n = (int) s.size(); 
    std::deque <int> pos0, pos1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        pos0.push_back(i); 
      }
      else {
        pos1.push_back(i);
      }
    }
    long long ans = 0LL; 
    if (pos0.empty() == true || pos1.empty() == true) {
      std::cout << 0 << std::endl;
      continue; 
    }
    while (true) {
      while (pos0.empty() == false && pos0.front() < pos1.front()) {
        pos0.pop_front(); 
      }
      if (pos0.empty() == true) {
        break; 
      }
      ans += pos0.front() - pos1.front() + 1;
      pos0.pop_front();
      if (pos0.empty() == true) {
        break; 
      }
      pos1.front()++;  
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}