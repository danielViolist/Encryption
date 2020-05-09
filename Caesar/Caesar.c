#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define SIZE 500
void encrypt(char result[], char message[], int shift, const char letters[]);
void decrypt(char result[], char messagep[], int shift, const char letters[]);
void toUpperCase(char msg[]);
int getIndex(char c, const char letters[]);
void makeAllEmpty(char msg[]);
int main()
{
    const char alphabet[] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char mode;
    char result[SIZE] = "none"; //arbitrary size
    char message[SIZE];
    int shift;
    while(true)
    {
        printf("Do you want to encrypt, decrypt, or quit? Enter 'e', 'd', or 'q': ");
        scanf("%c", &mode);
        if (mode == 'e' || mode == 'E')
        {
            printf("\nEnter the message to encrypt: ");
            fgets(message, SIZE-1, stdin);
            fgets(message, SIZE-1, stdin);
            printf("Enter the number of shifts: ");
            scanf("%d", &shift);
            encrypt(result, message, shift, alphabet);
            printf("\n\nEncrypted message:\n\n\n%s\n\n\n", result);
            scanf("%c", &mode);
        }
        else if (mode == 'd' || mode == 'D')
        {
            printf("\nEnter the message to decrypt: ");
            fgets(message, SIZE-1, stdin);
            fgets(message, SIZE-1, stdin);
            printf("Enter the number of shifts: ");
            scanf("%d", &shift);
            decrypt(result, message, shift, alphabet);
            printf("\n\nDecrypted message:\n\n\n%s\n\n\n", result);
            scanf("%c", &mode);
        }
        else if (mode == 'q' || mode == 'Q')
            break;
        else {
           scanf("%c", &mode);
           continue;
        }
    }
}

void encrypt(char result[], char message[], int shift, const char letters[])
{
    makeAllEmpty(result);
    toUpperCase(message);
    int index;
    for (int i = 0; i < strlen(message); i++)
    {
        if (getIndex(message[i], letters) != -1)
        {
            index = (getIndex(message[i], letters) + shift) % strlen(letters);
            result[i] = letters[index];
        }
        else {
            result[i] = message[i];
        }
    }
}
void decrypt(char result[], char message[], int shift, const char letters[])
{
    makeAllEmpty(result);
    toUpperCase(message); 
    int index;
    for (int i = 0; i < strlen(message); i++)
    {
        if (getIndex(message[i], letters) != -1)
        {
            index = (getIndex(message[i], letters) - shift) % strlen(letters);
            result[i] = letters[index];
        } 
        else {
            result[i] = message[i];
        }
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