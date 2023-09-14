# OS From Scratch

I always wanted to learn how OS works behind the scenes.

- How it handles various windows of applications.
- How it runs background processes.
- How it connects to various different hardwares seemlessly.

So I decided to start building my own OS from scratch

TODO list

- Bootloader
  - [x] disk read
  - [x] 16 bit print and hex print
  - [x] gdt for 32 bit protected mode
  - [x] 32 bit print
- Kernel
  - [x] Basic screen driver
  - [x] Clear screen function
  - [x] Print functions with scroll
        and newline
  - [ ] Interrupt handling
- Core OS
  - [ ] Cursor support
  - [ ] External application support
  - [ ] GUI components

# Compiling

You will need gcc, ld and nasm

I use this docker image for compiling cross-compiler tools which is recommed for 32 bit i386 OS.

```bash
docker run -it lordmilko/i686-elf-tools -gv 9.2.0 -bv 2.34 -dv 9.1
```

And copy the build zip generated inside container `/root/build-i686-elf/i686-elf-tools-linux.zip` to another ubuntu container.

You will need qemu too to test compiled os.

Run `make compile` and then `make start`

Result (Scrolling in action) -
<img width="832" alt="image" src="https://github.com/thisisommore/os-from-scratch/assets/51229945/b63a9cf7-a5b7-4537-8cbe-bb145c9e7c94">

Thanks to - (cfenollosa/os-tutorial)[https://github.com/cfenollosa/os-tutorial], (OSDevWiki)[https://wiki.osdev.org/Main_Page]
