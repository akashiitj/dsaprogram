// writing on a text file
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  fstream myfile ("example.txt");
  if (myfile.is_open())
  {
    myfile << "This is a line.\n";
    myfile << "This is another line.\n";
    myfile.close();
  }
  else cout << "Unable to open file";
 // myfile.close();
  string line;char ch;
 fstream myfile1 ("example.txt");
  if (!myfile1.eof())
  {
    while (  !myfile1.eof())
    {  myfile1.get(ch);
      cout << ch ;
    }
    myfile1.close();
  }

  else cout << "Unable to open file";

  return 0;
}
