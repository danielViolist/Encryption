#!/usr/bin/env python3

def encode(msg):
    original = {"A": 1, "B": 2, "C": 3, "D": 4, "E": 5, "F": 6, "G": 7, "H": 8, "I": 9, "J": 10, "K": 11, "L": 12, "M": 13, "N": 14, "O": 15, "P": 16, "Q": 17, "R": 18,
    "S": 19, "T": 20, "U": 21, "V": 22, "W": 23, "X": 24, "Y": 25, "Z": 26}
    backwards = {26: "A", 25: "B", 24: "C", 23: "D", 22: "E", 21: "F", 20: "G", 19: "H", 18: "I", 17: "J", 16: "K", 15: "L", 14: "M", 13: "N", 12: "O", 11: "P", 10: "Q",
     9: "R", 8: "S", 7: "T", 6: "U", 5: "V", 4: "W", 3: "X", 2: "Y", 1: "Z"}
    cipher = ""
    msg = msg.upper()
    for letter in msg:
        if letter == " ":
            cipher += " "
            continue
        char = original.get(letter)
        cipher += backwards.get(char)
    return cipher
def decode(msg):
    original = {"Z": 1, "Y": 2, "X": 3, "W": 4, "V": 5, "U": 6, "T": 7, "S": 8, "R": 9, "Q": 10, "P": 11, "O": 12, "N": 13, "M": 14, "L": 15, "K": 16, "J": 17, "I": 18,
    "H": 19, "G": 20, "F": 21, "E": 22, "D": 23, "C": 24, "B": 25, "A": 26}
    backwards = {26: "Z", 25: "Y", 24: "X", 23: "W", 22: "V", 21: "U", 20: "T", 19: "S", 18: "R", 17: "Q", 16: "P", 15: "O", 14: "N", 13: "M", 12: "L", 11: "K", 10: "J",
     9: "I", 8: "H", 7: "G", 6: "F", 5: "E", 4: "D", 3: "C", 2: "B", 1: "A"}
    cipher = msg.upper()
    msg = ""
    for letter in cipher:
        if letter == " ":
            msg += " "
            continue
        char = original.get(letter)
        msg += backwards.get(char)
    return msg

while(True):
    mode = input("Would you like to ecrypt, decrypt, or quit? Enter 'e', 'd', or 'q': ")
    if mode == 'e':
        msg = input("Enter the message to encrypt: ")
        print(encode(msg))
        pass
    elif mode == 'd':
        msg = input("Enter the message to decode: ")
        print(decode(msg))
        pass
    elif mode == 'q':
        break
    else:
        continue