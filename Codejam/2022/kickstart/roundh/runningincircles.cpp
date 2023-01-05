#include <iostream> 
int numTest; 

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    int length, n;
    std::cin >> length >> n;
    char currentDirection = '.'; 
    int currentDistance = 0; 
    long long ans = 0; 
    for (int i = 1; i <= n; i++) {
      int distance; 
      char direction;
      std::cin >> distance >> direction; 
      if (currentDirection == '.') {
        currentDirection = direction; 
      }
      if (currentDirection == direction) {
        if (distance >= length - currentDistance) {
          ans++; 
          distance -= length - currentDistance; 
          currentDistance = 0; 
        }
        else {
          currentDistance += distance; 
          distance = 0; 
        }
      }
      else {
        if (distance >= currentDistance) {
          distance -= currentDistance;
          currentDistance = 0;  
          if (distance > 0) {
            currentDirection = direction; 
          }
        }  
        else {
          currentDistance -= distance;
          distance = 0; 
        }
      }                            
      ans += distance / length;
      currentDistance += distance;
      currentDistance %= length;               
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}