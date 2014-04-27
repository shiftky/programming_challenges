/**
 * Where's Waldorf?
 * 文字同士の比較は、入力を行う段階ですべて小文字に統一してから行った。
 * 2次元配列に文字を全て入力し、検証する単語の1文字目と一致する文字が見つかった場合は、その位置をスタート地点として
 * 縦横斜めに8方位に対し、単語で使用されている文字が存在しているかを確認するプログラムを実装した。
 * 既に検証済みであり、存在していることが確認できている単語については、再び現れた際は検証処理を行わないようにした。
 */

#include <iostream>
#include <string>

using namespace std;

int field_row, field_col;
char field[51][51];

bool north(string word, int row, int col)
{
  int i = 0;
  while ( row >= 0 && i < word.length() && field[row][col] == word[i] ) {
    row--;
    i++;
  }
  return word.length() == i;
}

bool north_east(string word, int row, int col)
{
  int i = 0;
  while ( row >= 0 && col <= field_col && i < word.length() && field[row][col] == word[i] ) {
    row--;
    col++;
    i++;
  }
  return word.length() == i;
}

bool north_west(string word, int row, int col)
{
  int i = 0;
  while ( col >= 0 && row >= 0 && i < word.length() && field[row][col] == word[i] ) {
    row--;
    col--;
    i++;
  }
  return word.length() == i;
}

bool south(string word, int row, int col)
{
  int i = 0;
  while ( row <= field_row && i < word.length() && field[row][col] == word[i] ) {
    row++;
    i++;
  }
  return word.length() == i;
}

bool south_east(string word, int row, int col)
{
  int i = 0;
  while ( col <= field_col && row <= field_row && i < word.length() && field[row][col] == word[i] ) {
    row++;
    col++;
    i++;
  }
  return word.length() == i;
}

bool south_west(string word, int row, int col)
{
  int i = 0;
  while ( col >= 0 && row <= field_row && i < word.length() && field[row][col] == word[i] ) {
    row++;
    col--;
    i++;
  }
  return word.length() == i;
}

bool east(string word, int row, int col)
{
  int i = 0;
  while ( col <= field_col && i < word.length() && field[row][col] == word[i] ) {
    col++;
    i++;
  }
  return word.length() == i;
}

bool west(string word, int row, int col)
{
  int i = 0;
  while ( col >= 0 && i < word.length() && field[row][col] == word[i] ) {
    col--;
    i++;
  }
  return word.length() == i;
}

int main(void)
{
  int testcase = 0;
  cin >> testcase;

  for ( int i=0; i<testcase; i++ ) {
    cin >> field_row >> field_col;
    string dummy;
    getline(cin, dummy);

    for ( int j = 1; j <= field_row; j++ ) {
      for ( int k = 1; k <= field_col; k++ ) {
        char field_c;
        cin >> field_c;
        field[j][k] = tolower(field_c);
      }
    }

    string words[20] = { "" };
    int word_num;
    cin >> word_num;
    for ( int j = 0; j < word_num; j++ ) {
      string str_word;
      getline(cin, str_word);
      if ( str_word.empty() ) {
        j--;
      } else {
        for ( int k = 0; k < str_word.length(); k++ ) {
          words[j] += tolower(str_word[k]);
        }
      }
    }

    for ( int w = 0; w < word_num; w++ ) {
      string already = "";
      for ( int row = 1; row <= field_row; row++ ) {
        for ( int col = 1; col <= field_col; col++ ) {
          if ( already != words[w] && field[row][col] == words[w][0] ) {
            if ( north(words[w], row, col) ||
                 north_east(words[w], row, col) || north_west(words[w], row, col) ||
                 south(words[w], row, col) ||
                 south_east(words[w], row, col) || south_west(words[w], row, col) ||
                 east(words[w], row, col) || west(words[w], row, col) ) {
              already = words[w];
              cout << row << " " << col << endl;
            }
          }
        }
      }
    }

    if ( i < testcase-1 ) {
      cout << endl;
    }

    field_row = field_col = 0;
    for ( int j = 1; j <= field_row; j++ ) {
      for ( int k = 1; k <= field_col; k++ ) {
        field[j][k] = 0;
      }
    }
  }

  return 0;
}
