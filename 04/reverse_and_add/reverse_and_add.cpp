/**
 * Reverse and Add
 * 入力を string として読み取り、 long に変換した値と、反転後 long に変換した値とを足しあわせ
 * その値が回文である場合は結果を出力して終了するプログラムを実装した。
 * 回文でない場合は、計算した結果をさらに反転し足しあわせ、回文となるまで同様の計算を繰り返す。
 */

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

inline string toString(long num) { ostringstream stream; stream << num; return stream.str(); }
inline long toLong(string s) { long n; istringstream sin(s); sin >> n; return n; }

bool check_palindrome(long num) {
  string num_str = toString(num);
  for ( int i=0, j=num_str.size()-1; i<num_str.size() && j>=0; i++, j-- ) {
    if ( num_str[i] != num_str[j] ) {
      return false;
    }
  }
  return true;
}

int main(void)
{
  int testcase;
  cin >> testcase;

  for ( int t=0; t<testcase; t++ ) {
    int cnt = 1;
    long result = 0;
    string input_num;

    cin >> input_num;
    result = toLong(input_num);
    while ( cnt < 1000 ) {
      string tmp = toString(result);
      reverse(tmp.begin(), tmp.end());
      result += toLong(tmp);
      if ( check_palindrome(result) ) {
        cout << cnt << " " << result << endl;
        break;
      }
      cnt++;
    }
  }

  return 0;
}
