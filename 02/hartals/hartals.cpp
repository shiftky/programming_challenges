/**
 * Hartals
 * テストケース数 t, 日数 n, 政党数 p を入力し、 政党毎に Hartal かどうかを1週間分調べる。
 * 金・土曜日の場合は、 Hartal が起こらないものとして扱う。
 * 全期間を表す配列に、 Hartal が起こる場合は要素を true とし、最後に配列の true となる要素数を数え上げ出力する。
 */

#include <iostream>

#define MAX_WEEK_SIZE 3651

using namespace std;

int main(void)
{
  int t = 0;
  cin >> t;

  for ( int i=0; i<t; i++ ) {
    int n, p;
    cin >> n;
    cin >> p;

    bool week[MAX_WEEK_SIZE] = { false };
    for ( int j=0; j<p; j++ ) {
      int hatal;
      cin >> hatal;
      for ( int k=hatal-1; k<n; k+=hatal ) {
        if ( k % 7 != 5 && k % 7 != 6 ) {
          week[k] = true;
        }
      }
    }

    int count = 0;
    for ( int j=0; j<n; j++ ) {
      count += week[j] ? 1 : 0;
    }
    cout << count << endl;
  }

  return 0;
}
