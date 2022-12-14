#include <iostream> 
#include <vector>
int numTest;
struct Point {
  int X, Y; 
  Point() {
    X = 0;
    Y = 0;
  }
}; 
int Rs, Rh; 

int distance(const Point &p) {
  return p.X * p.X + p.Y * p.Y; 
}

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> Rs >> Rh;
    std::vector <Point> red, yellow; 
    int n;
    std::cin >> n;
    red.resize(n); 
    for (int i = 0; i < n; i++) {
      std::cin >> red[i].X >> red[i].Y; 
    }
    int m;
    std::cin >> m;
    yellow.resize(m); 
    for (int i = 0; i < m; i++) {
      std::cin >> yellow[i].X >> yellow[i].Y; 
    }
    int numRed = 0;
    int numYellow = 0; 
    for (int i = 0; i < n; i++) {
      if (distance(red[i]) > Rs * Rs + 2 * Rs * Rh + Rh * Rh) {
        continue; 
      }
      bool check = true; 
      for (int j = 0; j < m; j++) {
        if (distance(yellow[j]) < distance(red[i])) {
          check = false; 
          break; 
        }
      }
      if (check == true) {
        numRed++; 
      }
    }
    for (int j = 0; j < m; j++) {
      if (distance(yellow[j]) > Rs * Rs + 2 * Rs * Rh + Rh * Rh) {
        continue; 
      }
      bool check = true; 
      for (int i = 0; i < n; i++) {
        if (distance(red[i]) < distance(yellow[j])) {
          check = false;
          break; 
        }  
      }
      if (check == true) {
        numYellow++; 
      }
    }
    std::cout << numRed << ' ' << numYellow << std::endl;
  }
  return 0; 
}