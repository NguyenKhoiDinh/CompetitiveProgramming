#include <iostream>
#include <math.h> 
#include <algorithm> 
int numTest; 
int e[300005], G; 
int n; 

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout); 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> n >> G;
    for (int i = 1; i <= n; i++) {
      std::cin >> e[i]; 
    }
    std::sort(e + 1, e + n + 1); 
    std::reverse(e + 1, e + n + 1);
    int mini = 1000000007;
    int ans;  
    for (int i = 1; i <= n; i++) {
      if (mini > std::abs(G - e[i])) {
        mini = std::abs(G - e[i]); 
        ans = i; 
      }
    }
    std::cout << ans << ' ' << mini << std::endl;
  }
  return 0; 
}
