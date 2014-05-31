/**
 * Self-describing Sequence
 * はじめに、値 n が数列に始めて現れた位置 i を、配列 nums の n 番目に格納する。
 * 入力 n を受け取り、配列内で nums[i] <= n となる場合の i を結果とすることで、 f(n) の値を求めることができる。
 * upper_bound() を利用し、入力 n より大きい要素が最初に現れる位置を結果として表示した。
 */

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 2000000000

using namespace std;

int nums[1000000], size = 0;

void numbers(void)
{
  int i = 1;
  nums[0] = 1;
  nums[1] = 2;
  nums[2] = 4;
  for (; nums[nums[i] - 1] <= MAX; ++i) {
    for (int j = nums[i]; j <= nums[i+1]; ++j) {
      nums[j] = nums[j-1] + i + 1;
    }
  }
  size = nums[i] - 1;
}

int main(void)
{
  numbers();
  int n;
  while ( cin >> n && n ) {
    cout << upper_bound(nums, nums+size, n)-nums << endl;
  }
  return 0;
}
