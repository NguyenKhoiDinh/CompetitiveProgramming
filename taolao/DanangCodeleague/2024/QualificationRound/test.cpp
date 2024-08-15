#include <iostream>
#include <vector> 
#include <algorithm>

int main () {
  long long a, b;
  std::cin >> a >> b; 
  long long ways = 0LL; 
  long long sum = 0LL; 
  for (long long i = a; i <= b; i++) {
    std::vector <int> v;
    long long tmp = i;
    while (tmp > 0) {
      v.push_back(tmp % 10);
      tmp /= 10; 
    }    
    std::reverse(v.begin(), v.end()); 
    int freeOpen = 0;
    bool check = true;  
    for (int i = 0; i < (int) v.size(); i++) {
      if (v[i] % 2 == 0) {
        freeOpen++; 
      }
      else {
        freeOpen--; 
      }
      if (freeOpen < 0) {
        check = false; 
        break; 
      }
    }
    if (freeOpen > 0) {
      check = false; 
    }
    if (check == true) {
      ways++; 
      sum += i * i; 
    }
  }
  std::cout << ways << "     " << sum % 1000000007LL;
  return 0; 
}