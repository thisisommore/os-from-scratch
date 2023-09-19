#include "drivers/screen.c"
#include "drivers/keyboard.c"
#include "interrupt/isr.c"
#include "interrupt/timer.c"
#include "interrupt/idt.c"
void main()
{
    __asm__("sti");
    idt_init();
    cls();
    println("hello world");
    for (int i = 0; i <= 3000; i++)
    {
        println(int_to_assci(i));
    }

    init_keyboard();
    init_timer();
    println("END HERE");
}
