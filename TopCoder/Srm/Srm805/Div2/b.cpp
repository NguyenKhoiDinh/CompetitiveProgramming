#include <bits/stdc++.h> 

using namespace std; 

class CubeTower {
  public: 
  long long difference(int H, int N) {
    long long h = H; 
    long long n = N; 
    long long minCube = (long long) (n - 1) + (h - n + 1) * (h - n + 1) * (h - n + 1);
    long long d = h / n; 
    long long r = h % n; 
    long long maxCube = 0LL; 
    maxCube += r * (d + 1) * (d + 1) * (d + 1); 
    maxCube += (n - r) * d * d * d; 
    return maxCube - minCube;
  }
};

CubeTower C;

int main () {
  return 0; 
}