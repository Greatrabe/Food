#!/bin/bash

START=`pwd`

mesg() {
  echo "$@" 1>&2
}

checkInstalled() {
  while [ $# -gt 0 ]; do
    if ! which "$1"; then
      mesg "Installation requires $1. Please install $1 then retry."
      exit 1
    fi
    shift
  done
}

checkInstalled scala fsc make g++ crontab

if [ -d ~/public_html/Food ]; then
  mesg "Food already installed. Uninstalling..."
  ./uninstall.sh
  RVAL=$?
  if [ "$RVAL" -ne 0 ]; then
    mesg "Uninstall failed."
    exit 1
  fi
fi

mesg "Copying files..."
mkdir -p ~/public_html/Food
cp -r . ~/public_html/Food

mesg "Creating symlink..."
cd ~/public_html
ln -sf Food/html uw-food

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

if [ -e ${START}/Userfile ]; then
  mesg "Installing Userfile..."
  cp ${START}/Userfile html/
fi


