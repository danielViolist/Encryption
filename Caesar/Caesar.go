package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

var alphabet = []string{" ", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"}
var selection string
var message string
var afterEncryptOrDecrypt []string
var shift int

func getIndex(msg string) int {
	for i, v := range alphabet {
		if string(v) == msg {
			return i
		}
	}
	return -1
}

func encrypt(msg string, shift int) []string {
	message := strings.ToUpper(msg)
	var ret []string
	for _, v := range message {
		index := getIndex(string(v))
		char := alphabet[(index+shift)%len(alphabet)]
		ret = append(ret, char)
	}
	return ret
}

func decrypt(msg string, shift int) []string {
	message := strings.ToUpper(msg)
	var ret []string
	for _, v := range message {
		index := getIndex(string(v))
		char := alphabet[(index-shift)%len(alphabet)]
		ret = append(ret, char)
	}
	return ret
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for true {
		fmt.Println("Encrypt, decrypt, or quit (enter 'e', 'd', or 'q'): ")
		fmt.Scanln(&selection)
		if selection == "Q" || selection == "q" {
			os.Exit(0)
		} else if selection == "E" || selection == "e" || selection == "d" || selection == "D" {
			fmt.Println("Enter the message: ")
			scanner.Scan()
			message = scanner.Text()
			fmt.Println("Enter the shift: ")
			fmt.Scanln(&shift)
			if selection == "E" || selection == "e" {
				afterEncryptOrDecrypt = encrypt(message, shift)
			} else {
				afterEncryptOrDecrypt = decrypt(message, shift)
			}
			fmt.Println(afterEncryptOrDecrypt)
		} else {
			fmt.Println("Please enter a valid selection as given in the instructions. Tisk tisk smh...")
		}
	}
}
