/**
 * Longest Nap
 * アポイントメントの数だけ行を読み取り、スケジュールの開始時刻と終了時刻を保存する。
 * スケジュールの説明文は読み取らないようにした。
 * 10時から18時までの間で、スケジュール時間の範囲を確認し、一番長い間昼寝ができる時間を計算する。
 * 計算結果が1時間を超える場合とそうでない場合で、出力のメッセージ内容が変わるようにした。
 */

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Task {
  int start_h, start_m, end_h, end_m;
};

bool sort_time(struct Task a, struct Task b)
{
  return a.start_h*60+a.start_m < b.start_h*60+b.start_m;
}

inline int toInt(std::string s) { int v; std::istringstream sin(s); sin>>v; return v; }

int main(void)
{
  string line;
  getline(cin, line);
  int day = 0;
  while ( !cin.eof() ) {
    if ( line.empty() ) {
      getline(cin, line);
      continue;
    }

    day++;
    int apo = toInt(line);
    if ( apo == 0 ) {
      printf("Day #%d: the longest nap starts at 10:00 and will last for 8 hours and 0 minutes.\n", day);
      getline(cin, line);
      continue;
    }

    vector<struct Task> task;
    for ( int i=0; i<apo; i++ ) {
      getline(cin, line);
      if ( line.empty() ) {
        i--;
        continue;
      }
      struct Task time = { toInt(line.substr(0, 2)), toInt(line.substr(3, 2)), toInt(line.substr(6, 2)), toInt(line.substr(9, 2)) };
      task.push_back(time);
    }
    sort(task.begin(), task.end(), sort_time);

    int nap = -1, start_h, start_m;
    if ( task[0].start_h != 10 || task[0].start_m != 0 ) {
      nap = task[0].start_h*60 + task[0].start_m - 10*60;
      start_h = 10;
      start_m = 0;
    }
    for ( int i=1; i<apo; i++ ) {
      if ( (task[i-1].end_h != task[i].start_h || task[i-1].end_m != task[i].start_m) && nap < (task[i].start_h*60+task[i].start_m - task[i-1].end_h*60-task[i-1].end_m) ) {
        nap = task[i].start_h*60 + task[i].start_m - task[i-1].end_h*60 - task[i-1].end_m;
        start_h = task[i-1].end_h;
        start_m = task[i-1].end_m;
      }
    }
    if ( task[apo-1].end_h != 18 && nap < 18*60 - task[apo-1].end_h*60 - task[apo-1].end_m) {
      nap = 18*60 - task[apo-1].end_h*60 - task[apo-1].end_m;
      start_h = task[apo-1].end_h;
      start_m = task[apo-1].end_m;
    }

    printf("Day #%d: the longest nap starts at %d:%02d and will last for ", day, start_h, start_m);
    if ( nap >= 60 ) {
      printf("%d hours and %d minutes.\n", nap / 60, nap % 60);
    } else {
      printf("%d minutes.\n", nap);
    }

    getline(cin, line);
  }

  return 0;
}
