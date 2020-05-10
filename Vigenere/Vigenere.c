#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define SIZE 500
void encrypt(char result[], char message[], char key[], const char letters[]);
void decrypt(char result[], char messagep[], char key[], const char letters[]);
void toUpperCase(char msg[]);
int getIndex(char c, const char letters[]);
void makeAllEmpty(char msg[]);
int main()
{
    const char alphabet[] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char mode;
    char result[SIZE]; 
    char message[SIZE];
    char key[SIZE];
    while(true)
    {
        printf("Do you want to encrypt, decrypt, or quit? Enter 'e', 'd', or 'q': ");
        scanf("%c", &mode);
        if (mode == 'e' || mode == 'E')
        {
            makeAllEmpty(key);
            printf("\nEnter the message to encrypt: ");
            fgets(message, SIZE-1, stdin);
            fgets(message, SIZE-1, stdin);
            printf("Enter the key: ");
            fgets(key, SIZE-1, stdin);
            encrypt(result, message, key, alphabet);
            printf("\n\nEncrypted message:\n\n\n%s\n\n", result);
        }
        else if (mode == 'd' || mode == 'D')
        {
            makeAllEmpty(key);
            printf("\nEnter the message to decrypt: ");
            fgets(message, SIZE-1, stdin);
            fgets(message, SIZE-1, stdin);
            printf("Enter the key: ");
            fgets(key, SIZE-1, stdin);
            decrypt(result, message, key, alphabet);
            printf("\n\nDecrypted message:\n\n\n%s\n\n", result);
        }
        else if (mode == 'q' || mode == 'Q')
            break;
        else {
           scanf("%c", &mode);
           continue;
        }
    }
    return 0;
}

void encrypt(char result[], char message[], char key[], const char letters[])
{
    makeAllEmpty(result);
    toUpperCase(message);
    toUpperCase(key);
    int index;
    int keyIndex = 0;
    for (int i = 0; i < strlen(message); i++)
    {
        if (getIndex(message[i], letters) != -1)
        {
            index = (getIndex(message[i], letters) + getIndex(key[keyIndex], letters)) % strlen(letters);
            result[i] = letters[index];
        }
        else {
            result[i] = message[i];
        }
        keyIndex++;
        if (keyIndex == strlen(key)-1) {
            keyIndex = 0; }
    }
}
void decrypt(char result[], char message[], char key[], const char letters[])
{
    makeAllEmpty(result);
    toUpperCase(message); 
    toUpperCase(key);
    int index;
    int keyIndex = 0;
    for (int i = 0; i < strlen(message); i++)
    {
        if (getIndex(message[i], letters) != -1)
        {
            index = (getIndex(message[i], letters) - getIndex(key[keyIndex], letters)) % strlen(letters);
            result[i] = letters[index];
        }
        else {
            result[i] = message[i];
        }
        keyIndex++;
        if (keyIndex == strlen(key)-1)
            keyIndex = 0;
    }
}
void toUpperCase(char msg[])
{
    int msgSize = strlen(msg);
    for (int i = 0; i < msgSize; i++)
    {
        msg[i] = toupper(msg[i]);
    }
}
int getIndex(char c, const char letters[])
{
    for (int i = 0; i < strlen(letters); i++)
    {
        if (letters[i] == c)
            return i;
    }
    return -1;
}
void makeAllEmpty(char msg[])
{
    for (int i = 0; i < strlen(msg); i++)
        msg[i] = ' ';
}