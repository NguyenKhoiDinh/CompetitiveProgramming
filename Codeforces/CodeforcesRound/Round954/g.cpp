#include <iostream>
#include <vector> 
#include <algorithm>
int p[500005]; 
int n, numTest; 
int a[500005], b[500005];      
std::vector <int> listDivisors[500005]; 
std::vector <int> deno[500005], nume[500005]; 
int cnt[500005]; 

int main () {
  for (int i = 1; i <= 500000; i++) {
    for (int j = i; j <= 500000; j += i) {
      listDivisors[j].push_back(i); 
    }
  }
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      nume[i].clear();
      deno[i].clear(); 
    }
    long long ans = 0LL; 
    for (int i = 1; i <= n; i++) {
      std::cin >> p[i]; 
      int gcd = std::__gcd(p[i], i);
      a[i] = p[i] / gcd;
      b[i] = i / gcd;
      if (b[i] == 1) {
        ans--; 
      }                               
      nume[a[i]].push_back(b[i]);
      deno[b[i]].push_back(a[i]);   
    }                    
    for (int bj = 1; bj <= n; bj++) {
      for (int ai = bj; ai <= n; ai += bj) {
        for (int i = 0; i < (int) nume[ai].size(); i++) {
          int bi = nume[ai][i]; 
          cnt[bi]++; 
        }   
      }
      for (int i = 0; i < (int) deno[bj].size(); i++) {
        int aj = deno[bj][i]; 
        for (int j = 0; j < (int) listDivisors[aj].size(); j++) {
          ans += cnt[listDivisors[aj][j]]; 
        }
      }
      for (int ai = bj; ai <= n; ai += bj) {
        for (int i = 0; i < (int) nume[ai].size(); i++) {
          int bi = nume[ai][i];
          cnt[bi]--; 
        }
      }
    }
    std::cout << ans / 2 << std::endl; 
  }
  return 0; 
}                      