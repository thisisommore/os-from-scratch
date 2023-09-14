#include "drivers/screen.c"
void main()
{
    char *video_mem = (char *)0xb8000;
    cls();
    println("hello world");
    for (int i = 0; i < MAX_ROWS; i++)
    {
        println("THIS IS SCROLLING");
    }
    for (int i = 0; i < 13; i++)
    {
        println("THIS IS PRINTED AFTER MAX ROWS");
    }
    print("END HERE");
}
