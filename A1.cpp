#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  ifstream input("prob1_in.txt");
  ofstream output("prob1_out.txt");
  string line;
  while (getline(input, line))
  {
    long int i = 0, max = -1000000000;
    string temp = "";

    while (i < line.size())
    {
      if (line[i] != ' ')
      {
        temp += line[i];
        if (i == line.size() - 1)
          max = stol(temp) > max ? stol(temp) : max;
      }
      else
      {
        max = stol(temp) > max ? stol(temp) : max;
        temp = "";
      }
      ++i;
    }
    output << max << endl;
  }

  input.close();
}