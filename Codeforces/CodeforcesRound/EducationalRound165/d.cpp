#include <iostream>
#include <math.h>
#include <utility> 
#include <vector>
#include <algorithm> 
#include <functional>
#include <queue>
int numTest; 
int a[200005], b[200005]; 
int n, k; 
std::vector <std::pair <int, int> > v; 
std::priority_queue <long long> pq; 
std::vector <long long> prefix; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    for (int i = 1; i <= n; i++) {
      std::cin >> b[i];
    }
    v.clear(); 
    for (int i = 1; i <= n; i++) {
      v.push_back(std::make_pair(b[i], a[i])); 
    }
    std::sort(v.begin(), v.end());   
    long long prefixSum = 0LL; 
    prefix.resize(n + 1, 0LL); 
    prefix[0] = 0LL;
    for (int i = 1; i <= n; i++) {
      if (v[i - 1].first >= v[i - 1].second) {
        prefixSum += v[i - 1].first - v[i - 1].second; 
      }
      prefix[i] = prefixSum; 
    }
    while (pq.empty() == false) {
      pq.pop(); 
    }
    long long suffixSum = 0LL; 
    for (int i = n; i >= n - k + 1; i--) {
      pq.push(v[i - 1].second);   
      suffixSum += v[i - 1].second; 
    }
    long long ans = 0LL; 
    for (int i = n - k + 1; i >= 1; i--) {
      ans = std::max(ans, prefix[i - 1] - suffixSum); 
      if (i >= 2 && pq.empty() == false && v[i - 2].second < pq.top()) {
        suffixSum -= pq.top(); 
        pq.pop();
        pq.push(v[i - 2].second);
        suffixSum += v[i - 2].second;   
      }                                                
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}