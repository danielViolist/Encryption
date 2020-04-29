#include <string>
#include <iostream>

std::string alphabet = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";

std::string toUpperCase(std::string aMessage)
{
    for(int i = 0; i < aMessage.length(); i++)
    {
        aMessage[i] = std::toupper(aMessage[i]);
        std::cout << aMessage[i] << std::endl;
    }
    return aMessage;
}

std::string encrypt(std::string aMessage, std::string key)
{
    std::string cipher = "";
    int keyLoc = 0;
    for(int i = 0; i < aMessage.length(); i++)
    {
        int index = (alphabet.find(aMessage[i]) + alphabet.find(key[keyLoc])) % alphabet.length();
        cipher += alphabet[index];
        keyLoc += 1;
        if(keyLoc == key.length())
        {
            keyLoc = 0;
        }
    }
    return cipher;
}

std::string decrypt(std::string aMessage, std::string key)
{
    std::string plain = "";
    int keyLoc = 0;
    for(int i = 0; i < aMessage.length(); i++)
    {
        int index = (alphabet.find(aMessage[i]) - alphabet.find(key[keyLoc])) % alphabet.length();
        plain += alphabet[index];
        keyLoc += 1;
        if(keyLoc == key.length())
        {
            keyLoc = 0;
        }
    }
    return plain;
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
        std::cout << encrypt(toUpperCase(msg), toUpperCase(key)) << std::endl;
    }
    else if(c == 'D' || c == 'd')
    {
        std::cout << decrypt(toUpperCase(msg), toUpperCase(key)) << std::endl;
    }
    return 0;
}