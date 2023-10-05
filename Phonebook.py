# Create: O(1)
phonebook = {
    'A': {'Alice': '123-456-7890'},
    'B': {'Bob': '987-654-3210'},
    'C': {'Charlie': '555-555-5555'},
}
print("Create operation completed.\n")

# Add: O(1)
def add_contact(phonebook, letter, name, phone):
    if letter not in phonebook:
        phonebook[letter] = {}
    phonebook[letter][name] = phone

add_contact(phonebook, 'D', 'David', '111-222-3333')
print("Add operation completed.\n")

# Search: O(1)
search_letter = 'B'
search_name = 'Bob'
if search_letter in phonebook and search_name in phonebook[search_letter]:
    print(f"Search operation completed. Phone for {search_name}: {phonebook[search_letter][search_name]}\n")
else:
    print(f"Search operation completed. {search_name} not found.\n")

# Iteration: O(N), where N is the number of key-value pairs
print("Iteration operation completed.\n")
for letter, contacts in phonebook.items():
    for name, phone in contacts.items():
        print(f"Name: {name}, Phone Number: {phone}")
print()

# Delete: O(1)
delete_letter = 'C'
delete_name = 'Charlie'
if delete_letter in phonebook and delete_name in phonebook[delete_letter]:
    del phonebook[delete_letter][delete_name]
    print(f"Delete operation completed. {delete_name} has been deleted.\n")
else:
    print(f"Delete operation completed. {delete_name} not found.\n")
