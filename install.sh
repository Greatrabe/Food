#!/bin/bash

source common.sh

mesg "Uninstalling previously installed copy of Food..."
./uninstall.sh
RVAL=$?
if [ "$RVAL" -ne 0 ]; then
  mesg "Uninstall failed."
  exit 1
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
CRON="0 0 * * 0 cd ~/public_html/Food && `which scala` -cp ~/public_html/Food/menu-info MenuInfo && ./send-mail/run ${COMMENT}"
if [ -e ${CRON_FILE} ]; then
  if grep "${COMMENT}" $CRON_FILE 1>/dev/null; then
    mesg "Updating cron to reflect new command..."
    sed -i "s@^*${COMMENT}\$@${CRON}@" ${CRON_FILE}
  else # did not find the correct line in the cron file - never been installed
    mesg "Adding new command to cron..."
    echo "$CRON" >> ${CRON_FILE}
  fi
else
  # there is no cron file, make it
  mesg "Creating cron..."
  echo "$CRON" >> ${CRON_FILE}
fi
crontab ${CRON_FILE}

if [ -e ${START}/Userfile ]; then
  mesg "Installing Userfile..."
  cp ${START}/Userfile html/
elif [ -e ${BACKUP_DIR}/Userfile ]; then
  mesg "Installing Backup Userfile..."
  cp ${BACKUP_DIR}/Userfile html/
fi


