sudo apt-get update
sudo apt-get upgrade	
sudo apt-get install python3-pyqt5
cd /home/pi/
git clone https://github.com/andreafabrizi/Dropbox-Uploader.git
chmod +x dropbox_uploader.sh
cd /home/pi/Dropbox-Uploader
./dropbox_uploader.sh
cd /home/pi/
git clone https://github.com/CoSE-Jerry/COSE_FLASHLAPSE.git
mv /home/pi/COSE_FLASHLAPSE/run.desktop /home/pi/Desktop/
mkdir /home/pi/HP
cd /home/pi/HP
touch Email.py
echo "user = \"AKIAVBZCUOJSRB2INWNI\"" >> Email.py
echo  "password = \"BKGCZpCh/GzW10Kawv/8r2KQ9KptfWuWyVbBZry78+V0\"">> Email.py
pcmanfm --set-wallpaper /home/pi/COSE_FLASHLAPSE/_image/desktop.png
cd /home/pi/Dropbox-Uploader
./dropbox_uploader.sh
leafpad /home/pi/COSE_FLASHLAPSE/README.md
