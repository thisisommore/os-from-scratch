#include "../interrupt/irq.h"
#include "../interrupt/idt.h"
#include "ports.h"
#include "screen.h"
#include "../utils.h"
#include "keyboard.h"

#define KEYBOARD_DATA 0x60
void keyboard_handler(irq_handler_register r)
{
    u8 scancode = port_byte_in(KEYBOARD_DATA);
    print("Keyboard inpput scan code - ");
    println(int_to_assci(scancode));

    switch (scancode & 0xFF)
    {
    case SC_Q:
        println("Q");
        break;
    case SC_W:
        println("W");
        break;
    case SC_E:
        println("E");
        break;

    case SC_R:
        println("R");
        break;
    case SC_T:
        println("T");
        break;
    case SC_Y:
        println("Y");
        break;
    case SC_U:
        println("U");
        break;
    case SC_I:
        println("I");
        break;
    case SC_O:
        println("O");
        break;
    case SC_P:
        println("P");
        break;
    case SC_A:
        println("A");
        break;
    case SC_S:
        println("S");
        break;
    case SC_D:
        println("D");
        break;
    case SC_F:
        println("F");
        break;
    case SC_G:
        println("G");
        break;
    case SC_H:
        println("H");
        break;
    case SC_J:
        println("J");
        break;
    case SC_K:
        println("K");
        break;
    case SC_L:
        println("L");
        break;
    case SC_Z:
        println("Z");
        break;
    case SC_X:
        println("X");
        break;
    case SC_C:
        println("C");
        break;
    case SC_V:
        println("V");
        break;
    case SC_B:
        println("B");
        break;
    case SC_N:
        println("N");
        break;
    case SC_M:
        println("M");
        break;

    default:
        break;
    }
}

void init_keyboard()
{
    irq_h[33] = keyboard_handler;
}
