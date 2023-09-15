#include "drivers/screen.c"
#include "interrupt/isr.c"
#include "interrupt/idt.c"
void main()
{
    idt_init();
    cls();
    println("hello world");
    for (int i = 0; i <= 6000; i++)
    {
        println(int_to_assci(i));
    }
    println("END HERE");
    __asm__ __volatile__("int $2");
    __asm__ __volatile__("int $3");
}
