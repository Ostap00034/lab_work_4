#include <iostream>

using namespace std;

long long square_sum(int n)
{
  if (n == 1)
    return 1;
  return square_sum(n - 1) + n * n;
}

int main()
{
  cout << "Enter your number: ";
  int n; cin >> n;
  cout << "Answer is: " <<  square_sum(n) << endl;
}