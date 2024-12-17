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
            f.clear();
                for (int i = 1; i <= n; i++) {
                      std::cin >> a[i];
                            f[a[i]]++;  
                                }
                                    long long ans = 0LL; 
                                        for (std::map <int, int>::iterator it = f.begin(); it != f.end(); it++) {
                                              int numb = it->second; 
                                                    if (numb >= 2) {
                                                            long long mul = numb;
                                                                    mul *= numb - 1;
                                                                            mul /= 2;
                                                                                    mul *= n - 2;  
                                                                                            ans += mul;
                                                                                                  }
                                                                                                      }
                                                                                                          std::cout << ans << std::endl;
                                                                                                            }
                                                                                                              return 0; 
                                                                                                              }