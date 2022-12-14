#include <iostream> 
int a[1000005]; 
int cnt[2000005], mul_cnt[2000005]; 
int n; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
    cnt[a[i]]++; 
  }            
  for (int v = 1; v <= 1000000; v++) {
    for (int j = v; j <= 1000000; j += v) {
      mul_cnt[v] += cnt[j]; 
    }
  }
  long long ans = 0LL; 
  for (int i = 1; i <= n; i++) {
    int v = a[i]; 
    long long numb = mul_cnt[2 * v];
    std::cout << 1LL * numb * (numb - 1) / 2 << ' ';  
  }
  return 0; 
}