#include "isr.h"
#include "../drivers/screen.h"
#include "../utils.h"

char *exception_messages[] = {
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Breakpoint",
    "Into Detected Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",

    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment Not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",

    "Coprocessor Fault",
    "Alignment Check",
    "Machine Check",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",

    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"};

void isr_handler(idt_registers idt_r)
{
    print("interrupt occurred - ");
    println(int_to_assci(idt_r.int_no));
    println(exception_messages[idt_r.int_no]);
}

void irq_handler(idt_registers r)
{
    // EOI
    if (r.int_no > 39)
    {
        port_byte_out(PCI_SLAVE_CTRL, 0x20);
    }
    port_byte_out(PCI_CTRL, 0x20);

    if (irq_h[r.int_no] != 0)
    {
        irq_individual_handle irq_handle = irq_h[r.int_no];
        irq_handle(r);
    }
}