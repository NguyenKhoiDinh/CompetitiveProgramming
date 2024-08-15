#include <iostream>
#include <math.h>
#include <algorithm> 
#include <utility>
std::pair <long long, long long> a[300005];
int n;
long long prefix[300005], suffix[300005], prefixSum[300005], suffixSum[300005];   

int main () {
  int numTest;
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i].first;
    }
    for (int i = 0; i <= n + 1; i++) {
      prefix[i] = 0LL;
      suffix[i] = 0LL; 
      prefixSum[i] = 0LL; 
      suffixSum[i] = 0LL; 
    }
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i].second;
    }
    std::sort(a + 1, a + n + 1);
    prefixSum[0] = 0;
    for (int i = 1; i <= n; i++) {
      prefixSum[i] = prefixSum[i - 1] + a[i].second; 
    } 
    suffixSum[n + 1] = 0;
    for (int i = n; i >= 1; i--) {
      suffixSum[i] = suffixSum[i + 1] - a[i].second; 
    }
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) {
      prefix[i] = prefix[i - 1] - a[i].first * a[i].second;  
    }
    suffix[n + 1] = 0;
    for (int i = n; i >= 1; i--) {
      suffix[i] = suffix[i + 1] + a[i].first * a[i].second; 
    }
    if (prefixSum[n] < 0) {
      std::cout << "-inf" << std::endl;
      continue; 
    }
    long long ans = 1000000000000000007LL;
    for (int i = 0; i <= n; i++) {
      long long sum = prefixSum[i] + suffixSum[i + 1];
      if (sum <= 0) {
        ans = std::min(ans, sum * a[i + 1].first + prefix[i] + suffix[i + 1]);       
      }
      else {
        ans = std::min(ans, sum * a[i].first + prefix[i] + suffix[i + 1]); 
      }
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}