#include <iostream> 
#include <fstream> 
#include <algorithm> 
int numTest; 
int n; 
int a[100005]; 
 
int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": ";
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    } 
    std::sort(a + 1, a + n + 1); 
    int ans = 1; 
    for (int i = 1; i <= n; i++) {
      if (a[i] >= ans) {
        ans++; 
      }
    }
    std::cout << ans - 1 << std::endl;  
  }
  return 0; 
}