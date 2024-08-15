#include <iostream> 
int numTest; 
bool ok[200005];
int n;

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      ok[i] = false; 
    }
    bool ans = true;    
    for (int i = 1; i <= n; i++) {
      int seat;
      std::cin >> seat; 
      ok[seat] = true; 
      if (i == 1) {
        continue; 
      }
      if (seat == 1 && ok[2] == false) {
        ans = false;
      }
      if (seat == n && ok[n - 1] == false) {
        ans = false;
      }
      if (1 < seat && seat < n && ok[seat - 1] == false && ok[seat + 1] == false) {
        ans = false; 
      }
    }
    std::cout << (ans == true ? "YES" : "NO") << std::endl;
  }
  return 0; 
}