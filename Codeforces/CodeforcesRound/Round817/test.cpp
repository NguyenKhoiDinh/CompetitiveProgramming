#include <iostream> 
#include <vector>

int main () {
  std::vector <int> a = {1 4194305 4194304 100000 4294304 
 
 
};
  int s1 = 0;
  int s2 = 0; 
  for (int i = 0; i < (int) a.size(); i += 2) {
    s1 ^= a[i];
  } 

  for (int i = 1; i < (int) a.size(); i += 2) {
    s2 ^= a[i];
  } 
  std::cout << s1 << ' ' << s2;
  return 0; 
}