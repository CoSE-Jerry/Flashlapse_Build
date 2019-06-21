sudo apt-get update
sudo apt-get upgrade	
sudo apt-get install python3-pyqt5
cd /home/pi/
git clone https://github.com/andreafabrizi/Dropbox-Uploader.git
chmod +x dropbox_uploader.sh
cd /home/pi/Dropbox-Uploader
./dropbox_uploader.sh
cd /home/pi/
git clone https://github.com/CoSE-Jerry/Flashlapse_NEO.git
mv /home/pi/Flashlapse_NEO/run.desktop /home/pi/Desktop/
mkdir /home/pi/HP
cd /home/pi/HP
touch Email.py
echo "user = \"AKIAVBZCUOJSRB2INWNI\"" >> Email.py
echo  "password = \"BKGCZpCh/GzW10Kawv/8r2KQ9KptfWuWyVbBZry78+V0\"">> Email.py
pcmanfm --set-wallpaper /home/pi/Flashlapse_NEO/_image/background.png
leafpad /home/pi/Flashlapse_NEO/README.md
