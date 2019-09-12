ARDUINO=arduino-1.8.9
wget https://downloads.arduino.cc/$ARDUINO-linux64.tar.xz -O $ARDUINO.tar.xz

tar -xf $ARDUINO.tar.xz
cd $ARDUINO
sudo ./install.sh
cd ..
rm $ARDUINO.tar.xz

#Install libraries
arduino --install-library "Rosserial Arduino Library"
arduino --install-library "L3G"
arduino --install-library "LSM303"
