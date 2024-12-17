#include <iostream>
#include <vector>
#include <string> 
#include <cstring> 
#include <math.h>
#include <map>
#include <utility> 
const int mod = 1000000007; 
std::string L, R; 
int numTest;
int f[1005][10025];
bool isPrime[10025];
std::vector <int> listPrimes; 
bool checkPrime(int p) {
  if (p == 1) {
    return false; 
  }
  for (int i = 2; i <= (int) std::sqrt(p); i++) {
    if (p % i == 0) {
      return false; 
    }
  }
  return true;               
} 
void dynamicProgramming() {
  for (int p = 2; p <= 10000; p++) {
    if (checkPrime(p) == true) {
      listPrimes.push_back(p); 
    }
  }                                                 
  f[0][0] = 1;
  for (int i = 0; i < 1000; i++) {
    for (int sum = 0; sum <= 10000; sum++) { 
      if (f[i][sum] == 0) {
        continue; 
      }
      for (int d = 0; d <= 9; d++) {
        if (d == 3) {
          continue; 
        }
        (f[i + 1][sum + d] += f[i][sum]) %= mod; 
      }
    }
  }                                 
} 
std::vector <std::pair <std::string, std::string> > save;
std::map <std::string, int> g;  
struct trieNode {
  std::vector <trieNode*> child;  
};
trieNode *root; 
trieNode *createNode() {
  trieNode *ret = new trieNode(); 
  ret->child.resize(10);
  for (int d = 0; d < 10; d++) {
    ret->child[d] = NULL; 
  }
  return ret; 
}
void addString(const std::string &s) {
  for (int i = 0; i < (int) s.size(); i++) {
    int d = (int) s.size(); 
    if (ret->child[d] == NULL) {
      ret->child[d] = createNode(); 
    }
    ret = ret->child[d]; 
  }  
}

int main () {
  std::ios_base::sync_with_stdio(false); 
  std::cin.tie(NULL); 
  dynamicProgramming();
  root = createNode();  
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> L >> R; 
    for (int i = (int) L.size() - 1; i >= 0; i--) {
      if (L[i] - '0' > 0) {
        L[i]--; 
        break; 
      }
      else {
        L[i] = '9'; 
      }
    }
    while ((int) L.size() < (int) R.size()) {
      L = "0" + L; 
    }
    addString(L); 
    addString(R); 
    save.push_back(std::make_pair(L, R));                               
  }
  for (int t = 0; t < numTest; t++) {
    std::pair <std::string, std::string> current = save[i]; 
    int ans = g[current.second]; 
    ans -= g[current.first];
    if (ans < 0) {
      ans += mod; 
    }       
    std::cout << ans << std::endl; 
  }
  return 0;                   
}