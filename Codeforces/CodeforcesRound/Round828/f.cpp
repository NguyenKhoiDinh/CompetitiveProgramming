#include <iostream> 
#include <math.h> 
int numTest; 
int n; 
int a[200005]; 
int position[200005];

long long sum(long long n) {
  return n * (n + 1) / 2; 
} 

long long calc(int lim1, int lim2, int total) {
  long long ret = 0LL; 
  int rest = total - lim2; 
  if (lim1 <= rest) {
    ret = 1LL * (lim1 + 1) * (lim2 + 1); 
  }
  else {
    ret += 1LL * (rest + 1) * (lim2 + 1); 
    lim1 -= rest;              
    lim1--; 
    ret += 1LL * (lim1 + 1) * lim2; 
    ret -= 1LL * lim1 * (lim1 + 1) / 2; 
  }
  return ret; 
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
      position[a[i]] = i;  
    }
    long long ans = 0LL;
    int l = n + 1;
    int r = -1;  
    int mex = 1; 
    do {
      int pos = position[mex - 1]; 
      l = std::min(l, pos);
      r = std::max(r, pos);
      while (l <= position[mex] && position[mex] <= r) {
        mex++; 
      }
      int rest = r - l + 1 - mex; 
      if (rest <= mex) {
        int numbAdd = mex - rest;
        int limLeft = std::min(l - 1, numbAdd); 
        int limRight = std::min(n - r, numbAdd); 
        if (mex < n) {
          if (position[mex] < l) {
            limLeft = std::min(l - 1 - position[mex], numbAdd); 
          }
          else if (position[mex] > r) {
            limRight = std::min(position[mex] - 1 - r, numbAdd); 
          }
        }                                                                                                                            
        ans += calc(limLeft, limRight, numbAdd);  
      }
      mex++;
    }
    while (mex <= n); 
    std::cout << ans << std::endl;                                                        
  }
  return 0; 
}