START=`pwd`

mesg() {
  echo "$@" 1>&2
}

BACKUP_DIR="$HOME/public_html/backup/Food"
CRON_FILE="${BACKUP_DIR}/cron.txt"
COMMENT="# Food - get menu and send email"
