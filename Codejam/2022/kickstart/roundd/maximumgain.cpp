#include <iostream>  
#include <math.h> 
int numTest; 
long long a[6005], b[6005];      
long long minia[6005], minib[6005];   
int n, m, k; 

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": ";
    long long total = 0LL; 
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
      total += a[i]; 
    }
    std::cin >> m;
    for (int i = 1; i <= m; i++) {
      std::cin >> b[i];
      total += b[i];  
    }
    std::cin >> k;
    k = n + m - k;
    for (int i = 1; i <= n; i++) {
      minia[i] = 1000000000000007LL; 
    }
    for (int i = 1; i <= m; i++) {
      minib[i] = 1000000000000007LL; 
    }
    for (int i = 1; i <= n; i++) {
      long long sum = 0; 
      for (int j = i; j >= 1; j--) {
        sum += a[j]; 
        minia[i - j + 1] = std::min(minia[i - j + 1], sum); 
      }
    }
    for (int i = 1; i <= m; i++) {
      long long sum = 0; 
      for (int j = i; j >= 1; j--) {
        sum += b[j]; 
        minib[i - j + 1] = std::min(minib[i - j + 1], sum); 
      }
    }
    long long mini = 1000000000000007LL;  
    for (int i = 0; i <= std::min(n, k); i++) {
      int j = k - i; 
      if (j <= m) {
        mini = std::min(mini, minia[i] + minib[j]);
      }  
    }
    std::cout << total - mini << std::endl;    
  }
  return 0; 
}