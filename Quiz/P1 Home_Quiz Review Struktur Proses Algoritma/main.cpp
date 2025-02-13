#include <iostream>
using namespace std;

int fun(int (*)());

int main()
{
  fun(main);

  cout << "Hi";

  return 0;
}

int fun(int (*p)())
{
  cout << "Hllo";
  return 0;
}