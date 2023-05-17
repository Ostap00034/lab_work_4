#include <iostream>
#include <string>

using namespace std;

void RecTriangleIN(int n, int a)
{
  if (n == -1)
  {
    cout << "*\n";
  }
  else if (a != 0)
  {
    RecTriangleIN(n - 1, a);
    cout << "*" << string(n, 'X') << "*\n";
    if (a == n)
    {
      RecTriangleIN(a - 1, 0);
    }
  }
  else
  {
    cout << "*" << string(n, 'X') << "*\n";
    RecTriangleIN(n - 1, a);
  }
}

void RecTriangle(int a)
{
  RecTriangleIN(a, a);
}

int main()
{
  cout << "Enter your triangle max width: ";
  int n;
  cin >> n;
  RecTriangle(n);
}