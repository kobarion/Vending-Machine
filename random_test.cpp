/* rand example: guess the number */
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <ctime>       /* time */
// #include <time.h>

using namespace std;

int main ()
{
  int iSecret, iGuess;

  /* initialize random seed: */
  srand (time(NULL));

  time_t now = time(0);
  char* dt = ctime(&now);

  cout << "The local date and time is: " << dt << endl;


  /* generate secret number between 1 and 10: */
  iSecret = rand() % 10 + 1;

  do {
    cout << "Guess the number (1 to 10): " << endl;
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "The local date and time is: " << dt << endl;

    cin >> iGuess;
    if (iSecret<iGuess) cout << "The secret number is lower" << endl;
    else if (iSecret>iGuess) cout << "The secret number is higher" << endl;
  } while (iSecret!=iGuess);

  cout << "Congratulations!" << endl;
  return 0;
}