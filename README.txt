## How to Build
Build environment is Microsoft Visual Studio Community 2015 (C++)
Windows Software Development Kit (SDK) - Windows 10.0.10586.212
Windows Driver Kit (WDK) - Windows 10.0.15063.0
Microsoft Visual C++ 2015 Redistributable (x64 and x86) 14.0.24210

Source code is from TivaWare_C_Series-2.1.4.178\tools
Source has been customized for this project.

## How to run these tools
# The option "-a 0x00" says set write location of image.dfu to 0x0000 in flash. 
# If alternate bootloader code exists on micro controller, set to correspond to what bootloader expects for app load address.
# Option "-x" enable overwriting output without prompt
Release\dfuwrap.exe -i image.bin -o image.dfu -a 0x00 -x
Release\dfuprog.exe -v -r -f image.dfu

# New way to apply wrapper and flash
# -v = verbose
# -r = reset device when complete
# -p 4 = connect on COM4 to initiate DFU mode
# -f "file.bin" = compiled output file
bin\dfuprog.exe -v -r -p 4 -f image.dfu
