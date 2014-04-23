/**
 * Minesweeper
 * マインスイーパーのマップ全体を 0 で初期化した配列で表現し、爆弾の存在する箇所は値を -1 として区別しました。
 * 入力からのマップ読み込みが終了した後、爆弾の個数を調べヒントを作成する処理を行っています。
 * 爆弾が存在する座標の周囲 8 マスを表す配列要素に値を 1 加算しています。
 * その際、周囲のマスが実際のマップの範囲外になる場合や、別の爆弾が存在している箇所の場合は加算を行わず処理をスキップしています。
 */

#include <stdio.h>

#define N 1000
#define M 1000

int map[N][M];
void init_map(void);
void print_map(int, int);
void create_hint(int, int);
int check_map_area(int, int);

int main(void) {
  int n, m, i, j, field = 1;
  char line[100];

  while (1) {
    scanf("%d%d", &n, &m);
    if ( n == 0 && m == 0 ) {
      break;
    }

    init_map();
    for ( i=0; i<n; i++ ) {
      scanf("%s", line);
      for( j=0; j<m; j++ ){
        if ( line[j] == '*' ) {
          map[i][j] = -1;
        }
      }
    }

    for ( i=0; i<n; i++ ) {
      for ( j=0; j<m; j++ ) {
        if ( map[i][j] == -1 ) {
          create_hint(i, j);
        }
      }
    }

    if ( field != 1 ) {
      printf("\n");
    }
    printf("Field #%d:\n", field);
    print_map(n, m);
    field++;
  }
  return 0;
}

void create_hint(int n, int m)
{
  int i, j;
  for ( i=n-1; i<=n+1; i++ ) {
    for ( j=m-1; j<=m+1; j++ ) {
      if ( check_map_area(i, j) != 1 ) {
        continue;
      }

      if ( map[i][j] != -1 ) {
        map[i][j]++;
      }
    }
  }
}

int check_map_area(int n, int m)
{
  if ( n >= 0 && m >= 0 && n <= N && m <= M ) {
    return 1;
  } else {
    return 0;
  }
}

void init_map(void)
{
  int i = 0, j = 0;
  for ( i=0; i<N; i++ ) {
    for ( j=0; j<M; j++ ){
      map[i][j] = 0;
    }
  }
}

void print_map(int n, int m)
{
  int i = 0, j = 0;
  for ( i=0; i<n; i++ ) {
    for ( j=0; j<m; j++ ){
      if ( map[i][j] < 0 ) {
        printf("*");
      } else {
        printf("%d", map[i][j]);
      }
    }
    printf("\n");
  }
}

