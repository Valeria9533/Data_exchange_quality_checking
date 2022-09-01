This sofware is developed for radio-communication quality checks. 

It can also be used as a general data receiving/transmission terminal (via UART, RS-232, RS-485).

Baudrate ranges from 1200 to 115200 baud. If you don't set this parameter, it will be 9600 baud as a default.

(Windows app, but can be run in Linux using Wine)

Description:
1. Set addresses of devices, then click "Connect" and choose COM-port
2. Set baudrate
3. Set transmission interval
4. Choose the mode (master or slave)

If you have chosen "master" mode, data transmission will start automatically (numbers in sequence 10,20,30..f0..ff).

If you have chosen "slave" mode, device will automatically switch to the data package waiting mode. If something is received, it is transmitted back to "master" (the same data).

After each receiving package in both modes program will calculate number of sent packages (for master mode), numbers of received packages with right and wrongs checksums, number of errors and data exchange quality in %.

On the left side there are windows, where you can see transmitted data (for master mode) and received data.
Below there is a "Manual mode" window for generating custom packages. 
