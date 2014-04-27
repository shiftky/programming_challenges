/**
 * File Fragmentation
 * ファイル断片を配列に全て格納し、断片の長さの最小値と最大値を足した値を、求めるファイルのサイズとした。
 * 断片のペア同士を結合した際、その文字列の長さが求めるファイルのサイズと一致するものを全て生成し、一番出現回数が
 * 多いものを答えとして出力した。
 */

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void)
{
  int testcase = 0;
  cin >> testcase;

  string dummy;
  getline(cin, dummy);
  getline(cin, dummy);

  for ( int i=0; i < testcase; i++ ) {
    int count = 0, min = 1000, max = 0;
    string flags[1000], line;

    getline(cin, line);
    while ( line != "" ) {
      flags[count++] = line;
      if ( min > line.length() ) {
        min = line.length();
      }
      if ( max < line.length() ) {
        max = line.length();
      }

      getline(cin, line);
    }

    int file_size = min + max, tmp_i = 0;
    string tmp[1000];
    map<string, int> items;
    for ( int j=0; j < count; j++ ) {
      for ( int k=0; k < count; k++ ) {
        if ( j != k && flags[j].length()+flags[k].length() == file_size ) {
          map<string, int>::iterator itr;
          string str = tmp[tmp_i++] = flags[j] + flags[k];

          itr = items.find(str);
          if ( itr != items.end() ) {
            items[str]++;
          } else {
            items.insert(pair<string, int>(str, 1));
          }
        }
      }
    }

    int max_cnt = 0;
    string max_str;
    for ( int j=0; j<tmp_i; j++ ) {
      map<string, int>::iterator itr;
      itr = items.find(tmp[j]);
      if ( itr != items.end() && itr->second > max_cnt ) {
        max_cnt = itr->second;
        max_str = itr->first;
      }
    }
    cout << max_str << endl;

    if ( i != testcase-1 ) {
      cout << endl;
    }
  }

  return 0;
}
