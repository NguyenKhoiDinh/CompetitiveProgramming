#include <iostream>
#include <string> 
#include <algorithm>
int numTest; 
int ind[100005];
std::string s, st;
int n, m; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m;
    std::cin >> s;
    for (int i = 1; i <= m; i++) {
      std::cin >> ind[i]; 
    } 
    std::sort(ind + 1, ind + m + 1);
    std::cin >> st;
    std::sort(st.begin(), st.end());
    int p = 0;
    s[ind[1] - 1] = st[p];
    p++;
    for (int i = 2; i <= m; i++) {
      if (ind[i] != ind[i - 1]) {
        s[ind[i] - 1] = st[p]; 
        p++; 
      }
    }  
    std::cout << s << std::endl;
  }
  return 0; 
}