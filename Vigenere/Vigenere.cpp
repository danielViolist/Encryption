#include <string>
#include <iostream>

std::string alphabet = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";

std::string toUpperCase(std::string aMessage)
{
    for(int i = 0; i < aMessage.length(); i++)
    {
        aMessage[i] = std::toupper(aMessage[i]);
    }
    return aMessage;
}

std::string encrypt(std::string aMessage, std::string key)
{
    std::string cipher = "";
    for(int i = 0; i < aMessage.length(); i++)
    {
        int index = 
    }
}

std::string decrypt(std::string aMessage, std::string key)
{
    
}

int main()
{
    std::cout << "Message to encrypt/decrypt: ";
    std::string msg;
    std::cin >> msg;
    std::cout << "Cipher key word: ";
    std::string key;
    std::cin >> key;
    std::cout << "Encrypt or decrypt? Enter \'e\' or \'d\': ";
    char c;
    std::cin >> c;
    if(c == 'E' || c == 'e')
    {
        std::cout << encrypt(toUpperCase(msg), key);
    }
    else if(c == 'D' || c == 'd')
    {
        std::cout << decrypt(toUpperCase(msg), key);
    }
    return 0;
}