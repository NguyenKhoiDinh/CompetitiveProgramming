#include <iostream>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <stdio.h> 
int numTest; 
const double PI = std::acos(-1); 

int main () {
  scanf("%d", &numTest); 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    double r, n, l;
    scanf("%lf %lf %lf", &r, &n, &l);  
    double angle = 360.0000 / n; 
    double h = (l / (2 * std::tan(PI / n))); 
    double arc = (PI * r * r * angle) / 360.0000;
    double tri = r * l + 0.5 * l * h;
    printf("%.12f\n", n * (arc + tri));
  }
  return 0; 
}