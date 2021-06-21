#include <iostream>
#include <vector>

// TODO: Write the FindOdd function
int FindOdd(std::vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {

        int count = 0;

        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        if (count % 2 != 0)
            return arr[i];
    }
    return -1;
}


int main(int argc, char** argv)
{
    // TODO: write test code to verify your function works as expected
	std::vector<int> arr = { 1,1,2,2,3,3,4,5,5,6,6,7,7 };
	std::cout << FindOdd(arr) << std::endl;
    std::vector<int> arr2 = { 1,1,2,2,3,5,5,6,6,7,7 };
    std::cout << FindOdd(arr2) << std::endl;
    std::vector<int> arr3 = { 1,1,2,2,3,3,3,4,5,5,6,6,7,7 };
    std::cout << FindOdd(arr3) << std::endl;
    std::vector<int> arr4 = { 1,1,2,2,3,3,4,5,5,6,6,7,7 };
    std::cout << FindOdd(arr4) << std::endl;
    std::vector<int> arr5 = { 1,1,2,2,3,3,5,5,6,7,7 };
    std::cout << FindOdd(arr5) << std::endl;
    return 0;
}

