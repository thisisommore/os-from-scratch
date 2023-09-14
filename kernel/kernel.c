#include "drivers/screen.c"
void main()
{
    cls();
    println("hello world");
    for (int i = 0; i <= 6000; i++)
    {
        println(int_to_assci(i));
    }

    print("END HERE");
}
