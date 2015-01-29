#!/bin/bash

source common.sh

mkdir -p $BACKUP_DIR

if [ -d ~/public_html/Food ]; then
  if [ -e ~/public_html/Food/html/Userfile ]; then
    mesg "Backing up Userfile."
    cp ~/public_html/Food/html/Userfile ${BACKUP_DIR}/
  fi

  mesg "Removing ~/public_html/Food"
  rm -rf ~/public_html/Food ~/public_html/uw-food
fi

mesg "Backing up crontab..."
crontab -l > $CRON_FILE 2>/dev/null
if grep "no crontab" $CRON_FILE; then
  rm $CRON_FILE
else 
  # cron file found, remove the command and reinstall
  mesg "Removing crontab..."
  crontab -r
  sed "s@.*$COMMENT@@" $CRON_FILE | crontab -
fi


