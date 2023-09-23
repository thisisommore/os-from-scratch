#include "drivers/screen.c"
#include "drivers/keyboard.c"
#include "interrupt/idt.c"
#include "interrupt/isr.c"
#include "interrupt/irq.c"
#include "interrupt/timer.c"
#include "shell/shell.c"
void main()
{
    __asm__("sti");
    idt_init();
    cls();
    init_keyboard();

    println("PRO SHELL");
    char command_line[100];
    char bin_name[100], arg_res[100];
    while (1)
    {
        print("#> ");

        read_line(command_line);
        println("");
        get_params(command_line, bin_name, arg_res);

        char echo_bin[] = "ECHO";
        if (strcmp(bin_name, echo_bin) == 1)
        {
            println(arg_res);
        }
    }

    // init_timer();
    // println("END HERE");
}
