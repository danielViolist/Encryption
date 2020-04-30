#!/usr/bin/env python3
#Vigenere Cipher
class message:
    def __init__(self, message, key):
        self.__msg = message
        self.__keyPhrase = key
        self.__encryption = self.__encrypt()
        self.__decryption = self.__decrypt()
    def get_encryption(self):
        return self.__encryption
    def get_decryption(self):
        return self.__decryption
    def __encrypt(self):
        alphabet = ' ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        mesg = self.__msg.upper()
        cipher = ""
        i = 0
        for letter in mesg:
            index = (alphabet.find(letter) + (alphabet.find(self.__keyPhrase[i]))) % len(alphabet)
            cipher += alphabet[index]
            i += 1
            if i == len(self.__keyPhrase):
                i = 0
        return cipher
    def __decrypt(self):
        alphabet = ' ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        msg = self.__msg.upper()
        plainText = ""
        i = 0
        for letter in msg:
            index = (alphabet.find(letter) - (alphabet.find(self.__keyPhrase[i]))) % len(alphabet)
            plainText += alphabet[index]
            i += 1
            if i == len(self.__keyPhrase):
                i = 0
        return plainText

while(True):
    mode = input("Would you like to encrypt, decrypt, or quit? Enter 'e', 'd', or 'q': ")
    if mode == 'e':
        msg = input("Enter the message to encrypt: ")
        key = input("Enter the key: ")
        key = key.upper()
        code = message(msg, key)
        print("\n\nEncrypted Message: "+code.get_encryption()+"\n\n")
    elif mode == 'd':
        msg = input("Enter the message to decrypt: ")
        key = input("Enter the key: ")
        key = key.upper()
        code = message(msg, key)
        print("\n\nDecrypted Message: "+code.get_decryption()+"\n\n")
    elif mode == 'q':
        print("\nGoodbye.")
        break
    else:
        continue