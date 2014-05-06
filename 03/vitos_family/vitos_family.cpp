/**
 * Vito's Family
 * 入力された通りの値から、それぞれの家の間の距離を動的配列に格納していき
 * ソート後を行った後に最小の値を出力した。
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
  int testcase;
  cin >> testcase;

  for ( int t=0; t<testcase; t++ ) {
    int r;
    scanf("%d", &r);

    vector<int> si;
    for ( int i=0; i<r; i++ ) {
      int tmp;
      scanf("%d", &tmp);
      si.push_back(tmp);
    }

    vector<int> d;
    for ( int i=0; i<si.size(); i++ ) {
      int sum = 0;
      for ( int j=0; j<si.size(); j++ ) {
        if ( si[i] != si[j] ) {
          sum += abs(si[i]-si[j]);
        }
      }
      d.push_back(sum);
    }
    sort(d.begin(), d.end());
    cout << d.front() << endl;
  }

  return 0;
}

