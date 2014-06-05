/**
 * Summation of Four Primes
 * 入力 n を受け取り、偶数の場合は "2 2 x y", 奇数の場合は "2 3 x y" となるように x y を求めた。
 * 7 以下の場合は "Impossible." と表示する。
 * はじめに配列に素数の一覧を作成し、 素数の中から x を選び y を2分探索で探すプログラムを実装した。　
 */
#include <iostream>
#include <algorithm>
#include <vector>

#define N 10000001

using namespace std;

int main(void)
{
  static bool prime[N];

  prime[0] = prime[1] = false;
  fill(prime+2, prime+N, true);

  for ( int i=2; i*i<N; i++ ) {
    if ( prime[i] ) {
      for ( int j=2*i; j<N; j+=i ) {
        prime[j] = false;
      }
    }
  }

  vector<int> p;
  for (int i=2; i<N; i++) {
    if ( prime[i] ) {
       p.push_back(i);
    }
  }

  int n;
  while ( cin >> n ) {
    if ( n <= 7 ) {
      cout << "Impossible." << endl;
    } else {
      if ( n % 2 == 0 ) {
        cout << "2 2 ";
        n -= 4;
      } else {
        cout << "2 3 ";
        n -= 5;
      }

      for ( int i=0; i<p.size(); i++ ) {
        if ( binary_search(p.begin(), p.end(), n-p[i]) ) {
          cout << p[i] << " " << n-p[i] << endl;
          break;
        }
      }
    }
  }
  return 0;
}
