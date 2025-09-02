AVR-GCC is a version of the GNU Compiler Collection (GCC) specifically tailored as a cross-compiler to generate code for AVR microcontrollers, which are 8-bit RISC microcontrollers originally developed by Atmel (now part of Microchip Technology)
To update packages and install avr-gcc(Cross compiler for C especially for ATmega):
```bash
termux-setup-storage
sudo apt update #skip sudo/su if the package is not found in debian
sudo apt install avr-gcc avra avrdude
```
If you have already installed avr-gcc with other installments earlier, in order to check if avr-gcc is present in your termux, use these commands:
```bash
which avr-gcc
which avrdude
which avra
```
Alternative linux commands to check weather you have it installed:
```bash
avr-gcc --version
avrdude --help
avra --version
dpkg -l | grep avr #If you want to check for full installation (including libraries, configs, etc.) and not just the executables then run this command
```
Create a directory using following commands and create a .c file to write the code and compile:
```bash
mkdir directory #Creates a directory
cd directory #Directs to that respective directory
pwd #Used to check path
nano filename.c #Create a .c file and write a program (CTRL+O, Enter, CTRL+X)
```
To compile and convert it to .hex file from .elf, run these commands:
```bash
avr-gcc -mmcu=atmega328p -Os -o blink.elf blink.c
avr-objcopy -O ihex -R .eeprom blink.elf blink.hex
```
Copy and rename your .hex file to execute precompiled program in arduino droid to show output on arduino.
