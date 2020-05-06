#include <iostream>

char alphabet[] = {' ', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int toUpper(char phrase[])
{
    int i;
    for(i = 0; i < 1024; i++)
    {
        if(phrase[i] == 0)
        {
            break;
        }
        phrase[i] = toupper(phrase[i]);
    }
    return i;
}

void cipher(char msg[], int msgLength, char key[], int keyLength, char direction)
{
    int index;
    if(direction == 'e')
    {
        for(int i = 0; i < msgLength; i++)
        {

        }
    }
    else
    {
        for(int i = 0; i < msgLength; i++)
        {

        }
    }
    std::cout << std::endl;
}

int main()
{
    char selection;
    char msg[1024];
    int msgLength;
    int keyLength;
    char key[1024];
    while(true)
    {
        //Clearing the arrays
        for(int i = 0; i < 1024; i++)
        {
            msg[i] = key[i] = 0;
        }
        msgLength = keyLength = 0;
        std::cout << "Would you like to encrypt, decrypt, or quit? Enter 'e', 'd', or 'q': " << std::endl;
        std::cin >> selection;
        std::cin.ignore();
        if(selection == 'q')
        {
            std::cout << "Goodbye" << std::endl;
            exit(0);
        }
        else if(selection == 'e' || selection == 'd')
        {
            std::cout << "Enter the message: ";
            std::cin.getline(msg, 1024);
            std::cout << "\nEnter the key: ";
            std::cin.getline(key, 1024);
            msgLength = toUpper(msg);
            keyLength = toUpper(key);
            cipher(msg, msgLength + 1, key, keyLength + 1, selection);
        }
    } 
}