## -*- coding: utf-8 -*-

import classes

t = classes.World()
t.set("Hi!")
print(t.greet())

t.many(['Good morning', 'Good afternoon', 'Good evening'])
print(t.greet())

# Warning: u'下午好' (VS 2015)
# Traceback (most recent call last):
#    File "py_classes.py", line 10, in <module>
#      print(t.greet())
#    File "C:\Program Files\Python37\lib\encodings\cp1251.py", line 19, in encode
#      return codecs.charmap_encode(input,self.errors,encoding_table)[0]
#  UnicodeEncodeError: 'charmap' codec can't encode character '\u55e8' in position 27: character maps to <undefined>
