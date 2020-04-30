#include <string>
#include <iostream>

std::string encode(std::string aMessage, int messageSize)
{
    std::string encodedMsg = "";
    for(int i = 0; i < messageSize; i++)
    {
        if(aMessage[i] >= 65 && aMessage[i] < 97)
        {
            int temp = aMessage[i] - 'A';
            encodedMsg += ('Z' - temp);
        }
        else if(aMessage[i] >= 97 && aMessage[i] < 123)
        {
            int temp = aMessage[i] - 'a';
            encodedMsg += ('z' - temp);
        }
        else
        {
            encodedMsg += aMessage[i];
        }
    }
    return encodedMsg;
}

std::string decode(std::string aMessage, int messageSize)
{
    std::string decodedMsg = "";
    for(int i = 0; i < messageSize; i++)
    {
        if(aMessage[i] >= 65 && aMessage[i] < 97)
        {
            int temp = 'Z' - aMessage[i];
            decodedMsg += ('A' + temp);
        }
        else if(aMessage[i] >= 97 && aMessage[i] < 123)
        {
            int temp = 'z' - aMessage[i];
            decodedMsg += ('a' + temp);
        }
        else
        {
            decodedMsg += aMessage[i];
        }
    }
    return decodedMsg;
}

int main()
{
    while(true)
    {
        std::cout << "Do you want to encode, decode, or quit? Enter \'E\' to encode, \'D\' to decode, or \'Q\' to quit." << std::endl;
        std::string c;
        std::getline(std::cin, c);
        if(c[0] == 'E' || c[0] == 'e')
        {
            std::cout << "Enter the message you wish to encode\n";
            std::string msg;
            std::getline(std::cin, msg);
            std::cout << encode(msg, msg.length()) << std::endl;
        }
        else if(c[0] == 'D' || c[0] == 'd')
        {
            std::cout << "Enter the message you wish to decode\n";
            std::string msg;
            std::getline(std::cin, msg);
            std::cout << decode(msg, msg.length()) << std::endl;
        }
        else if(c[0] == 'Q' || c[0] == 'q')
        {
            std::cout << "Deuces homie" << std::endl;
            return 0;
        }
    }
}