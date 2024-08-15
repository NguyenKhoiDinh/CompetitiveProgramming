#include <iostream>
#include <vector>
std::vector <std::vector <long long> > ans = { 
{},
{},
{},
{},
{1210, 2020},
{21200},
{},
{3211000},
{42101000},
{521001000},
{6210001000}
};
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    std::cin >> n;
    if (ans[n].empty() == true) {
      std::cout << -1; 
    }
    else {
      for (int i = 0; i < (int) ans[n].size(); i++) {
        std::cout << ans[n][i] << ' '; 
      }
    }
    std::cout << std::endl;
  }
  return 0; 
}