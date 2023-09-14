#include "screen.h"
#include "ports.c"
#include "../utils.c"

void set_cursor_offset(int offset)
{
    port_byte_out(VIDEO_PORT_CTRL, 14);
    port_byte_out(VIDEO_PORT_DATA, offset >> 8);
    port_byte_out(VIDEO_PORT_CTRL, 15);
    port_byte_out(VIDEO_PORT_DATA, offset & 0xff);
}

void print(char *text)
{
    char *video_mem = VIDEO_MEMORY;
    port_byte_out(VIDEO_PORT_CTRL, 14);
    int pos = port_byte_in(VIDEO_PORT_DATA) << 8;
    port_byte_out(VIDEO_PORT_CTRL, 15);
    pos += port_byte_in(VIDEO_PORT_DATA);
    while (*text != 0)
    {
        if (*text == '\n')
        {
            pos = cursor_to_new_line();
            text++;
            continue;
        }
        video_mem[pos * 2] = *text++;
        video_mem[(pos * 2) + 1] = WHITE_ON_BLACK;
        pos++;
        if (get_row(pos) > (MAX_ROWS))
        {
            scroll(pos);
            pos = get_cursor_offset(MAX_ROWS, 1);
        }
        else
        {
            set_cursor_offset(pos);
        }
    }
}

void println(char *text)
{
    print(text);
    cursor_to_new_line();
}

int cursor_to_new_line()
{
    char *video_mem = VIDEO_MEMORY;
    port_byte_out(VIDEO_PORT_CTRL, 14);
    int pos = port_byte_in(VIDEO_PORT_DATA) << 8;
    port_byte_out(VIDEO_PORT_CTRL, 15);
    pos += port_byte_in(VIDEO_PORT_DATA);
    int current_row = get_row(pos + 1);
    if (current_row + 1 > MAX_ROWS)
    {
        return scroll(pos);
    }
    else
    {
        int new_line_offset = get_cursor_offset(current_row + 1, 1) - 1; // -1 since memory starts from 0
        set_cursor_offset(new_line_offset);
        return new_line_offset;
    }
}

int scroll(int pos)
{
    char *video_mem = (char *)0xb8000;
    mem_cpy(video_mem, video_mem + (MAX_COLS * 2), MAX_COLS * MAX_ROWS * 2);
    int prev = get_cursor_offset(MAX_ROWS, 1) - 1;
    set_cursor_offset(prev);
    return prev;
}

int get_col(int offset)
{
    int row = offset / MAX_COLS;
    int remin = offset - (MAX_COLS * row);
    if (remin == 0)
        return MAX_COLS;
    return remin;
}

int get_row(int offset)
{
    int col = offset / MAX_COLS;
    if (col * MAX_COLS < offset)
        return col + 1;
    return col;
}

int get_cursor_offset(int row, int col)
{
    int col_max_row = ((row - 1) * MAX_COLS);
    return col_max_row + col;
}
void cls()
{
    char *video_mem = (char *)VIDEO_MEMORY;
    for (int i = 0; i < MAX_COLS * MAX_ROWS; i++)
    {
        video_mem[i * 2] = ' ';
        video_mem[i * 2 + 1] = WHITE_ON_BLACK;
    }
    set_cursor_offset(0);
}