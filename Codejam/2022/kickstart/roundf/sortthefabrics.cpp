#include <iostream> 
#include <string>
#include <utility>
#include <algorithm>
#include <vector>
int numTest; 
std::vector <std::pair <std::string, int> > Ada;
std::vector <std::pair <int, int> > Charles;
int n; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> n;
    Ada.clear();
    Charles.clear(); 
    for (int i = 1; i <= n; i++) {
      std::string color;
      int durability;
      int id;
      std::cin >> color >> durability >> id;
      Ada.push_back(std::make_pair(color, id));
      Charles.push_back(std::make_pair(durability, id)); 
    }
    std::sort(Ada.begin(), Ada.end());
    std::sort(Charles.begin(), Charles.end());
    int ans = 0; 
    for (int i = 0; i < n; i++) {
      if (Ada[i].second == Charles[i].second) {
        ans++; 
      }
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}