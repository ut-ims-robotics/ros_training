#!/bin/bash
if [[ $EUID -ne 0  ]]; then
  echo "You need to be root to run this script. Use \"sudo $0\"" 
  exit 1
fi

echo "!!! WARNING !!! This script will mess up your host file and much more."
echo "Make sure you're running it ONLY on a system meant for ROS Training!"
echo "CTRL+C to close this program."

echo -ne "Computer ID [1-12]: "
read MY_ID

echo -ne "Password for clearbot WiFi network: "
read -s MY_PASSWORD

MY_HOSTNAME="laptop-$MY_ID"

# Distribute computers between the two routers based on their ID.
if [ $MY_ID -le 5 ]
then
  SSID="clearbot-0"
  PROFILES=$(nmcli connection | awk '$1=="clearbot-0"{print $2}')
else
  SSID="clearbot-1"
  PROFILES=$(nmcli connection | awk '$1=="clearbot-1"{print $2}')
fi

INTERFACE=$(iw dev | awk '$1=="Interface"{print $2}')
IP=192.168.200.$(($MY_ID + 100))

# Set hostname
echo "$MY_HOSTNAME" >> /etc/hostname

# Overwrite the hosts file.
HOSTS_FILE=/etc/hosts

echo "127.0.0.1 localhost" > $HOSTS_FILE
echo "127.0.1.1 $MY_HOSTNAME" >> $HOSTS_FILE

# The following lines are desirable for IPv6 capable hosts
cat >> $HOSTS_FILE <<- EOM

::1     ip6-localhost ip6-loopback
fe00::0 ip6-localnet
ff00::0 ip6-mcastprefix
ff02::1 ip6-allnodes
ff02::2 ip6-allrouters

EOM

# add laptops
for i in {1..25}; do
  echo "192.168.200.$(($i + 100)) laptop-$i" >> $HOSTS_FILE
done

echo "" >> $HOSTS_FILE

# add robots
for i in {1..15}; do
  echo "192.168.200.$i  clearbot-$i" >> $HOSTS_FILE
done


# add ROS_IP to bashrc
#FILE=~/.bashrc
#sed -i '/ROS_IP/d' $FILE
#echo "export ROS_IP=$IP" >> $FILE


# Configure network
echo "Assigning IP: $IP"
echo "WiFi SSID: $SSID"

# Add only if connection does not exist yet
if [ -z "$PROFILES" ]
then
  echo "Creating $SSID wifi profile"
  echo "Using interface $INTERFACE"
  nmcli connection add type wifi con-name $SSID ifname $INTERFACE ssid $SSID
fi

# Configure the connection
nmcli con mod $SSID 802-11-wireless.mode "infrastructure"
nmcli con mod $SSID 802-11-wireless-security.key-mgmt "wpa-psk"
nmcli con mod $SSID 802-11-wireless-security.psk "$MY_PASSWORD"
nmcli con mod $SSID ipv4.method "manual" ipv4.addresses $IP/24
nmcli con mod $SSID ipv4.gateway "192.168.200.250" ipv4.dns "8.8.8.8"
nmcli connection up $SSID

# Add user to dialout group
usermod -a -G dialout academy

# Clear history
rm ~/.bash_history
history -c
