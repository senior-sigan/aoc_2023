#include <stdio.h>
#include <string.h>

// https://adventofcode.com/2023/day/1

// ======
// Part 1

// As they're making the final adjustments, they discover that their calibration document (your puzzle input) has been amended by a very young Elf who was apparently just excited to show off her art skills. Consequently, the Elves are having trouble reading the values on the document.

// The newly-improved calibration document consists of lines of text; each line originally contained a specific calibration value that the Elves now need to recover. On each line, the calibration value can be found by combining the first digit and the last digit (in that order) to form a single two-digit number.

// For example:

// 1abc2
// pqr3stu8vwx
// a1b2c3d4e5f
// treb7uchet
// In this example, the calibration values of these four lines are 12, 38, 15, and 77. Adding these together produces 142.

// Consider your entire calibration document. What is the sum of all of the calibration values?

// ======
// Part 2

// Your calculation isn't quite right. It looks like some of the digits are actually spelled out with letters: one, two, three, four, five, six, seven, eight, and nine also count as valid "digits".

// Equipped with this new information, you now need to find the real first and last digit on each line. For example:

// two1nine
// eightwothree
// abcone2threexyz
// xtwone3four
// 4nineeightseven2
// zoneight234
// 7pqrstsixteen
// In this example, the calibration values are 29, 83, 13, 24, 42, 14, and 76. Adding these together produces 281.

void task_1(void) {
  char ch;
  int res = 0;
  int left = -1;
  int right;
  while ((ch = getchar()) != EOF) {
    if (ch == '\n') {
      res += left * 10 + right;
      left = -1;
    }

    if (ch >= '0' && ch <= '9') {
      if (left < 0) {
        left = ch - '0';
        right = left;
      } else {
        right = ch - '0';
      }
    }
  }
  // handle last line
  res += left * 10 + right;

  printf("Result: %d\n", res);
  
  // 52974
}


#define N 33 // one two three four five six seven eight nine
#define A 14 // a..z

char* alphabet = "efghinorstuvwx";
char* words[9] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int trie[N][A];
int ch2pos[255];

void build_trie() {
  // https://en.wikipedia.org/wiki/Trie
  // https://en.wikipedia.org/wiki/Radix_tree

  for (int i = 0; i < 255; i++) {
    ch2pos[i] = -1;
  }
  int pos = 0;
  for (char* ch = alphabet; *ch != '\0'; ch++) {
    ch2pos[(int)*ch] = pos++;
  }

  int i = 0;
  for (int iw = 0; iw < 9; iw++) {
    int s = 0;
    for (char* ch = words[iw]; *ch != '\0'; ch++) {
      int term_ch = (*(ch+1) == '\0');
      int pos = ch2pos[(int)*ch];
      int t = trie[s][pos];
      if (t == 0) {
        if (term_ch == 1) {
          // negative means last node. And it encodes the value
          // Example: one -> o n e -> e -> -1
          trie[s][pos] = -(iw+1);
        } else {
          trie[s][pos] = ++i;
          s = i;
        }
      } else {
        s = t;
      }
    }
  }

  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < A; j++) {
  //     printf("%2d ", trie[i][j]);
  //   }
  //   printf("\n");
  // }
}

int find(char* line) {
  int s = 0;
  for (size_t i = 0; i < strlen(line); i++) {
    char ch = line[i];

    if (ch >= '0' && ch <= '9') { // handle digits
      return ch - '0';
    }

    int pos = ch2pos[(int)ch];
    if (pos < 0) {
      return 0;
    }

    s = trie[s][pos];
    if (s == 0) {
      return 0;
    }

    if (s < 0) {
      return -s;
    }
  }

  return 0;
}

int calc_line(char* line) {
  int first = -1;
  int last = 0;
  for (size_t i = 0; i < strlen(line); i++) {
    int num = find(line + i);

    if (num > 0) {
      if (first < 0) {
        first = num;
        last = first;
      } else {
        last = num;
      }
    }
  }
  
  int res = 10 * first + last;
  printf("%s %d\n", line, res);

  return res;
}


void task_2(void) {
  char line[50]; // max line length is 50
  build_trie();

  int res = 0;
  while(scanf("%s", line) > 0) {
    res += calc_line(line);
  }

  printf("Result = %d\n", res);
  // 53340
}

int main(void) {
  // task_1();
  task_2();

  return 0;
}
