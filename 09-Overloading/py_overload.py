from overload import Example

e = Example()

e.do_it()
print(e)
print(e.do_it(2))
e.do_it('Hallo')
print(e)

print('------')

print(e.make_it('xxx'), e)
print(e.make_it('abc', 2), e)
print(e.make_it('xyz', 3, 'abc'), e)
print(e.make_it('mnk', 4), e)
