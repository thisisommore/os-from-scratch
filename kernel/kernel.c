#include "drivers/screen.c"
void main()
{
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
