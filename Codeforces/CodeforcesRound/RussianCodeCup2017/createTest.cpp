#include <bits/stdc++.h>
#include "testlib.h" 

using namespace std; 

int main (int argc, char* argv[]) {
  freopen("input.txt", "w", stdout); 
  registerGen(argc, argv, 1);
  rnd.setSeed(time(0));
  cout << 20 << endl; 
  for (int t = 1; t <= 20; t++) {
    int n = rnd.next(1, 50);
    cout << n << endl; 
    for (int i = 1; i <= n; i++) {
      cout << rnd.next(1, 1000000000) << ' '; 
    }
    cout << endl;
  }
  return 0; 
}