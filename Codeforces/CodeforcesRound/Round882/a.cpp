#include <iostream>
#include <queue>
#include <vector>
#include <functional> 
#include <math.h> 
int numTest; 
int a[105]; 
int n, k; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    std::priority_queue <int> pq; 
    int sum = 0; 
    for (int i = 2; i <= n; i++) {
      sum += std::abs(a[i] - a[i - 1]); 
      pq.push(std::abs(a[i] - a[i - 1])); 
    }
    for (int i = 1; i < k; i++) {
      sum -= pq.top();
      pq.pop(); 
    }
    std::cout << sum << std::endl;
  }
  return 0; 
}