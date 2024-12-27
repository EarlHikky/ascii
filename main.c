#include <stdio.h>
#include <unistd.h>

#define SUCCES 1
#define FAIL 0
#define HEIGHT 50
#define WIDTH 100
#define PAUSE 100000

void print_ascii_image(unsigned char ascii_image[HEIGHT][WIDTH]);
unsigned char process_file(unsigned char ascii_image[HEIGHT][WIDTH]);

int main() {
  unsigned char ascii_image[HEIGHT][WIDTH] = {0};

  if (process_file(ascii_image)) {
    print_ascii_image(ascii_image);
  }

  return 0;
}

void print_ascii_image(unsigned char ascii_image[HEIGHT][WIDTH]) {
  for (unsigned char y = 0; y < HEIGHT; y++) {
    for (unsigned char x = 0; x < WIDTH; x++) {
      printf("%c", ascii_image[y][x]);
    }
    printf("\n");
    usleep(PAUSE);
  }
}

unsigned char process_file(unsigned char ascii_image[HEIGHT][WIDTH]) {
  unsigned char flag = FAIL;
  FILE *file = fopen("file", "r");

  if (file) {
    int number = 0;
    unsigned char row = 0, col = 0;

    while (fscanf(file, "%d", &number) == 1) {
      ascii_image[row][col] = number;
      col++;
      if (col >= WIDTH && row < HEIGHT) {
        col = 0;
        row++;
      }
    }

    fclose(file);
    flag = SUCCES;
  }
    return flag;
}
