#include <bits/stdc++.h> 

using namespace std;

class HouseOfCards {
  public:
  long long count(int N) { 
    return 3LL * N * (N + 1) / 2 - N;  
  }
};

HouseOfCards H;

int main () {
  cout << H.count(4);
  return 0; 
}