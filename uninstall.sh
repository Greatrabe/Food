#!/bin/bash

START=`pwd`

mesg() {
	echo $@ 1>&2
}

mesg "Backing up Userfile."
cp ~/public_html/Food/html/Userfile .

mesg "Removing ~/public_html/Food"
rm -rf ~/public_html/Food ~/public_html/uw-food

mesg "Removing crontab..."
crontab -r

