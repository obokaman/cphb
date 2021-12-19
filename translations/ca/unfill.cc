#include <iostream>
#include <vector>
#include <map>

using namespace std;

string line;

int main() {
  string s;
  map<int, string> mem;
  int count = 0;
  while (getline(cin, s)) {
    if (s.substr(0,7) == "\\begin{" and
        s.back()=='}' && s.size() < 20) {
      string end = "\\end{" + s.substr(7);
      cerr << "Found block " << s << "\n";
      cout << line << "\n";
      line.clear();
      line = s + "\n";
      while (getline(cin, s)) {
        line += s + "\n";
        if (s == end) {
          break;
        }
      }
      mem[++count] = line;
      cout << "[[[[" << count << "]]]]" << "\n";
      line.clear();
    } else {
      if (line != "" && !s.empty()) line += " ";
      line += s;
      if (s.empty()) {
        cout << line << "\n\n";
        line.clear();
      }
    }
  }
  cout << line << "\n";

  cout << "\n\n\n###\n";
  for (auto it : mem) {
    cout << "[[[[" << it.first << "]]]]\n";
    cout << it.second << "\n";
  }
}
