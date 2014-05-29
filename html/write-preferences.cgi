#!/usr/bin/env python
import cgi, cgitb
import sys, os
sys.stderr = sys.stdout

with open('../food-types.txt', 'r') as f:
  content = f.readlines()
  l = []
  for i in content:
    parts = i.split(', ')
    l.append(parts[0])
  f.close()

with open('Userfile', 'r') as f:
  content = f.readlines()
  f.close()

email = os.environ['REMOTE_USER'] + "@uwaterloo.ca"
form = cgi.FieldStorage()


s = reduce(lambda x, y: x + " " + y if form.getvalue(y) is not None else x, l, "")
s = email + s + "\n"
exists = False

with open('Userfile', 'w') as f:
  for line in content:
    parts = line.split(" ")
    if email == parts[0]:
      exists = True
      f.write(s)
    else:
      f.write(line)
  if exists == False:
    f.write(s)
  f.close()


print "Content-Type: text/html"
print
print '<title>Preferences Saved</title>'
print '<body>'
print 'Thank you for using Food. Your preferences have been saved and you will be emailed '
print 'every Sunday with your own personal menu of the food available on campus that matches your preferences.<br>'
print '</body>'
