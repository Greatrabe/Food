#!/bin/bash

START=`pwd`

cp -r . ~/public_html/Food

cd ~/public_html
ln -s Food/html uw-food

cd Food/send-mail
make
chmod 700 run

cd ../menu-info
fsc MenuInfo.scala

cd ..
crontab cron.txt