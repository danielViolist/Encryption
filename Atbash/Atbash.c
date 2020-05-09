#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define SIZE 500
void encrypt(char result[], char msg[]);
void decrypt(char result[], char msg[]);
void toUpperCase(char msg[]);
void makeAllEmpty(char msg[]);
int main()
{
    char mode;
    char result[SIZE];
    char message[SIZE];
    while(true)
    {
        printf("Do you want to encrypt, decrypt, or quit? Enter 'e', 'd', or 'q': ");
        scanf("%c", &mode);
        if (mode == 'e' || mode == 'E')
        {
            printf("Enter the message to encrypt: ");
            fgets(message, SIZE-1, stdin);
            fgets(message, SIZE-1, stdin);
            encrypt(result, message);
            printf("Encrypted message:\n\n\n%s\n\n", result);
        }
        else if (mode == 'd' || mode == 'D')
        {
            printf("Enter the message to decrypt: ");
            fgets(message, SIZE-1, stdin);
            fgets(message, SIZE-1, stdin);
            decrypt(result, message);
            printf("Decrypted message:\n\n\n%s\n\n", result);
        }
        else if (mode == 'q' || mode == 'Q')
            break;
        else {
            scanf("%c", &mode);
            continue;
        }
    }
}
void encrypt(char result[], char msg[])
{
    makeAllEmpty(result);
    toUpperCase(msg);
    int temp;
    for (int i = 0; i < strlen(msg); i++)
    {
        if (msg[i] >= 65 && msg[i] < 97)
        {
            temp = msg[i] - 'A';
            result[i] = (char)('Z' - temp);
        } 
        else if (msg[i] >= 97 && msg[i] < 123)
        {
            temp = msg[i] - 'a';
            result[i] = (char)('z' - temp);
        } 
        else 
            result[i] = msg[i]; 
    }
}
void decrypt(char result[], char msg[])
{
    makeAllEmpty(result);
    toUpperCase(msg);
    int temp;
    for (int i = 0; i < strlen(msg); i++)
    {
        if (msg[i] >= 65 && msg[i] < 97)
        {
            temp = 'Z' - msg[i];
            result[i] = (char)('A' + temp);
        } 
        else if (msg[i] >= 97 && msg[i] < 123)
        {
            temp = 'z' - msg[i];
            result[i] = (char)('a' + temp);
        } 
        else 
            result[i] = msg[i]; 
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
void makeAllEmpty(char msg[])
{
    for (int i = 0; i < strlen(msg); i++)
        msg[i] = ' ';
}