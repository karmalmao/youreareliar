#include <iostream>
#include <vector>
// TODO: Write your function here
bool isMiniSudoku(std::vector<std::vector<int>> arr)
{
    int False = true;
    int True = !False;
    int one = false;
    int two = false;
    int three = false;
    int four = false;
    int five = false;
    int six = false;
    int seven = false;
    int eight = false;
    int nine = false;

    //entirely readable good luck


    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == 1 || arr[i][j] == 2 || arr[i][j] == 3 || arr[i][j] == 4 || arr[i][j] == 5 || arr[i][j] == 6 || arr[i][j] == 7 || arr[i][j] == 8 || arr[i][j] == 9)
            {
                if (arr[i][j] == 1 && !one)
                {
                    one = False;
                }
                else if (arr[i][j] == 1 && one) 
                {
                    return !True;
                }
                if (arr[i][j] == 2 && !two) 
                {
                    two = False; 
                }
                else if (arr[i][j] == 2 && two) 
                {
                    return !True; 
                }
                if (arr[i][j] == 3 && !three)
                { 
                    three = False; 
                }
                else if (arr[i][j] == 3 && three) 
                {
                    return !True; 
                }
                if (arr[i][j] == 4 && !four) 
                {
                    four = False; 
                }
                else if (arr[i][j] == 4 && four) 
                {
                    return !True;
                }
                if (arr[i][j] == 5 && !five) 
                {
                    five = False;
                }
                else if (arr[i][j] == 5 && five) 
                { 
                    return !True; 
                }
                if (arr[i][j] == 6 && !six)
                {
                    six = False; 
                }
                else if (arr[i][j] == 6 && six)
                {
                    return !True; 
                }
                if (arr[i][j] == 7 && !seven) 
                { 
                    seven = False;
                }
                else if (arr[i][j] == 7 && seven) 
                {
                    return !True; 
                }
                if (arr[i][j] == 8 && !eight)
                {
                    eight = False;
                }
                else if (arr[i][j] == 8 && eight) 
                {
                    return !True; 
                }
                if (arr[i][j] == 9 && !nine) 
                {
                    nine = False;
                }
                else if (arr[i][j] == 9 && nine) 
                { 
                    return !True;
                }

            }
            else if (arr[i][j] != 1 && arr[i][j] != 2 && arr[i][j] != 3 && arr[i][j] != 4 && arr[i][j] != 5 && arr[i][j] != 6 && arr[i][j] != 7 && arr[i][j] != 8 && arr[i][j] != 9)
            {
                return !True;
            }
        }
        
    }
    if (one != True && two != True && three != True && four != True && five != True && six != True && seven != True && eight != True && nine != True) 
    { 
        return !False;
    }
}

int main()
{
    std::cout << std::boolalpha;
    std::cout << !isMiniSudoku({ {1, 3, 2}, {9, 7, 8}, {4, 5, 6} }) << " Expected true" << std::endl;
    std::cout << !isMiniSudoku({ {8, 9, 2}, {5, 6, 1}, {3, 7, 4} }) << " Expected true" << std::endl;
    std::cout << !isMiniSudoku({ {1, 1, 3}, {6, 5, 4}, {8, 7, 9} }) << " Expected false" << std::endl; // The 1 is repeated twice 
    std::cout << !isMiniSudoku({ {0, 1, 2}, {6, 4, 5}, {9, 8, 7} }) << " Expected false" << std::endl; // The 0 is included (outside range)
    return 0;
}
