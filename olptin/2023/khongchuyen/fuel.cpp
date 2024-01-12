#include <iostream>
#include <math.h> 
#include <stack>
int n, m, numQueries; 
int v[100005], h[100005]; 
std::stack <int> mystack; 
long long prefixSum[100005], suffixSum[100005]; 
long long prefixF[100005], suffixF[100005]; 

int main () {
  std::cin >> n >> m; 
  for (int i = 1; i <= n; i++) {
    std::cin >> v[i]; 
  }
  v[0] = 0;
  v[n + 1] = m; 
  for (int i = 1; i <= n; i++) {
    std::cin >> h[i]; 
  }
  h[0] = 100005;
  h[n + 1] = 100005;
  for (int i = 1; i <= n; i++) {
    prefixSum[i] = prefixSum[i - 1] + h[i]; 
  } 
  for (int i = n; i >= 1; i--) {
    suffixSum[i] = suffixSum[i + 1] + h[i]; 
  }
  mystack.push(0); 
  for (int i = 1; i <= n; i++) {
    while (mystack.empty() == false && h[mystack.top()] < h[i]) {
      mystack.pop(); 
    }
    prefixF[i] = prefixF[mystack.top()] + (long long) (v[i] - v[mystack.top()] - 1) * h[i] - (prefixSum[i - 1] - prefixSum[mystack.top()]); 
    mystack.push(i); 
  }
  while (mystack.empty() == false) {
    mystack.pop(); 
  }
  mystack.push(n + 1); 
  for (int i = n; i >= 1; i--) {
    while (mystack.empty() == false && h[mystack.top()] < h[i]) {
      mystack.pop(); 
    }                
    suffixF[i] = suffixF[mystack.top()] + (long long) (v[mystack.top()] - v[i] - 1) * h[i] - (suffixSum[i + 1] - suffixSum[mystack.top()]); 
    mystack.push(i); 
  }
  std::cin >> numQueries; 
  for (int query = 1; query <= numQueries; query++) {
    long long K; 
    std::cin >> K; 
    int maxLeft = 0; 
    int lo = 0; 
    int hi = n; 
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (prefixF[mid] < K) {
        maxLeft = mid; 
        lo = mid + 1; 
      } 
      else {
        hi = mid - 1; 
      }
    }
    int minRight = n + 1; 
    lo = maxLeft + 1; 
    hi = n + 1; 
    while (lo <= hi) {
      int mid = (lo + hi) / 2; 
      if (suffixF[mid] < K) {
        minRight = mid; 
        hi = mid - 1; 
      }
      else {
        lo = mid + 1; 
      }
    }
    std::cout << maxLeft + n + 1 - minRight << std::endl;
  }
  return 0;                                                                                  
}