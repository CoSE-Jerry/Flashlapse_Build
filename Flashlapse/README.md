to set up an flashlapse environment one your raspberry pi 3:

method one:
	1. go to http://bit.ly/2I1hc5k to download a modified raspbian image on to your computer
	2. flash SD card (larger than 4GB) with downloaded image using Etcher
		https://www.balena.io/etcher/
	3. attach keyboard and mouse to your raspberry pi to start using the device.
	4. double click flashlapse icon on the desktop to run the program

method two:
	1. download the latest "Raspbian Stretch with desktop" Image from
		https://www.raspberrypi.org/downloads/raspbian/
	2. flash SD card (larger than 4GB) with the downloaded image using Etcher
		https://www.balena.io/etcher/
	3. attach Keyboard, mouse, and HDMI monitor to raspberry pi 3
	4. power up the device
	5. follow the pop up to configure the device (wifi, keyboard, timezone...)
	6. left click on menu (top left raspberry icon), click "Preferences" -> "Raspberry Pi Configuration" -> "Interfaces"
	7. set "Camera" and "VNC" to enable (VNC allows you to connect to the pi without monitor, keyboard, or mouse)
	8. click OK and agree to reboot
	6. use a fat32 (can be formatted to)flash drive to copy "inject.sh" to the desktopof raspberry pi
	7. open up terminal (click black box on the top left corner)
	8. excecute command "sh /home/pi/Desktop/inject.sh" (without the " s) this might take a while depending on your network connection and how out of date your original image is
	9. respond to all prompts with yes (Y)
	10. when asked about access token copy over from the credentials file "nmyx0SMmLQAAAAAAAAMb4ZvmCjxnkIJ6zI00v8JaBNpICIFmxZ7sW7g07Bh2AWku"(without the " s, in raspberry pi, copy and paste is "ctrl + shift + c" and "ctrl + shift +v")
	11. right click on desktop to open Desktop Preferences and change text color to somthing more readable.
	12. double click flashlapse icon on the desktop to run the program


to set up flashlapse environment on arduino:

	1. download the latest version of arduino IDE
		https://www.arduino.cc/en/Main/Software
	2. open arduino IDE 
		left click on "Tools" -> "Manage Libraries..." -> "Interfaces"
		Search for "Adafruit_NeoPixel" Library and click install
	3. open Arduino_Control_Code
		select the correct port, and upload code


Tips and Tricks:
	1. always connect raspberry pi with arduino before running the program
	2. using VNC makes the process alot easier
	3. the software automaticly updates every time it runs
