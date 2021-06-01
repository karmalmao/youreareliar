#include <iostream>
#include <string>
#include <locale>


bool isValidHexCode(std::string hexcode)
{

    int uppercount = 0;
    int lowercount = 0;
    int digitcount = 0;
    
    if (hexcode.size() == 7 && hexcode[0] == '#')
    {
        for (char a : hexcode)
        {
            if (a > 64 && a < 71 || a > 47 && a < 58 || a > 96 && a < 103)
            {
                if (isupper(a)) { uppercount++; }
                if (islower(a)) { lowercount++; }
                if (isdigit(a)) { digitcount++; }
            }
        }
        if (uppercount + digitcount == 6 || lowercount + digitcount == 6)
        {
            return true;
        }
        else {return false;}
    }
    else { return false; }
}



int main()
{
    std::cout << isValidHexCode("#CD5C5C") << ": expected true" << std::endl;
    std::cout << isValidHexCode("#EAECEE") << ": expected true" << std::endl;
    std::cout << isValidHexCode("#eaecee") << ": expected true" << std::endl;
    std::cout << isValidHexCode("#CD5C58C") << ": expected false" << std::endl;
    std::cout << isValidHexCode("#CD5C5Z") << ": expected false" << std::endl;
    std::cout << isValidHexCode("#CD5C&C") << ": expected false" << std::endl;
    std::cout << isValidHexCode("#Cd5CdC") << ": expected false" << std::endl;
    std::cout << isValidHexCode("CD5C5C") << ": expected false" << std::endl;
}
