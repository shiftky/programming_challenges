/**
 * The 3n+1 problem
 * 入力された i から j までを、問題文で示されたアルゴリズムの n とし、数列生成の計算を行う関数を実装しました。
 * 計算のため実行されたサイクルを記録し、 i から j までの入力のうち最もサイクルの大きい値を入力 i, j と共に出力しました。
 * i > j となる入力例が存在するため、その場合は関数 maxCycle 内で swap 処理を行った後実際の計算処理を実行しています。
 */

#include <stdio.h>

int maxCycle(int, int);
int calc(int);

int main(void) {
  int i = 0, j = 0;
  int tmp;

  while ( scanf("%d%d", &i, &j) != EOF ) {
    printf("%d %d %d\n", i, j, maxCycle(i, j));
  }
  return 0;
}

int maxCycle(int i, int j)
{
  int cycle = 0, max = 0;
  int n, tmp;

  if ( i > j ) {
    tmp = i;
    i = j;
    j = tmp;
  }

  for ( n = i; n <= j; n++ ) {
    cycle = calc(n);
    if ( max < cycle ) {
      max = cycle;
    }
  }
  return max;
}

int calc(int n)
{
  int cycle = 1;
  while ( n != 1 ) {
    cycle++;
    if ( n % 2 == 1 ) {
      n = 3 * n + 1;
    } else {
      n = n / 2;
    }
  }
  return cycle;
}
