#!/usr/bin/env python3

class message:
    def __init__(self, message, key):
        self.__msg = message
        self.__key = key
        self.__encryption = self.__encrypt()
        self.__decryption = self.__decrypt()
    def get_encryption(self):
        return self.__encryption
    def get_decryption(self):
        return self.__decryption
    def __encrypt(self):
        alphabet = ' ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        msg = self.__msg.upper()
        cipher = ""
        i = 0
        for letter in msg:
            index = (alphabet.find(letter) + (alphabet.find(self.__key[i]))) % len(alphabet)
            cipher += alphabet[index]
            i += 1
            if i == len(self.__key):
                i = 0
        return cipher
    def __decrypt(self):
        alphabet = ' ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        msg = self.__msg.upper()
        plainText = ""
        i = 0
        for letter in msg:
            index = (alphabet.find(letter) - (alphabet.find(self.__key[i]))) % len(alphabet)
            plainText += alphabet[index]
            i += 1
            if i == len(self.__key):
                i = 0
        return plainText

msg = input("Message to encrypt/decrypt: ")
key = input("Cipher key word: ")
mode = input("Encrypt or decrypt? Enter 'e' or 'd': ")
code = message(msg, key)
if mode == 'e':
    print(code.get_encryption())
elif mode == 'd':
    print(code.get_decryption())
else:
    print("Invalid entry.")