#include <iostream>
using namespace std;

void print(char chr, int times)
{
  for (int i = 0; i < times; i++)
    cout << chr;
  return;
}

int main()
{
  for (int i = 0; i < 10; i += 3)
    {
	  print(' ', ((10 - i) / 2) +  1);
	  print('*', i + 1);
      cout << endl;
	}

  for (int i = 10; i > -1; i -= 3)
	{
      print(' ', ((10 - i) / 2) + 1);
      print('*', i + 1);
	  cout << endl;
    }

  return 0;
}
