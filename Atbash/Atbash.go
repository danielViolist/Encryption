package main

import (
	"fmt"
	"strings"
)

func main() {
	for {
		var input string
		fmt.Print("Enter message: ")
		fmt.Scanln(&input)
		fmt.Println("\n" + change(input) + "\n")
	}
}

func change(msg string) string {
	message := strings.ToUpper(msg)
	result := ""
	mapping := map[string]string{"A": "Z", "B": "Y", "C": "X", "D": "W", "E": "V", "F": "U", "G": "T", "H": "S", "I": "R", "J": "Q",
		"K": "P", "L": "O", "M": "N", "N": "M", "O": "L", "P": "K", "Q": "J", "R": "I", "S": "H", "T": "G", "U": "F", "V": "E", "W": "D", "X": "C", "Y": "B", "Z": "A"}
	for _, let := range message {
		newLetter, found := mapping[string(let)]
		if !found {
			result += string(let)
			continue
		}
		result += string(newLetter)
	}
	return result
}
