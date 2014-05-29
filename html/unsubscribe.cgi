#!/usr/bin/env python
import cgi, cgitb
import sys, os
sys.stderr = sys.stdout

with open('Userfile', 'r') as f:
  content = f.readlines()
  f.close()

email = os.environ['REMOTE_USER'] + "@uwaterloo.ca"
form = cgi.FieldStorage()


with open('Userfile', 'w') as f:
  for line in content:
    parts = line.split(" ")
    if email != parts[0]:
      f.write(line)
  f.close()


print "Content-Type: text/html"
print
print '<title>You have been unsubscribed</title>'
print '<body>'
print ':('
print '</body>'
