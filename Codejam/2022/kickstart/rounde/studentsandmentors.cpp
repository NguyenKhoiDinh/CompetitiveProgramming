#include <iostream> 
#include <map>
#include <fstream>
int numTest; 
int a[100005];
std::map <int, int> mymap;  
int n; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> n;
    mymap.clear(); 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
      mymap[a[i]]++; 
    }
    for (int i = 1; i <= n; i++) {
      std::map <int, int>::iterator it = mymap.upper_bound(2 * a[i]);
      it--;
      if (it->second == 1 && it->first == a[i]) {
        if (it == mymap.begin()) {
          std::cout << "-1 "; 
        } 
        else {
          it--;
          std::cout << it->first << ' ';
        }
      }
      else {
        std::cout << it->first << ' ';
      }
    } 
    std::cout << std::endl;
  }
  return 0; 
}