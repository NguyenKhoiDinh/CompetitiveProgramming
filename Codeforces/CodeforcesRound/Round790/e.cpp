#include <iostream> 
#include <vector> 
#include <utility> 
#include <algorithm> 
int numTest; 
int a[150005], ans[150005]; 
std::vector<std::pair <int, int> > listQuery; 
int n, numQuery; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> numQuery;
    std::vector <int> sum;
    listQuery.clear(); 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    std::sort(a + 1, a + n + 1); 
    int totalSum = 0; 
    for (int i = n; i >= 1; i--) {
      totalSum += a[i];
      sum.push_back(totalSum);   
    }
    for (int i = 1; i <= numQuery; i++) {
      std::pair <int, int> query; 
      std::cin >> query.first;
      query.second = i; 
      listQuery.push_back(query); 
    }  
    std::sort(listQuery.begin(), listQuery.end()); 
    int p = 0; 
    for (int i = 0; i < numQuery; i++) {
      while (p < n && sum[p] < listQuery[i].first) {
        p++; 
      }  
      if (p < n) {
        ans[listQuery[i].second] = p + 1; 
      }
      else {
        ans[listQuery[i].second] = -1; 
      }
    }
    for (int i = 1; i <= numQuery; i++) {
      std::cout << ans[i] << std::endl; 
    }                                  
  }
  return 0; 
}