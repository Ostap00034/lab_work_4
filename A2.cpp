#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  ifstream input("prob2_in.txt");
  ofstream output("prob2_out.txt");
  
  string line;
  getline(input, line);

  int i = 0, k = 0;

  while (i < line.size() - 1)
  {
    if (line[i] != ' ')
    {
      if (line[i + 1] != ' ' && i != line.size() - 2)
        output << line[i] << "*";
      else if (i == line.size() - 2)  
        output << line[i] << "*" << line[i + 1];
      else
        output << line[i];
    }
    else
      output << line[i];
      
    ++i;
  }

  input.close();
}