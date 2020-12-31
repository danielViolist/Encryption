package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

var alphabet = []string{" ", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"}

func main() {
	var message string
	var selection string
	var password string
	scanner := bufio.NewScanner(os.Stdin)
	for {
		fmt.Println("Would you like to encrypt, decrypt, or quit (enter 'e', 'd', or 'q')?")
		fmt.Scanln(&selection)
		if selection == "Q" || selection == "q" {
			os.Exit(0)
		} else if selection == "E" || selection == "e" || selection == "d" || selection == "D" {
			fmt.Println("Enter the message: ")
			scanner.Scan()
			message = scanner.Text()
			fmt.Println("Enter the password:")
			scanner.Scan()
			password = scanner.Text()
			if selection == "E" || selection == "e" {
				encrypt(message, password)
			} else if selection == "d" || selection == "D" {
				decrypt(message, password)
			}
		} else {
			fmt.Println("Please enter a valid selection as given in the instructions. Tisk tisk smh...")
		}
	}
}

func getIndex(msg string) int {
	for i, v := range alphabet {
		if string(v) == msg {
			return i
		}
	}
	return -1
}

func encrypt(msg, pw string) {
	message, password := prepare(msg, pw)
	cipher := []string{}
	pwIndex := 0
	passw := []rune(password)
	for _, v := range message {
		index := (getIndex(string(v)) + getIndex(string(passw[pwIndex]))) % len(alphabet)
		char := alphabet[index]
		cipher = append(cipher, char)
		pwIndex++
		if pwIndex == len(passw) {
			pwIndex = 0
		}
	}
	fmt.Println("Encrypted message:", cipher)
}

func decrypt(msg, pw string) {
	message, password := prepare(msg, pw)
	pwIndex := 0
	cipher := []string{}
	passw := []rune(password)
	for _, v := range message {
		index := (getIndex(string(v)) - getIndex(string(passw[pwIndex]))) % len(alphabet)
		char := alphabet[index]
		cipher = append(cipher, char)
		pwIndex++
		if pwIndex == len(passw) {
			pwIndex = 0
		}
	}
	fmt.Println("Decrypted message:", cipher)
}

func prepare(msg, pw string) (string, string) {
	return strings.ToUpper(msg), strings.ToUpper(pw)
}
