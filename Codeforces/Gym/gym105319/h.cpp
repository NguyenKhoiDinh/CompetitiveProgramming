#include <iostream>
#include <math.h>
#include <vector>
int numTest; 
int a[1000005]; 
int cnt[1000005];
int cntDiv[1000005], cntMul[1000005];
bool used[1000005];  
int n;  
std::vector <int> listDivisors[1000005]; 
void erathones() {
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
  erathones(); 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
      cnt[a[i]]++;  
    }    
    for (int i = 1; i <= n; i++) {
      int x = a[i];
      if (used[x] == true) {
        continue; 
      }
      used[x] = true;  
      for (int j = 0; j < (int) listDivisors[x].size(); j++) {
        int d = listDivisors[x][j];
        cntMul[d] += cnt[x];
        cntDiv[x] += cnt[d];  
      }
    }
    int ans = n; 
    for (int i = 1; i <= n; i++) {
      int numb = cntDiv[a[i]] + cntMul[a[i]];
      int rest = n - cnt[a[i]] - numb;
      numb += 2 * rest;
      ans = std::min(ans, numb);   
    }
    std::cout << ans << std::endl;
    for (int i = 1; i <= n; i++) {
      cnt[i] = 0; 
      cntDiv[i] = 0;
      cntMul[i] = 0;
      used[i] = false; 
    }
  }
  return 0; 
}