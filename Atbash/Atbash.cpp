#include <iostream>

std::string encode(std::string aMessage)
{

}

std::string decode(std::string aMessage)
{

}

int main()
{
    std::cout << "Do you want to encode, decode, or quit? Enter \'E\' to encode, \'D\' to decode, or \'Q\' to quit." << std::endl;
    char c;
    std::cin >> c;
    while(true)
        {
        if(c == 'E' || c == 'e')
        {
            
        }
        else if(c == 'D' || c == 'd')
        {
            std::cout << "Enter the message you wish to decode\n";
            std::string msg;
            std::cin >> msg;
        }
        else if(c == 'Q' || c == 'q')
        {
            std::cout << "Deuces homie" << std::endl;
            return 0;
        }
    }
}