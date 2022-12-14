#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
struct command {
  string type;
  int value;
};
vector <command> save;

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    command newCommand;
    cin >> newCommand.type >> newCommand.value;
    save.push_back(newCommand);
  }
  int ans = 0;
  for (int v = 1; v <= 100; v++) {
    bool check = true;
    int val = v;
    for (int i = 0; i < n; i++) {
      if (save[i].type == "ADD") {
        val += save[i].value;
      }
      else if (save[i].type == "SUBTRACT") {
        val -= save[i].value;
        if (val < 0) {
          check = false;
          break;
        }
      }
      else if (save[i].type == "MULTIPLY") {
        val *= save[i].value;
      }
      else {
        if (val % save[i].value != 0) {
          check = false;
          break;
        }
        val /= save[i].value;
      }
    }
    if (check == false) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}