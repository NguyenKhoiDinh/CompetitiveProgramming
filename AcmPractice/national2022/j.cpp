#include <iostream>
int a[1005][1005];
int main () {
  int numTest;
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, m, cnt = 0; 
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        std::cin >> a[i][j];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int value = a[i][j];
        bool check = true;
        for (int k = 0; k < m; k++){
          if (value != a[i][k]){
            check = false;
            break;
          }
        }
        if (check == true) {
          for (int k = 0; k < n; k++) {
            if (value != a[k][j]) {
              check = false;
              break;
            }
          }
        }
        if (check == true) {
          cnt++;
        }
      }
    }
    std::cout << cnt << std::endl;
  }
  return 0; 
}
