#include <bits/stdc++.h> 

using namespace std;

class NonbinarySearch {
  public:
  int search(int N) {
    if (N <= 2) {
      return N; 
    }
    else {
      return 1 + search((N + 2) / 2); 
    }
  }
};

NonbinarySearch N; 

int main () {
  return 0; 
}