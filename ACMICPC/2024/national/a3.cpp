#include <iostream>
#include <algorithm>  
#include <map> 
int n, numTest;
int a[300005]; 
std::map <int, int> f; 

int main () {
  std::cin >> numTest; 
    for (int testCase = 1; testCase <= numTest; testCase++) {
        std::cin >> n;
            for (int i = 1; i <= n; i++) {
                  std::cin >> a[i];
                      }
                          std::sort(a + 1, a + n + 1); 
                              long long ans = 0LL; 
                                  a[n + 1] = -1;
                                      int numb = 1;
                                          for (int i = 2; i <= n + 1; i++) {
                                                if (a[i] != a[i - 1]) {
                                                        if (numb >= 2) {
                                                                  long long mul = numb;
                                                                            mul *= numb - 1;
                                                                                      mul /= 2; 
                                                                                                mul *= i - 1 - numb;
                                                                                                          ans += mul; 
                                                                                                                  }
                                                                                                                          if (numb >= 3) {
                                                                                                                                    long long mul = numb;
                                                                                                                                              mul *= numb - 1;
                                                                                                                                                        mul *= numb - 2;
                                                                                                                                                                  mul /= 6;
                                                                                                                                                                            ans += mul; 
                                                                                                                                                                                    }
                                                                                                                                                                                            numb = 1; 
                                                                                                                                                                                                  }
                                                                                                                                                                                                        else {
                                                                                                                                                                                                                numb++; 
                                                                                                                                                                                                                      }  
                                                                                                                                                                                                                          } 
                                                                                                                                                                                                                              std::cout << ans << std::endl;
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                  return 0; 
                                                                                                                                                                                                                                  }