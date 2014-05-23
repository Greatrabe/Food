#!/bin/bash

cp -r . ~/public_html/Food
ln -s ~/public_html/Food/html ~/public_html/uw-food

chmod 700 ~/public_html/Food/send-mail/run

crontab cron.txt
