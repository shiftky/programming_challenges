/**
 * Interpreter
 * 最初の入力としてテストケース数 N を読み込み、テストケースの読み込みと命令解釈を N 回実行するプログラムを作成した。
 * 入力は空行が現れるまで続け、メモリの内容として配列に格納する。入力終了後は問題文に記載されたルールに従い、命令の
 * 解釈と実行を行っている。出力は命令解釈に必要な回数を出力とし、テストケースごとの結果は空行で分けた。
 */
#include <iostream>
#include <string>
#include <sstream>

#define MEM_SIZE 1000
#define REG_SIZE 10

using namespace std;

inline int toInt(std::string s) { int v; std::istringstream sin(s); sin>>v; return v; }

int interpret(int *mem, int *reg)
{
  int i = 0, cnt = 0;
  while ( i < MEM_SIZE ) {
    int cmd = mem[i] / 100;
    int p1 = (mem[i] / 10) % 10;
    int p2 = mem[i] % 10;
    i++;
    cnt++;

    switch (cmd) {
      case 1:
        return cnt;
      case 2:
        reg[p1] = p2;
        break;
      case 3:
        reg[p1] = (reg[p1] + p2) % 1000;
        break;
      case 4:
        reg[p1] = (reg[p1] * p2 ) % 1000;
        break;
      case 5:
        reg[p1] = reg[p2];
        break;
      case 6:
        reg[p1] = (reg[p1] + reg[p2]) % 1000;
        break;
      case 7:
        reg[p1] = (reg[p1] * reg[p2]) % 1000;
        break;
      case 8:
        reg[p1] = mem[reg[p2]];
        break;
      case 9:
        mem[reg[p2]] = reg[p1];
        break;
      case 0:
        if ( reg[p2] != 0 ) {
          i = reg[p1];
        }
        break;
    }
  }
  return 0;
}

void init_array(int *mem, int n)
{
  for ( int i=0; i<n; i++ ) {
    mem[i] = 0;
  }
}

int main(void) {
  int n, mem[MEM_SIZE], reg[REG_SIZE];

  cin >> n;

  string dummy;
  getline(cin, dummy);
  getline(cin, dummy);

  for ( int i=0; i<n; i++ ) {
    init_array(mem, MEM_SIZE);
    init_array(reg, REG_SIZE);

    int j = 0;
    while (1) {
      string str;
      getline(cin, str);
      if ( str.empty() ) {
        break;
      } else {
        mem[j] = toInt(str);
      }
      j++;
    }

    if ( i > 0 ) {
      cout << endl;
    }
    cout << interpret(mem, reg) << endl;
  }
  return 0;
}
