#include <iostream> 
int numTest; 
int calc(int a1, int a2, int b1, int b2) {
  int ret = 0;
  if (a1 > b1) {
    ret++; 
  } 
  else if (a1 < b1) {
    ret--; 
  }
  if (a2 > b2) {
    ret++; 
  }
  else if (a2 < b2) {
    ret--; 
  }
  return (ret > 0); 
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int a1, a2, b1, b2;
    std::cin >> a1 >> a2 >> b1 >> b2;
    int ans = 0;
    ans += calc(a1, a2, b1, b2);
    ans += calc(a1, a2, b2, b1);
    ans += calc(a2, a1, b1, b2);
    ans += calc(a2, a1, b2, b1);
    std::cout << ans << std::endl;    
  }
  return 0; 
}