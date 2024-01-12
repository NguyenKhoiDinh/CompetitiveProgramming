#include <bits/stdc++.h>
#include "testlib.h" 

using namespace std; 

int main (int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  rnd.setSeed(time(0));
  freopen("copyarray.inp", "w", stdout); 
  int n = rnd.next(1, 100000);
  int numQueries = rnd.next(1, 100000); 
  std::cout << n << ' ' << numQueries << std::endl;
  for (int i = 1; i <= n; i++) {
    std::cout << rnd.next(1, 1000000000) << ' '; 
  } 
  std::cout << std::endl; 
  for (int query = 1; query <= numQueries; query++) {
    int type = rnd.next(1, 2); 
    int id = rnd.next(0, query - 1); 
    int value = rnd.next(1, 1000000000); 
    std::cout << type << ' ' << id << ' ' << value << std::endl;
  }
  return 0; 
}