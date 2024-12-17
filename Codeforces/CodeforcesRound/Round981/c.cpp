#include <iostream> 
int n;
int a[100005]; 

int main () {
  int numTest;
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    int ans = 0; 
    int l = 1; 
    int r = n; 
    while (l <= r) {
      int nxtl = l + 1; 
      int nxtr = r - 1; 
      if (nxtl <= nxtr) {
        ans += std::min((a[l] == a[nxtl]) + (a[r] == a[nxtr]), (a[l] == a[nxtr]) + (a[r] == a[nxtl]));   
      }
      if (l + 1 == r) {
        ans += (a[l] == a[r]); 
      }
      l++;
      r--; 
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}


                
