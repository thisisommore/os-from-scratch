#ifndef SCREEN_H
#define SCREEN_H

#define MAX_ROWS 25
#define MAX_COLS 80
#define VIDEO_MEMORY 0xb8000
#define WHITE_ON_BLACK 0x0f
#define VIDEO_PORT_CTRL 0x3d4
#define VIDEO_PORT_DATA 0x3d5

void print(char *text);
void println(char *text);
#endif SCREEN_H