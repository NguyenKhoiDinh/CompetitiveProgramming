#include <iostream>
#include <vector>  
int numTest; 
int n;
bool visited[200005];  
int a[200005]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
      visited[i] = false; 
    }
    std::vector <int> ans; 
    for (int i = 1; i <= n; i++) {
      if (visited[a[i]] == false) {
        ans.push_back(a[i]); 
        visited[a[i]] = true; 
      }
    }
    for (int i = 0; i < (int) ans.size(); i++) {
      std::cout << ans[i] << ' '; 
    }
    for (int i = 1; i <= n; i++) {
      if (visited[i] == false) {
        std::cout << i << ' ';
      }
    }
    std::cout << std::endl;
  }
  return 0; 
}