#include <iostream>
#include "LinkedList.h"

int main(int argc, char** argv)
{
    LinkedList<int> myList = { 10, 20, 30, 40, 50};

   
    // loop through the list using our iterators via for loop
    for (auto iter = myList.begin(); iter != myList.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }





    myList.PushBack(18);
    myList.PopFront();
    std::cout << std::endl;
    // loop through the LinkedList using range-based-for
    // requires begin and end methods to be implemented.

}
