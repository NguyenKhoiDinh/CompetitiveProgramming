#include <iostream> 
#include <string> 
int numTest; 
int n, k; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k; 
    if (k == 1) {
      std::cout << "Alice" << std::endl; 
      fflush(stdout); 
      std::cout << "move " << n << ' ' << 1 << std::endl;
      fflush(stdout); 
      std::string cmd; 
      std::cin >> cmd; 
      if (cmd == "end") {
        int x, y;
        std::cin >> x >> y;
        if (x == -1 && y == -1) {
          continue; 
        }
        else {
          return 0; 
        }
      }
    }
    if (k == 2) {
      bool isAlice = true; 
      if (n % 2 == 0) {
        std::cout << "Bob" << std::endl; 
        isAlice = false; 
      }
      else {
        std::cout << "Alice" << std::endl; 
      }
      fflush(stdout);
      int firstMarble = n - 1, secondMarble = n; 
      int nextPlace = n - 2; 
      int nextMarble = n; 
      while (true) {
        if (isAlice == false) {
          std::string cmd; 
          std::cin >> cmd; 
          if (cmd == "end") {
            int x, y;
            std::cin >> x >> y;
            if (x == -1 && y == -1) {
              break; 
            }
            else {
              return 0; 
            } 
          }
          else if (cmd == "invalid") {
            return 0; 
          }
          else {
            int x, y;
            std::cin >> x >> y; 
            if (firstMarble == x) {
              firstMarble = y;
              nextMarble = secondMarble;
              if (y == 1 || y == 2) {
                nextPlace = 3 - y; 
              } 
              else if (y % 2 == 0) {
                nextPlace = y - 1;   
              }
              else {
                nextPlace = y + 1; 
              }
            }
            else {
              secondMarble = y;
              nextMarble = firstMarble;
              if (y == 1 || y == 2) {
                nextPlace = 3 - y; 
              }
              else if (y % 2 == 0) {
                nextPlace = y - 1; 
              } 
              else {
                nextPlace = y + 1; 
              }
            }
          }
        }
        else {
          std::cout << "move " << nextMarble << ' ' << nextPlace << std::endl;
          if (nextMarble == firstMarble) {
            firstMarble = nextPlace; 
          }
          else {
            secondMarble = nextPlace;
          }
          fflush(stdout);   
        }
        isAlice = !isAlice; 
      } 
    }
  }
  return 0; 
}