#include <iostream>
#include <algorithm>
#include <vector>
int numTest; 
long long cnt[1000005]; 
int a[100005];
std::vector <int> listDivisors[1000005]; 
int n; 
void init() {
  for (int i = 1; i <= 1000000; i++) {
    for (int j = 2 * i; j <= 1000000; j += i) {
      listDivisors[j].push_back(i); 
    }
  }
}
int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  init(); 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
      cnt[a[i]]++;     
    }
    std::sort(a + 1, a + n + 1); 
    std::vector <int> tmp;
    tmp.push_back(a[1]); 
    for (int i = 2; i <= n; i++) {
      if (a[i] != a[i - 1]) {
        tmp.push_back(a[i]); 
      }
    }
    for (int i = 0; i < (int) tmp.size(); i++) {
      for (int j = 0; j < (int) listDivisors[tmp[i]].size(); j++) {
        int d = listDivisors[tmp[i]][j];
        if (cnt[d] > 0) {
          cnt[d] += cnt[tmp[i]];
          cnt[tmp[i]] = 0;
          break;  
        }
      }
    }
    long long ans = 0LL; 
    for (int i = 0; i < (int) tmp.size(); i++) {
      ans += (long long) tmp[i] * cnt[tmp[i]]; 
      cnt[tmp[i]] = 0; 
    }
    std::cout << ans << std::endl; 
  } 
  return 0; 
}