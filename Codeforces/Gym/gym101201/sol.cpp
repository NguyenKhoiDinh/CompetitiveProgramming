#include <iostream>
#include <math.h>

using namespace std;

int N;
long long sum = 0;

int main () {
  cin >> N;
  for (int i = 1; i <= (int) sqrt(N); i++) {
    if (N % i == 0) {
      sum += i;
      int b = N / i;
      if (b != i) {
        sum += b;
      }
    }
  }
  cout << sum;
  return 0;
}