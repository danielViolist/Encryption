#!/usr/bin/env python3
#Caesar Cipher    
class message:
    def __init__(self, msg="abc", key=1):
        self.__message = msg
        self.__shift = key
        self.__encrption = self.__encrypt(self.__message)
        self.__decryption = self.__decrypt(self.__message)
    def get_message(self):
        return self.__message
    def get_encryption(self):
        return self.__encrption
    def get_decryption(self):
        return self.__decryption
    def __encrypt(self, msg):
        phrase = ""
        alphabet = ' ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        message = msg.upper()
        for letter in message:
            i = alphabet.find(letter)
            i = (i + self.__shift)%len(alphabet)
            phrase += alphabet[i]
        return phrase
    def __decrypt(self, msg):
        phrase = ""
        alphabet = ' ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        message = msg.upper()
        for letter in message:
            i = alphabet.find(letter)
            i = (i - self.__shift)%len(alphabet)
            phrase += alphabet[i]
        return phrase

msg = input("Message to decrypt or encrypt with the Ceasar Cipher: ")
try:
    key = int(input("Number of shifts for the cipher: "))
except Exception as e:
    print("Only integer values allowed for the key. Exiting.")
    exit()
mode = input("Would you like to encrypt or decrypt? Enter 'e' or 'd': ")
if mode == 'e':
    cipher_text = message(msg, key)
    cipher_text = cipher_text.get_encryption()
    print("Cipher Text: " + cipher_text)
elif mode == 'd':
    decoded_text = message(msg, key)
    decoded_text = decoded_text.get_decryption()
    print("Decoded text: " + decoded_text)
else:
    print("Please enter 'e' or 'd' to use this program.")
    exit()
print("Goodbye.")