#include <iostream>
#include <string>

using namespace std;

class RecString
{
  string s;

public:
  RecString(string _s) : s(_s) {}

  int length()
  {
    if (s == "")
      return 0;
    return 1 + RecString(s.substr(1)).length();
  }

  void append(string t)
  {
    if (t == "")
      return;
    s += t[0];
    s.append(t.substr(1));
  }

  int count(char t)
  {
    if (s == "")
      return 0;
    if (s[0] == t)
      return 1 + RecString(s.substr(1)).count(t);
    return RecString(s.substr(1)).count(t);
  }

  string getString()
  {
    return s;
  }
};

int main()
{
  cout << "Enter your string: ";
  string a;
  getline(cin, a);

  RecString str(a);

  cout << "Enter any string for concatenate with your: ";

  cin.ignore();

  string c;
  getline(cin, c);

  str.append(c);

  cout << "Recieved string: " << str.getString() << endl;

  cout << "Enter your character to count in your string: ";

  char b;
  cin >> b;

  cout << "Your character (" << b << ") is contained " << str.count(b) << " times in your string(" << str.getString() << ")" << endl;

  cout << "Your string is " << str.length() << " characters long." << endl;
}