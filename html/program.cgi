#!/usr/bin/env python
import cgi, cgitb
import sys
sys.stderr = sys.stdout

form = cgi.FieldStorage() 


f = open('Userfile', 'a')

l = ['email', 'Vegetarian', 'Beef', 'Chicken', 'Pasta', 'Mexican', 
  'Asian', 'Indian', 'Cheese', 'Seafood']
s = reduce(lambda x, y: form.getvalue(x) + " " + y if x == 'email' else x + " " + y if form.getvalue(y) is not None else x, l)
f.write(s + "\n")
f.close()

print "Content-Type: text/html"
print
print '<title>Preferences Saved</title>'
print '<body>'
print 'Thank you for using Food. Your preferences have been saved and you will be emailed '
print 'every Sunday with your own personal menu of the food available on campus that matches your preferences.<br>'
print '</body>'

#print '<script>'
#print '  window.location.href = "redirect.html"'
#print '</script>'
