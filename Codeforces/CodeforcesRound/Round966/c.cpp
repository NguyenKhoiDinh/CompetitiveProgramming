#include <iostream> 
#include <map>
#include <string> 
int numTest; 
int n;
int a[200005]; 
int numQueries; 
int value[26]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n; 
    for (int i = 0; i < n; i++) {
      std::cin >> a[i]; 
    }
    std::cin >> numQueries; 
    for (int query = 1; query <= numQueries; query++) {
      std::string s; 
      std::cin >> s; 
      const int inf = 1000000007;
      for (int ch = 0; ch < 26; ch++) {
        value[ch] = inf; 
      }
      std::map <int, char> id;
      if ((int) s.size() != n) {
        std::cout << "NO" << std::endl;
        continue; 
      }  
      int p = 0;
      while (p < n) {
        if (value[s[p] - 'a'] == inf && id.find(a[p]) == id.end()) {
          value[s[p] - 'a'] = a[p];
          id[a[p]] = s[p];  
          p++; 
          continue; 
        }  
        if (value[s[p] - 'a'] != inf) {
          if (id.find(a[p]) == id.end() || id[a[p]] != s[p]) {
            break; 
          }
        }
        if (id.find(a[p]) != id.end()) {
          if (value[s[p] - 'a'] == inf || a[p] != value[s[p] - 'a']) {
            break; 
          }
        }
        p++; 
      }
      std::cout << (p == n ? "YES" : "NO") << std::endl;
    }
  }
  return 0; 
}