// https://adventofcode.com/2023/day/2

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  int red;
  int green;
  int blue;
} Stats;

char buf[255];

int parse(const char* line, Stats constraint) {
  int game_idx;
  line += 5; // skip Game
  sscanf(line, "%d", &game_idx);
  printf("%d: ", game_idx);

  line = strchr(line, ':'); // find :
  line+=2; // skip : and space

  while(line != NULL && line[0] != '\0') {
    int v;
    sscanf(line, "%d", &v);
    printf("%d=", v);
    line = strchr(line, ' '); // find space
    line++; // skip space
    sscanf(line, "%s", buf);
    printf("%s ", buf);
    switch (buf[0]) {
    case 'r':
      if (v > constraint.red) return 0;
      break;
    case 'g':
      if (v > constraint.green) return 0;
      break;
    case 'b':
      if (v > constraint.blue) return 0;
      break;
    default:
      printf("BAD TOKEN: '%s'\n", buf);
      break;
    }

    line += strlen(buf);
    if (line[0] == ' ') line++;
    if (line[0] == '\n' || line[0] == '\0') break;
  }
  printf("\n");  

  return game_idx;
}

void task1() {
  char line[255];
  Stats constraint = {.red=12, .green=13, .blue=14};
  
  int res = 0;
  while(fgets(line, sizeof line, stdin) != NULL) {
    res += parse(line, constraint);
  }

  printf("Result = %d\n", res);
}

int parse2(char* line) {
  line = strchr(line, ':'); // find :
  line += 2; // skip : and space

  Stats stats= {.red=0, .green=0, .blue=0};

  while(line != NULL && line[0] != '\0') {
    int v;
    sscanf(line, "%d", &v);
    printf("%d=", v);
    line = strchr(line, ' '); // find space
    line++; // skip space
    sscanf(line, "%s", buf);
    printf("%s ", buf);
    switch (buf[0]) {
    case 'r':
      if (v > stats.red) stats.red = v;
      break;
    case 'g':
      if (v > stats.green) stats.green = v;
      break;
    case 'b':
      if (v > stats.blue) stats.blue = v;
      break;
    default:
      printf("BAD TOKEN: '%s'\n", buf);
      break;
    }

    line += strlen(buf);
    if (line[0] == ' ') line++;
    if (line[0] == '\n' || line[0] == '\0') break;
  }
  printf("\n");  

  return stats.red * stats.green * stats.blue;
}

void task2() {
  char line[255];

  int res = 0;
  while(fgets(line, sizeof line, stdin) != NULL) {
    res += parse2(line);
  }

  printf("Result = %d\n", res);
}

int main(void) {
  // task1();
  task2();
}
