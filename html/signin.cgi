#!/usr/bin/env python
import sys
sys.stderr = sys.stdout

with open('../food-types.txt', 'r') as f:
  content = f.readlines()

print "Content-Type: text/html"
print
print '<title>Sign in</title>'
print '<body>'
print '  <form action="write-preferences.cgi" method="post" enctype="multipart/form-data">'
print '    <p> Please enter your email here. Your FOOD is on the way!</p>'
print '    <p> email: <input type="text" name="email"/></p>'

for i in content:
  parts = i.split(', ')
  print ('    <p><input type="checkbox" name="' + parts[0] + '"/> ' + parts[0] + '</p>\n')

print '    <p><input type="submit" value="Submit"/></p>'
print '  </form>'
print '</body>'
