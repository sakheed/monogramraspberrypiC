#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>

#define WHITE 1
#define BLACK 0
#define COLOR_RED 2

void draw_grid(uint16_t pixels[8][8]) {
    for(int y=0; y<8; y++) {
        move(y,0);
        for(int x=0; x<8; x++) {
            if(pixels[7-x][y]) {
                attron(COLOR_PAIR(pixels[7-x][y]));
                addch('#');
                attroff(COLOR_PAIR(pixels[7-x][y]));
            } else {
                addch(' ');
            }
        }
    }
    refresh();
}

void fill_pixels(uint16_t pixels[8][8], uint16_t color) {
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            pixels[i][j] = color;
        }
    }
}

int main(void) {
    // uint16_t means "non-negative two-byte integer"
    uint16_t pixel[8][8];

    // Starts drawing in the terminal
    initscr();
    start_color();
    /* This means consider WHITE to mean 
     * foreground is COLOR_WHITE (i.e., white) and
     * background is also COLOR_WHITE.
     * The value of WHITE was #defined above.
     * The value of COLOR_WHITE is #defined in 
     * ncurses.h. You can also use:
     * COLOR_BLACK
     * COLOR_RED
     * COLOR_GREEN
     * COLOR_YELLOW
     * COLOR_BLUE
     * COLOR_MAGENTA
     * COLOR_CYAN
     * but you probably also want to define your own, for example
     * #define RED 2
     */
    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
    init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(COLOR_RED, COLOR_RED, COLOR_RED);
    fill_pixels(pixel,BLACK);
    // Top of letter S
    pixel[5][2]=WHITE;
    pixel[4][2]=WHITE;
    pixel[3][2]=WHITE;
    pixel[2][2]=WHITE;

    //tester
    pixel[5][3] = WHITE;

    //start of diagonal
    //pixel[2][5]=WHITE;

    // Middle going down diagonally
    pixel[4][4]=WHITE;
    pixel[3][5]=WHITE;
    pixel[2][6]=WHITE;

    // Bottom of letter S
    pixel[5][7]=WHITE;
    pixel[4][7]=WHITE;
    pixel[3][7]=WHITE;
    pixel[2][7]=WHITE;

    // see: man 3 sleep
    draw_grid(pixel);
    sleep(2);
    fill_pixels(pixel,BLACK);
    //end of S, start D

    //left side of D
    pixel[2][2] = COLOR_RED;
    pixel[2][3] = COLOR_RED;
    pixel[2][4] = COLOR_RED;
    pixel[2][5] = COLOR_RED;
    pixel[2][6] = COLOR_RED;

    //right side of D
    pixel[6][2] =COLOR_RED;
    pixel[6][3] =COLOR_RED;
    pixel[6][4] =COLOR_RED;
    pixel[6][5] =COLOR_RED;
    pixel[6][6] =COLOR_RED;

    //bottom connector
    pixel[3][2] =COLOR_RED;
    pixel[4][2] =COLOR_RED;
    pixel[5][2] =COLOR_RED;
    pixel[6][2] =COLOR_RED;

    //top connector

    pixel[3][6] =COLOR_RED;
    pixel[4][6] =COLOR_RED;
    pixel[5][6] =COLOR_RED;
  
   //end pieces 
   pixel[7][6] = COLOR_RED;
  pixel[7][2] =COLOR_RED;




    draw_grid(pixel);
    sleep(2);
    fill_pixels(pixel,BLACK);

    // endwin() should only be called once/program
    endwin();
    return 0;
}
