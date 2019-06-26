rm -rf /home/pi/Flashlapse_NEO
rm /home/pi/Desktop/run.desktop
cd /home/pi/
git clone https://github.com/CoSE-Jerry/COSE_FLASHLAPSE.git
mv /home/pi/COSE_FLASHLAPSE/run.desktop /home/pi/Desktop/
mkdir /home/pi/HP
pcmanfm --set-wallpaper /home/pi/COSE_FLASHLAPSE/_image/desktop.png
leafpad /home/pi/COSE_FLASHLAPSE/README.md
