#include <iostream>
#include <string>

bool isPalindrome(std::string string)
{
    bool isPalindrome = true;
    for (uint i = 0; i < (string.length() + 1)/2; i++)
    {
        // std::cout << string[i] << " = " << string[string.length() -1 -i] << std::endl;
        if(string[i] != string[string.length() - 1 - i])
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "ERROR::Usage " << argv[0] << " <input>" << std::endl;
        return -1;
    }

    const char* input = argv[1];
    const uint inputlength = strlen(input);

    std::string longestPalindrome = std::string("");
    
    for (uint i = 0; i < inputlength ; i++)
    {
        std::string subString = std::string(input, i+1);
        for (uint j = 0; j < i; j++)
        {
            std::string subSubstring = subString.substr(j, std::string::npos);
            if (isPalindrome(subSubstring) && subSubstring.length() > longestPalindrome.length())
            {
                longestPalindrome = subSubstring;
                break;
            }
        }
    }

    std::cout << longestPalindrome << std::endl;
}