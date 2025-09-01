Set up AVR Toolchain in Debian (inside Termux):
# Skip 'sudo' if your debian doesn't include su/sudo packages
```bash
sudo apt update
sudo apt install avr-gcc avra avrdude
```
Create a directory in your local storage inside termux in debian, use linux commands like:
```bash
mkdir file #To create a directory
cd file #To select and go back to that mentioned directory
pwd #To check your path
```
Use nano to write your AVR assembly code targeting your Arduino’s microcontroller (usually ATmega328P):
```bash
nano filename.asm
```
Use avra or avr-gcc to convert the assembly file into a hex file, this will generate your filename.hex :
```bash
avra filename.asm
```
Open Arduino Droid and go to settings>actions>compile>precompiled>select your file
Then give permission to access your hardware that you have connected via desirable OTG cable
Your output will be executed
