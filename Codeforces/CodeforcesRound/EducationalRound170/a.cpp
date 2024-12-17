#include <bits/stdc++.h>

using namespace std;

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    string s, t;
    cin >> s >> t;
    int ps = 0, pt = 0;
    while (ps < (int) s.size() && pt < (int) t.size() && s[ps] == t[pt]) {
      ps++;
      pt++;   
    }  
    std::cout << (ps == 0 ? -1 : ps) + 1 + (int) s.size() - ps + (int) t.size() - pt << std::endl;
  }
  return 0; 
}