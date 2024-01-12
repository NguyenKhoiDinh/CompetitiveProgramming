#include <iostream>
#include <string>
std::string a[105]; 
int n, m; 

int main () {
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i]; 
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m - 2; j++) {
      if (a[i][j] == '.' && a[i][j + 1] == '.' && a[i][j + 2] == '.') {
        std::cout << i + 1 << ' ' << j + 1;
        return 0; 
      }
    }
  }
  return 0; 
}