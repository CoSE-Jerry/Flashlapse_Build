to set up an flashlapse environment one your raspberry pi 3:

method one:
	1. go to http://bit.ly/2I1hc5k to download a modified raspbian image on to your computer
	2. flash SD card (larger than 4GB) with donloaded image using Etcher
		https://www.balena.io/etcher/
	3. attach keyboard and mouse to your raspberry pi to start using the device.
	4. double click flashlapse icon on desktop to run the program

method two:
	1. download latest "Raspbian Stretch with desktop" Image from
		https://www.raspberrypi.org/downloads/raspbian/
	2. flash SD card (larger than 4GB) with downloaded image using Etcher
		https://www.balena.io/etcher/
	3. attach Keyboard, mouse, and HDMI monitor to raspberry pi 3
	4. power up device
	5. follow the pop up to configure the device (wifi,keyboard,timezone...)
	6. left click on menu (top left raspberry icon), click "Preferences" -> "Raspberry Pi Configuration" -> "Interfaces"
	7. set "Camera" and "VNC" to enable (VNC allows you to connect to the device without monitor, keyboard, or mouse)
	8. click OK to reboot
	6. use flash drive to copy over "inject.sh" to the desktop
	7. open up terminal
	8. excecute command "sh /home/pi/Desktop/inject.sh" (without the " s)
	9. respond to all prompts with yes (Y)
	10. when asked about access token enter "nmyx0SMmLQAAAAAAAAMb4ZvmCjxnkIJ6zI00v8JaBNpICIFmxZ7sW7g07Bh2AWku"(without the " s)
	11. right click on desktop to open Desktop Preferences and change text color to somthing more readable.
	12. double click flashlapse icon on desktop to run the program


to set up flashlapse environment on arduino:

	1. download latest version of arduino IDE
		https://www.arduino.cc/en/Main/Software
	2. open arduino IDE 
		left click on "Tools" -> "Manage Libraries..." -> "Interfaces"
		Search for "Adafruit_NeoPixel" Library and click install
	3. open Arduino_Control_Code
		select the correct port, and upload code


Tips and Tricks:
	1. Always connect raspberry pi with arduino before running the program
	2. using VNC makes the process alot easier
