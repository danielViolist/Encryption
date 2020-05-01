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

while(True):
    mode = input("Would you like to encrypt, decrypt, or quit? Enter 'e', 'd', or 'q': ")
    if mode == 'e' or mode == 'E':
        msg = input("Enter the message to encrypt: ")
        try: 
            key = int(input("Enter the number of shifts for the cipher: "))
        except Exception:
            print("\n\nOnly inter values are accepted for the key.\n\n")
            continue
        cipher_txt = message(msg, key)
        print("\n\nCipher Text: "+cipher_txt.get_encryption()+"\n\n")
    elif mode == 'd' or mode == 'D':
        msg = input("Enter the message to decrypt: ")
        try:
            key = int(input("Enter the number of shifts for cipher: "))
        except:
            print("\n\nOnly iteger values are accepted for the key.\n\n")
            continue
        plain_txt = message(msg, key)
        print("\n\nDecrypted Text: "+plain_txt.get_decryption()+"\n\n")
    elif mode == 'q' or mode == 'Q':
        print("\n\nGoodbye.\n\n")
        break
    else: 
        continue