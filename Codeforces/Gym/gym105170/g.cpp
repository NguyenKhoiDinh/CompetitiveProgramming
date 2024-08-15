#include <iostream>
#include <algorithm>
struct element {
  int y, l, r; 
  bool operator < (const element &other) {
    return (y > other.y || (y == other.y && l < other.l)); 
  }
};
element a[200005]; 
int n, numTest; 
int startx, starty; 

int main () {
  
  return 0; 
}