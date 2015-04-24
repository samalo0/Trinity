# Trinity v1.0

4/24/15
Stephen Maloney

This code is for an application that I developed to learn Linux, Qt, and the
Raspberry Pi 2.

This application runs on a 480x320 display in xwindows with no title bar, and
is designed to be auto-booted into. It essentially allows you to select one of
three patches using external switches or the touch screen; these three patches
switch Strymon Bigsky, Timeline, and Mobius presets, as well as setting two
relays which can switch an amp such as a Mesa Boogie Mark V: 25.

Additional tabs allow using the Timeline looper, editing the songs, and
setting up MIDI, saving the songs, etc.

To get it running and compiled, follow the instructions below.

Instructions:
------------
Download Rapbian from the main website. I used a  2015-02-16-raspian-wheezy
image, which is the latest.

On boot up into raspi-config:
----------------------------
1. Expand the filesystem
2. Change international options for correct timezone and keyboard
3. Change hostname
4. Enable SSH
5. Update raspi-config utility
6. reboot

On reboot, install required programs:
------------------------------------
RTMIDI (midi library used to open ports, send MIDI messages, etc):
apt-get install librtmidi1 librtmidi-dev librtmidi-dbg

Qt (Graphical interface):
apt-get install qtcreator

Unclutter (Used to hide cursor when running app):
apt-get install unclutter

Samba (Used to share files with windows PCs):
apt-get install samba

Run all updates:
---------------
apt-get update
apt-get upgrade
rpi-update (optional - this updates the kernel, if you are going to use
another kernel, such as the adafruit kernel to use a small touchscreen, this
is unneeded)

samba:
-----
Set this up if you want to get to files on your pi from your desktop PC. 
Edit the configuration file:
sudo nano /etc/samba/smb.conf

Scroll down to shares and add:
[pihome]
   comment= Pi Home
   path=/home/pi
   browseable=Yes
   writeable=Yes
   only guest=Yes
   create mask=0777
   directory mask=0777
   public=Yes
   force user = root

gpio:
----
I used wiringPi, a GPIO library, to access the GPIO of the Pi2 in order to
read three switches and set two relays.

I had to modify the library slightly to allow call-back functions to pass
a user data pointer. This way call-back functions (interrupt service routines)
can interact with the main GUI. 

compiling:
---------
Put the code in /home/pi/Trinity. Run qmake and make on it to build the app.
If you put it somewhere else, you will need to edit Trinity.cpp and change
the file paths for the saved and loaded files.

screen:
------
I used a PiTFT - 480x320 3.5" TFT + Touchscreen for this project.
http://www.adafruit.com/products/2097

To install it and get it working:
curl -SLs https://apt.adafruit.com/add | sudo bash
sudo apt-get install -y adafruit-pitft-helper
sudo adafruit-pitft-helper -t 35r

You also have to add one file to make xwindows work on boot up; the file is: 
sudo nano /usr/share/X11/xorg.conf.d/99-fbdev.conf 

Put the following in it:
Section "Device"  
  Identifier "myfb"
  Driver "fbdev"
  Option "fbdev" "/dev/fb1"
EndSection

Use raspi-config to tell the PI2 that you want to boot into xwindows on
startup.

autostart apps:
--------------
The final thing you might want to do is make it autostart and hide the cursor.
Edit the file:
sudo nano /etc/xdg/lxsession/LXDE-pi/autostart

And put into it:
@unclutter -idle 0.1 root
@/home/pi/Trinity/Trinity







