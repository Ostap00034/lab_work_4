#include <iostream>
#include <string>

using namespace std;

void RecTriangle(int n, int a)
{
  if (n == -1)
  {
    cout << "*\n";
  }
  else if (a != 0)
  {
    RecTriangle(n - 1, a);
    cout << "*" << string(n, 'X') << "*\n";
    if (a == n)
    {
      RecTriangle(a - 1, 0);
    }
  }
  else
  {
    cout << "*" << string(n, 'X') << "*\n";
    RecTriangle(n - 1, a);
  }
}

int main()
{
  cout << "Enter your triangle max width: ";
  int n;
  cin >> n;
  RecTriangle(n, n);
}