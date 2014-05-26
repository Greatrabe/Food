#!/usr/bin/env python
import cgi, cgitb
import sys
sys.stderr = sys.stdout

form = cgi.FieldStorage() 

#print "Content-Type: text/html"
#print
#print '<title>Foo</title>'
#print '<body>'
#print 'Hello World<br>'

f = open('Userfile', 'a')

l = ['email', 'Vegetarian', 'Beef', 'Chicken', 'Pasta', 'Mexican', 
  'Asian', 'Indian', 'Cheese', 'Seafood']
l = map(lambda x: form.getvalue(x), l)
l = map(lambda x: 'off' if x is None else x, l)
f.write(reduce(lambda x, y: x + "," + y, l))
f.close()

print '<script>'
print '  window.location.href = "redirect.html"'
print '</script>'