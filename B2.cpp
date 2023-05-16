#include <iostream>
#include <vector>

using namespace std;

vector<string> alp{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

string H(int n, string s = "")
{
  if (n < 16)
    return "0x" + alp[n] + s;

  s = alp[n % 16] + s;
  return H(n / 16, s);
}

int main()
{
  cout << "Enter positive number to convert to hex: ";
  int n; cin >> n;
  cout << H(n) << endl;
}