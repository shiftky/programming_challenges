/**
 * The Trip
 * 小数点を含む数のまま計算を行うと、計算誤差により正しい結果を得られないため、入力を行う際に ドル と セント に
 * 分けて入力し、以降の金額計算はすべてセントで（整数として）行った。
 */

#include <stdio.h>
#define N 1001

int main(void) {
  int i, n, dollar, cent, total, get, give;
  int money[N];
  double avg;

  while (1) {
    scanf("%d", &n);
    if ( n == 0 ) {
      break;
    }
    total = avg = get = give = 0;

    for ( i=0; i<n; i++ ) {
      scanf("%d.%d", &dollar, &cent);
      money[i] = dollar * 100 + cent;
      total += money[i];
    }
    avg = (double) total / (double) n;

    for ( i=0; i<n; i++ ) {
      if ( avg - money[i] < 0 ) {
        give += -(avg - money[i]);
      } else {
        get += avg - money[i];
      }
    }

    if ( give > get ) {
      printf("$%d.%02d\n", give / 100, give % 100);
    } else {
      printf("$%d.%02d\n", get / 100, get % 100);
    }
  }
  return 0;
}
