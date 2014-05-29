#!/usr/bin/env python
import sys, os
sys.stderr = sys.stdout

userid = os.environ['REMOTE_USER']

found = False
with open('Userfile', 'r') as f:
  content = f.readlines()
  for line in content:
    parts = line.split(" ")
    email = userid + "@uwaterloo.ca"
    if email == parts[0]:
      found = True
      break
  f.close()

with open('../food-types.txt', 'r') as f:
  content = f.readlines()
  f.close()


print "Content-Type: text/html"
print
print '<title>Sign in</title>'
print '<body>'
print '  <p>Hello ' + userid + '!'
print '  <form action="write-preferences.cgi" method="post" enctype="multipart/form-data">'
print '    <p> Please enter your preferences here and click submit. Your FOOD is on the way!</p>'

ctr = 1
for i in content:
  typ = i.split(', ')[0]
  parts = line.rstrip().split(" ")

  checked = ""
  if found == True and len(parts) > ctr and parts[ctr] == typ:
    checked = "checked"
    ctr += 1

  print ('    <p><input type="checkbox" ' + checked + ' name="' + typ + '"/> ' + typ + '</p>\n')

print '    <p><input type="submit" value="Submit"/></p>'
print '  </form>'
print '  <form action="unsubscribe.cgi" method="post" enctype="multipart/form-data">'
print '    <input type="submit" value="Unsubscribe"</p>'
print '  </form>'
print '</body>'
