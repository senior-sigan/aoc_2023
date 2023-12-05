#include <stdio.h>

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

typedef struct TrieNode_ {
  struct TrieNode_ children[255];

} TrieNode;

void task_2(void) {
  // https://en.wikipedia.org/wiki/Trie
  // https://en.wikipedia.org/wiki/Radix_tree

  // Build a Prefix Tree
  // one two three four five six seven eight nine

  // [o t   f   s   e n]
  // [n w h o i i e i i]
  // [e o r u v x v g n]
  // [    e r e   e h e]
  // [    e       n t  ]

  // [o t t f f s s e n]
  // [n w h o i i e i i]
  // [e o r u v x v g n]
  // [    e r e   e h e]
  // [    e       n t  ]
}

int main(void) {
  // task_1();

  return 0;
}
