#include <iostream>
#include <map>
#include <string> 
#include <vector>
int numTest; 
std::map <std::string, int> mymap; 
int n; 
std::vector <std::string> a[3]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    mymap.clear(); 
    std::cin >> n; 
    for (int i = 0; i < 3; i++) {
      a[i].clear(); 
      std::string word; 
      for (int j = 1; j <= n; j++) {
        std::cin >> word;
        a[i].push_back(word);  
        mymap[word]++; 
      }
    }
    int ans = 0; 
    for (int i = 0; i < 3; i++) {
      int points = 0; 
      for (int j = 0; j < n; j++) {
        if (mymap[a[i][j]] == 1) {
          points += 3; 
        }
        else if (mymap[a[i][j]] == 2) {
          points += 1; 
        }
      }
      std::cout << points << ' '; 
    }                             
    std::cout << std::endl; 
  }
  return 0; 
}