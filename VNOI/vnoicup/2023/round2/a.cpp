#include <iostream> 
#include <vector>
#include <string> 

int main () {
  int n, m;
  std::cin >> n >> m;
  std::vector <std::string> a;
  a.resize(n); 
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      if (a[i][j] != a[i][j + 1] && a[i][j] != a[i + 1][j] && a[i][j + 1] != a[i + 1][j] && a[i][j + 1] == a[i + 1][j + 1]) {
        std::cout << "YES";
        return 0; 
      }
    }
  }
  std::cout << "NO";
  return 0;
}