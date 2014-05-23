#!/bin/bash

START=`pwd`

mesg() {
	echo $@ 1>&2
}

mesg "Removing ~/public_html/Food"
rm -rf ~/public_html/Food ~/public_html/uw-food

mesg "Removing crontab..."
crontab -r

