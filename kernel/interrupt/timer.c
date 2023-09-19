#include "../drivers/screen.h"
#include "../utils.h"
#include "../drivers/ports.h"
#include "isr.h"

#define PIT_FREQ 19
int tick = 0;
void timer_handler(idt_registers t)
{
    if (tick % PIT_FREQ == 0)
    {
        print("time - ");
        print(int_to_assci(tick / PIT_FREQ));
        println("s");
    }
    tick++;
}

void init_timer()
{
    irq_h[32] = timer_handler;

    // Using PIT_FREQ just to test, we can comment below steps and use PIT_FREQ as 18 instead which is default
    u16 divisor = 1193180 / PIT_FREQ;

    port_byte_out(0x43, 0x36);
    port_byte_out(0x40, (u8)(divisor & 0xff));
    port_byte_out(0x40, (u8)(divisor >> 8));
}