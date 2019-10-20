import member

m1 = member.SomeClass('Pavel')
print(f'name = {m1.name}')
m1.name = 'Gunther'
print(f'name = {m1.name}')

m1.number = 7 + 1 / 3
print(f'number = {m1.number}')
