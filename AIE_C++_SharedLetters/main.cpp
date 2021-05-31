#include <iostream>
// TODO:
// Create a function that returns the number of characters shared between two words.
int SharedLetters(std::string w1, std::string w2)
{
    int count = 0;
    for (int i = 0; i < w1.length(); i++)
    {
        for (int j = 0; j < w2.length(); j++)
        {
            if (w1[i] == w2[j] && w1[i] != ' ' && w2[j] != ' ')
            {
                count++;
                w1.replace(i, 1, " ");
                w2.replace(j, 1, " ");
            }
        }
    }
    return count;
}
int main()
{
    std::cout << SharedLetters("apple", "meaty") << std::endl; // 2
    std::cout << SharedLetters("fan", "forsook") << std::endl; // 1
    std::cout << SharedLetters("fanf", "forsook") << std::endl; // 1
    std::cout << SharedLetters("fanf", "forsookf") << std::endl; // 2
    std::cout << SharedLetters("fan", "forsookf") << std::endl; // 1
    std::cout << SharedLetters("spout", "shout") << std::endl; // 4
}