#include <iostream> 
#include <iomanip>
int numTest; 
double Tm, Sm, Ty, Sy; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> Tm >> Sm >> Ty >> Sy; 
    double timem = 100.000 / (Tm + Sm); 
    double timey = 100.000 / (Ty + Sy);
    if ((10.0 / Sm) <= (90.000 / Tm)) {
      timem = 10.0 / Sm + 90.0000 / Tm - 10.0 / Sm; 
    }
    if ((10.0 / Sy) <= (90.000 / Ty)) {
      timey = 10.0 / Sy + 90.0000 / Ty - 10.0 / Sy; 
    }
    //std::cout << std::fixed << std::setprecision(12) << timem << "    " << timey << std::endl;
    if (timem < timey) {
      std::cout << "Megumin"; 
    } 
    else if (timem > timey) {
      std::cout << "Yunyun"; 
    }
    else {
      std::cout << "Draw"; 
    }
    std::cout << std::endl; 
  }
  return 0;   
}