#include <iostream>
#include <string> 
#include <stack> 
#include <algorithm> 
long long a[(1 << 16) + 10]; 
std::string s; 

int main () {
  std::ios_base::sync_with_stdio(false); 
  int numTest; 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int k;
    std::cin >> k; 
    for (int i = 0; i < (1 << k); i++) {
      std::cin >> a[i]; 
    }
    std::cin >> s; 
    std::stack <char> st; 
    for (int i = 0; i < (int) s.size(); i++) {
      if (s[i] == '0') {
        if (st.empty() == false && st.top() == '1') {
          st.pop(); 
          continue; 
        }
      }
      st.push(s[i]); 
    }
    s = "";
    while (st.empty() == false) {
      s += st.top();
      st.pop(); 
    }                           
    std::reverse(s.begin(), s.end());
    int n = 1 << k;
    int p = -1;                  
    for (int i = 0; i < (int) s.size(); i++) {
      if (s[i] == '0') {                  
        for (int j = 0; j < n / 2; j++) {
          a[j] += a[j + n / 2]; 
        }
        n /= 2;
        p = i;   
      }
      else {
        break; 
      }
    }
    int sz = n;
    for (int i = p + 1; i < (int) s.size(); i++) {
      for (int j = 0; j < sz; j++) {
        std::cout << 0 << ' '; 
      }
      sz *= 2; 
    } 
    for (int j = 0; j < n; j++) {
      std::cout << a[j] << ' '; 
    }
    std::cout << std::endl;
  }
  return 0; 
}