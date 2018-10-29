/*
Name: Faizan Ahmad
Creation Date: 28/10/2018
Problem Description: 
    function having one integer parameter ‘N’ as size of diamond and displays the following shape.
*/
# include <iostream>
using namespace std;

void printDiamond(int size);

int main()
{
    int size;
    cout << "Enter size of Diamond: ";
    cin >> size;
    
    printDiamond(size);
    
    return 0;
}

void printDiamond(int size)
{
    int stars = 1, spaces = size;

    for (spaces; spaces > 0; spaces--)
    {
        for (int i = 0; i < spaces; i++)
        {
            cout << " ";
        }
        for (int i = 0; i < stars; i++)
        {
            cout << "*";
        }
        cout << endl;
        stars += 2;
    }

    for (stars; stars > 0; stars-=2)
    {
        for (int i = 0; i < spaces; i++)
        {
            cout << " ";
        }
        for (int i = 0; i < stars; i++)
        {
            cout << "*";
        }
        cout << endl;
        spaces++;
    }
}
