#include "irq.h"
#include "idt.h"

void irq_init()
{
    // Intilize PCI IRQs to map the interrupts to 31 offset
    port_byte_out(PCI_CTRL, 0x11);
    port_byte_out(PCI_SLAVE_CTRL, 0x11);

    // 32 offset for 0-7 master PCI
    port_byte_out(PCI_DATA, 0x20);

    // 40 offset for 8-15 master PCI
    port_byte_out(PCI_SLAVE_DATA, 0x28);

    // Second pin is slave pin
    port_byte_out(PCI_DATA, 0x4);

    // Set slave id
    port_byte_out(PCI_SLAVE_DATA, 0x2);

    port_byte_out(PCI_DATA, 0x0);
    port_byte_out(PCI_SLAVE_DATA, 0x0);

    set_idt_entry(32, irq0);
    set_idt_entry(33, irq1);
    set_idt_entry(34, irq2);
    set_idt_entry(35, irq3);
    set_idt_entry(36, irq4);
    set_idt_entry(37, irq5);
    set_idt_entry(38, irq6);
    set_idt_entry(39, irq7);
    set_idt_entry(40, irq8);
    set_idt_entry(41, irq9);
    set_idt_entry(42, irq10);
    set_idt_entry(43, irq11);
    set_idt_entry(44, irq12);
    set_idt_entry(45, irq13);
    set_idt_entry(46, irq14);
    set_idt_entry(47, irq15);
}

void irq_handler(irq_handler_register r)
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