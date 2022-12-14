#include <bits/stdc++.h> 

using namespace std;
const int LIM = 1000000;
int n; 

long long ask(int x, int y) {
  cout << x << ' ' << y << endl;
  fflush(stdout); 
  long long distance;
  cin >> distance;
  return distance; 
}

bool isSquare(long long n) {
  long long x = (long long) sqrt(n); 
  return (x * x == n);
}

void process() {
  long long distance = ask(0, 0);
  if (distance == 0) {
    return;
  }  
  for (long long x = 0; x * x <= distance; x++) {
    if (isSquare(distance - x * x) == true) {
      long long y = (long long) sqrt(distance - x * x);
      if (x <= LIM && y <= LIM && ask(x, y) == 0) {
        return; 
      }
    }
  }
}

int main () {
  cin >> n;
  for (int ball = 1; ball <= n; ball++) {
    process();
  }
  return 0;
}