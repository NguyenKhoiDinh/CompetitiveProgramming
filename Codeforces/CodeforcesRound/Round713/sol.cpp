#include <iostream> 

using namespace std;

int min(int a, int b) {
  int ret = a;
  if (ret > b) {
    ret = b;
  }
  return ret;
}

int max(int a, int b) {
  int ret = a;
  if (ret < b) {
    ret = b;
  }
  return ret;
}

void process() {
  int query;
  cin >> query;
  for (int i = 1; i <= query; i++) {
    int type, a, b;
    cin >> type >> a >> b;
    if (type == 0) {
      cout << min(a, b) << endl;
    }  
    else {
      cout << max(a, b) << endl;
    }
  }
}

int main () {
  process(); 
  return 0; 
}