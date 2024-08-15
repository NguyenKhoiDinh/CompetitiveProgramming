#include <iostream>
#include <vector>    
#include <queue>
#include <stack> 
int numTest;
int n, k;
long long S, c1, c2, mod; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k >> S >> c1 >> c2 >> mod; 
    c1 %= mod;
    c2 %= mod; 
    std::priority_queue <long long> pq; 
    pq.push(S); 
    long long prev = S; 
    for (int i = 2; i <= n; i++) {
      long long cur = (prev * c1 + c2) % mod; 
      if ((int) pq.size() < k) {
        pq.push(cur); 
      }
      else {
        if (pq.top() > cur) {
          pq.pop();
          pq.push(cur); 
        }
      }
      prev = cur; 
    }
    std::stack <long long> ans; 
    while (pq.empty() == false) {
      ans.push(pq.top()); 
      pq.pop();    
    }
    while (ans.empty() == false) {
      std::cout << ans.top() << ' ';
      ans.pop();
    }
    std::cout << std::endl;
  }
  return 0; 
}