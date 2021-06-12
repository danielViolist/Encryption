#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define SIZE 500
void change(char result[], char msg[]);
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
        if (mode == 'e' || mode == 'E' || mode == 'D' || mode == 'd')
        {
            printf("Enter the message: ");
            fgets(message, SIZE-1, stdin);
            fgets(message, SIZE-1, stdin);
            change(result, message);
            printf("\n\n%s\n\n", result);
        }
        else if (mode == 'q' || mode == 'Q')
            break;
        else {
            scanf("%c", &mode);
            continue;
        }
    }
}
void change(char result[], char msg[])
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