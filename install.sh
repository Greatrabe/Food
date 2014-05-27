#!/bin/bash

START=`pwd`

mesg() {
	echo $@ 1>&2
}

if [ ! -d ~/public_html/Food ]; then
  mesg "Copying files..."
  mkdir -p ~/public_html/Food
  cp -r . ~/public_html/Food
fi

mesg "Creating symlink..."
cd ~/public_html
ln -s Food/html uw-food

mesg "Compiling send-mail..."
cd Food/send-mail
make
chmod 700 run

mesg "Compiling MenuInfo..."
cd ../menu-info
fsc MenuInfo.scala

cd ..
mesg "Getting current menu..."
scala -cp menu-info MenuInfo

mesg "Installing crontab..."
crontab cron.txt

