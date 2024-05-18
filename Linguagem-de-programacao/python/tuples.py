tuple1 = ('geeks', 'for')
tuple2 = 3, 4
tuple3 = 'geeks', 'for', 3, 4
list1 = [tuple1, tuple2, tuple3]

#this is not right
#tuple2[0] = 4

#this is right
list1[0] = 4

print (tuple1)
print (tuple2)
print (tuple3)
print (list1)