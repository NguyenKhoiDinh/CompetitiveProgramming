#include <iostream> 
#include <string> 
std::string s, t; 
int lastPosition[26]; 

int main () {
  std::cin >> s >> t;
  for (int ch = 0; ch < 26; ch++) {
    lastPosition[ch] = -1;
  }
  for (int i = (int) t.size() - 2; i >= 0; i--) {
    if (lastPosition[t[i] - 'a'] == -1) {
      lastPosition[t[i] - 'a'] = i;
    }
  }
  int minLength = 1000000007;
  int ps = -1;
  int pt = -1;  
  for (int i = 1; i < (int) s.size(); i++) {
    if (lastPosition[s[i] - 'a'] != -1) {
      if (minLength > i + (int) t.size() - lastPosition[s[i] - 'a']) {
        minLength = i + (int) t.size() - lastPosition[s[i] - 'a'];
        ps = i;
        pt = lastPosition[s[i] - 'a']; 
      }  
    }
  }
  if (ps == -1 && pt == -1) {
    std::cout << -1; 
    return 0;
  }
  for (int i = 0; i <= ps; i++) {
    std::cout << s[i]; 
  } 
  for (int i = pt + 1; i < (int) t.size(); i++) {
    std::cout << t[i];
  }
  return 0; 
} 