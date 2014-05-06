/**
 * Shoemaker's problem
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
  int  n;

  while ( scanf("%d\n\n", &n) != EOF ) {
    int testcase, task_i, penalty;
    scanf("%d\n", &testcase);
    cout << testcase << endl;

    for ( int t=0; t<testcase; t++ ) {
      scanf("%d %d\n", &task_i, &penalty);
      cout << task_i << " " << penalty << endl;
    }
  }

  return 0;
}

