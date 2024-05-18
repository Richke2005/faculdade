numberList = [1, 2, 3, 4]
stringList = ["Rich", "leonardo", "maria"]
heterogenousList = [1, 2, "richard", {"id": 1, "name": "richard"}]

print(2 in numberList)
print(5 in numberList)

for n in numberList:
    print(n)

for name in stringList:
    print(name)

for object in heterogenousList:
    print(object)

print(f"tamanho lista numberList: {format(len(numberList))}")