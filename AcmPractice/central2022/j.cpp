#include <iostream> 
#include <vector> 
int n, m, a, b; 
struct element {
  int x1, y1, x2, y2; 
};
std::vector <element> save; 

int main () {
  std::cin >> n >> m >> a >> b; 
  int rowa = (a - 1) / m; 
  int rowb = (b - 1) / m; 
  if (rowa == rowb) {
    std::cout << 1 << std::endl; 
    return 0; 
  }
  int firstRow = rowa; 
  int numbBalls1 = (a - 1) / m * m + m - a + 1; 
  int numbBalls2 = b - ((b - 1) / m * m);
  if ((a - 1) % m != 0) {
    save.push_back((element) {(a - 1) % m, rowa, m, rowa + 1}); 
    firstRow++; 
  }                                                  
  if (b == n || (b - 1) % m == m - 1) {
    save.push_back((element) {0, firstRow, m, rowb + 1}); 
    std::cout << (int) save.size() << std::endl;
    return 0; 
  }
  if (firstRow < rowb) {
    save.push_back((element) {0, firstRow, m, rowb}); 
  }
  save.push_back((element) {0, rowb, (b - 1) % m + 1, rowb + 1}); 
  if ((int) save.size() == 3 && (a - 1) % m != 0 && numbBalls1 + numbBalls2 == m) {
    std::cout << 2 << std::endl;
    return 0; 
  }
  std::cout << (int) save.size() << std::endl;
  return 0; 
}