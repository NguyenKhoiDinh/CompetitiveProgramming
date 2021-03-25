#include <iostream>
using namespace std;
long n, k, diff = 0, temporary = -1 ;
long a[10005];
bool check[10005];
int main(){
  cin >> n >> k;
  for(int i=1; i <= n; i++){
    cin >> a[i];
    if(check[a[i]] == false){
      check[a[i]] = true;
      diff++;
      if(diff == k){
        temporary = i;
      }
    }
    if(i == n){
      cout << 1 << ' ' << temporary;
    }
  }
  return 0;
}