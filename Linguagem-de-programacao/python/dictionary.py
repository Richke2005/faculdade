peoples = [
    {
        "name": "richard",
        "age": 0,
        "gender": "male",
        "email": "richard@gmail.com",
        "phone": "11947318237",
        "adress": "rua ines de castro",
    },
    {
        "name": "noah",
        "age": 0,
        "gender": "female",
        "email": "richard@gmail.com",
        "phone": "11947318237",
        "adress": "rua ines de castro",
    }
]

#printing the list
for person in peoples:
    print("-----------------------------------------")
    print(person)
    print("-----------------------------------------")

#searching specific attributes
for person in peoples:
    print(person["gender"])
print("\n")

#verifying the existence of an attribute in a list 
print("verifying the existence of an attribute in a list: ")
for person in peoples:
    print("name" in person)
    if "name" in person:
        print(person.get("name"))


#adding another attribute in the list
for person in peoples:
    person['another'] = 123

for person in peoples:
    print(person['another'])

dicTest = {
        "name": "noah",
        "age": 0,
        "gender": "female",
        "email": "richard@gmail.com",
        "phone": "11947318237",
        "adress": "rua ines de castro",
}
#printting the dictionary keys
keys = dicTest.keys()
#printing the dictionary values
values = dicTest.values()
#printing the dictionary items
object = dicTest.items()

print("name" in keys)
print("name" in dicTest)
print("noah" in values)