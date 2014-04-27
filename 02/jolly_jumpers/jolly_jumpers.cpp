/**
 * Jolly Jumpers
 * 行の一番最初の数字を n とし、以降続く数列は配列に格納して扱いました。
 * 配列要素を順に読み、 i 番目の要素と i+1 番目の要素同士で差の絶対値を計算しました。
 * 差が 0 の場合、n 以上の場合、既に計算済みの差である場合は Jolly Jumper でないとし、フラグを false に設定しました。
 * Jolly Jumper でない場合は、ループから抜け、入力の行ごとに結果を出力します。
 */
#include <iostream>
#include <cmath>

#define MAX_SIZE 3001

using namespace std;

int main(void)
{
  int n = 0;
  cin >> n;

  while ( !cin.eof() ) {
    if ( n <= 0 ) {
      cout << "Not jolly" << endl;
      cin >> n;
      continue;
    }

    int numbers[MAX_SIZE] = {0};
    for ( int i=0; i<n; i++ ) {
      cin >> numbers[i];
    }

    bool visited[MAX_SIZE] = {false}, flg = true;
    for ( int i=0; i<n-1; i++ ) {
      int abs_diff = abs(numbers[i] - numbers[i+1]);
      if ( abs_diff <= 0 || abs_diff >= n || visited[abs_diff] ) {
        flg = false;
        break;
      } else {
        visited[abs_diff] = true;
      }

    }
    cout << ( flg ? "Jolly" : "Not jolly" ) << endl;
    cin >> n;
  }

  return 0;
}
