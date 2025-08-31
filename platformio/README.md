Steps to execute Platform io in Termux:

Install Platform io in Termux terminal(inside Debain or Ubuntu platform):
```bash
# Make sure python3-venv is installed [Note: sometimes Sudo or su command doesn't work in debian so ignore su/sudo and execute rest of the command]
sudo apt update
sudo apt install python3-venv -y

# Create a virtual environment
python3 -m venv ~/.pioenv

# Activate it
source ~/.pioenv/bin/activate

# Now install platformio inside this venv
pip install platformio
```

Every time you want to use PlatformIO, just:
```bash
source ~/.pioenv/bin/activate
pio --version
```

After login to the debian platform inside termux, get out of the root and create a new Platform IO directory/project:
```bash
mkdir twos_complement
cd twos_complement

# Use this command to call platformio.ini into your directory where you write nano file
pio init --board uno
```

Create a nano file inside source in the directory and run Platform IO:
```bash
# Write the program inside the nano file and save (Ctrl+O), Enter, Exit from the nano file(Ctrl+O)
nano src/main.cpp

#To run the program smoothly and compile:
pio run

# After the .hex file is created, copy and move it to the folder where arduino droid can easily access your compiled file
cp .pio/build/uno/firmware.hex /sdcard/Download/firmware_uno.hex
```
Come out of termux and execute precompiled hex file by calling it through arduino droid
If your code syncs properly with the hardware connections, then desired output is displayed.
