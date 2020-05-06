#include <iostream>
#include <string>

char alphabet[] = {' ', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

std::string toUpper(std::string phrase)
{
    std::string uppercasePhrase;
    for(int i = 0; i < phrase.length(); i++)
    {
        uppercasePhrase += toupper(phrase[i]);
    }
    return uppercasePhrase;
}

void cipher(std::string msg, std::string key, char direction)
{
    int index;
    //TODO --- Actually do the cipher lol
    if(direction == 'e')
    {
        
    }
    else
    {
        
    }
    std::cout << std::endl;
}

int main()
{
    char selection;
    std::string msg;
    int msgLength;
    int keyLength;
    std::string key;
    while(true)
    {
        //Clearing the arrays
        msg = key = "";
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
            std::getline(std::cin, msg);
            std::cout << "Enter the key: ";
            std::getline(std::cin, key);
            msg = toUpper(msg);
            key = toUpper(key);
            cipher(msg, key, selection);
        }
    } 
}