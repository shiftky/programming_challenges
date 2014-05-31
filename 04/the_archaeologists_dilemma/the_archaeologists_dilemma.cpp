/**
 * The Archaeologists Dilemma
 */

#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
  long double c = c = logl(10)/logl(2);
  int num;
  cin >> num;
  while ( !cin.eof() ) {
    long double t, lp, lpp;
    lp = logl(num)/logl(2);
    lpp = logl(num+1)/logl(2);
    t = floorl(log10l(num)) + 2;
    for (; ceill(lp + t*c) != floorl(lpp + t*c); t++);
    cout << (long long int)floorl(lpp + t*c) << endl;
    cin >> num;
  }
  return 0;
}
