#include <iostream>
#include <map>
#include <algorithm>
#include <vector> 
int numTest; 
int n, k; 
std::map <int, std::vector <int> > f; 
int a[100005]; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k;
    f.clear(); 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
      f[a[i] % k].push_back(a[i]); 
    }
    int numbOdd = 0;  
    long long ans = 0LL; 
    for (std::map <int, std::vector <int> >::iterator it = f.begin(); it != f.end(); it++) {
      std::vector <int> &v = it->second; 
      std::sort(v.begin(), v.end()); 
      int sz = (int) v.size(); 
      if (sz % 2 == 1) {
        numbOdd++; 
      }
      std::vector <long long> prefix(sz + 2), suffix(sz + 2);
      prefix[0] = 0;
      for (int i = 2; i <= sz; i += 2) {
        prefix[i] = prefix[i - 2] + (v[i - 1] - v[i - 2]) / k; 
      }
      suffix[sz + 1] = 0; 
      for (int i = sz - 1; i >= 1; i -= 2) {
        suffix[i] = suffix[i + 2] + (v[i] - v[i - 1]) / k; 
      } 
      if (sz % 2 == 0) {
        ans += suffix[1];   
      }
      else {
        long long mini = 10000000000000007LL; 
        for (int i = 1; i <= sz; i += 2) {
          mini = std::min(mini, prefix[i - 1] + suffix[i + 1]);   
        }  
        ans += mini; 
      }
    }
    if (numbOdd > 1) {
      std::cout << -1 << std::endl;
      continue; 
    }
    else {
      std::cout << ans << std::endl;
    }
  }
  return 0; 
}