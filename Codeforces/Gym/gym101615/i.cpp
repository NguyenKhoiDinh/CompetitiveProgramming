#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
struct command {
  char type;
  long long position;
  char character;
  bool operator == (const command &other) const {
    return (type == other.type && position == other.position && character == other.character);
  }
};
vector <command> program1, program2;

void readInput() {
  while (true) {
    command newCommand;
    cin >> newCommand.type;
    if (newCommand.type == 'E') {
      break;
    }
    cin >> newCommand.position;
    newCommand.character = '?';
    if (newCommand.type == 'I') {
      cin >> newCommand.character;
    }
    program1.push_back(newCommand);
  }
  while (true) {
    command newCommand;
    cin >> newCommand.type;
    if (newCommand.type == 'E') {
      break;
    }
    cin >> newCommand.position;
    newCommand.character = '?';
    if (newCommand.type == 'I') {
      cin >> newCommand.character;
    }
    program2.push_back(newCommand);
  }
}

void process(vector <command> &program) {
  for (int i = 1; i < (int) program.size(); i++) {
    for (int j = i; j >= 1; j--) {
      if (program[j].type == 'D' && program[j - 1].type == 'D' && program[j - 1].position <= program[j].position) {
        swap(program[j], program[j - 1]);
        program[j - 1].position++;
      }
      else if (program[j].type == 'I' && program[j - 1].type == 'I' && program[j - 1].position >= program[j].position) {
        swap(program[j], program[j - 1]);
        program[j].position++;
      }
      else if (program[j].type == 'D' && program[j - 1].type == 'I') {
        if (program[j - 1].position > program[j].position) {
          swap(program[j], program[j - 1]);
          program[j].position--;
        }
        else if (program[j - 1].position == program[j].position) {
          program.erase(program.begin() + j - 1, program.begin() + j + 1);
          i -= 2;
        }
        else {
          swap(program[j], program[j - 1]);
          program[j - 1].position--;
        }
      }
    }
  }
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  readInput();
  process(program1);
  process(program2);
  if ((int) program1.size() != (int) program2.size()) {
    cout << 1;
    return 0;
  }
  for (int i = 0; i < (int) program1.size(); i++) {
    if (program1[i] == program2[i]) {
      continue;
    }
    cout << 1;
    return 0;
  }
  cout << 0;
  return 0;
}