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
        "gender": "male",
        "email": "richard@gmail.com",
        "phone": "11947318237",
        "adress": "rua ines de castro",
    }
]
for person in peoples:
    person['another'] = 123

for person in peoples:
    print(person['another'])