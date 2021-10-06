import string
import random

uppercase_letters = list(string.ascii_uppercase)
lowercase_letters = list(string.ascii_lowercase)
punctuations = list(string.punctuation)

characters = []

characters.extend(lowercase_letters)
characters.extend(uppercase_letters)
characters.extend(punctuations)

length = int(input('Enter the length of the password : '))

password = ''.join(random.choice(characters) for _ in range(length))

print("Generated password is : ", password)