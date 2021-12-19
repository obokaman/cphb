#include <iostream>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

map<string, string> rep;

int main(int argc, char** argv) {
  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " <unfill-file>" << endl;
    return 1;
  }
  ifstream ifs(argv[1]);
  string line;
  string symbol;
  while (getline(ifs, line) && line != "###") {}
  while (getline(ifs, line) ) {
    if (line.substr(0,4) == "[[[[") {
      symbol = line;
    } else {
      if (!symbol.empty()) {
        if (!rep[symbol].empty()) {
          rep[symbol] += "\n";
        }
        rep[symbol] += line;
      }
    }
  }

  while (getline(cin, line)) {
    auto it = rep.find(line);
    if (it != rep.end()) {
      cout << it->second;
    } else {
      cout << line << endl;
    }
  }
}
