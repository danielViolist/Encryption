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
        try:
            char = original.get(letter)
            cipher += backwards.get(char)
        except Exception:
            cipher += letter
    return cipher

while(True):
    mode = input("Would you like to ecrypt, decrypt, or quit? Enter 'e', 'd', or 'q': ")
    if mode == 'e' or mode == 'd' or mode == 'E' or mode == 'D':
        msg = input("Enter the message to encrypt: ")
        print(encode(msg))
    elif mode == 'q' or mode == 'Q':
        break
    else:
        continue