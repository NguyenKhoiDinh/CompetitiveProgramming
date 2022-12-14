#include <bits/stdc++.h> 

using namespace std;
const long long LIMIT = 20; 

long long ask(long long x1, long long y1, long long x2, long long y2) {
  cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl; 
  fflush(stdout); 
  long long S;
  cin >> S;
  return S; 
}

void answer(long long x1, long long y1, long long x2, long long y2) {
  cout << "! " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl; 
  fflush(stdout); 
}

int main () {
  long long S = ask(1LL, 1LL, LIMIT, LIMIT); 
  long long x1 = -1; 
  long long lo = 1, hi = LIMIT; 
  while (lo <= hi) {
    long long mid = (lo + hi) / 2; 
    long long square = ask(1, 1, mid, LIMIT); 
    if (square > 0) {
      x1 = mid; 
      hi = mid - 1; 
    }
    else {
      lo = mid + 1; 
    }
  }
  long long S1 = ask(x1, 1, x1, LIMIT); 
  long long x2 = S / S1 * x1 + x1 - 1; 
  long long y1 = -1; 
  lo = 1, hi = LIMIT;
  while (lo <= hi) {
    long long mid = (lo + hi) / 2; 
    long long square = ask(1, 1, LIMIT, mid); 
    if (square > 0) {
      y1 = mid; 
      hi = mid - 1; 
    }
    else {
      lo = mid + 1; 
    }
  }
  S1 = ask(1, y1, LIMIT, y1); 
  long long y2 = S / S1 * y1 + y1 - 1; 
  answer(x1, y1, x2, y2); 
  return 0; 
}