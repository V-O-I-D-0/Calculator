#include <iostream>
#include <vector>
#include <sstream>
#include "windows.h"
#include <stdio.h> 
#include <conio.h>
#include <string.h> 
#include <regex>
#include <string>

using namespace std;

int resize() 
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 1000, 1000, TRUE);
    return 0;
}


int main()
{
    
    int preVal = 0;
    string equation;
    vector<string>pString;
    int accum = 0;

    vector<int>intVect;
    string opString;

    cout << "Enter your equation: ";
    getline(cin, equation);

    stringstream check1(equation);
    string indeterminate;

    int nums[2] = { 0,0 };
    char operators = '0';

    while (getline(check1, indeterminate, ' '))
    {
        pString.push_back(indeterminate);
    }

    //convert pString to int and operators
    regex rO("[0123456789]");
    regex rI("[+*/-]");

    stringstream resultI;
    regex_replace(ostream_iterator<char>(resultI), equation.begin(), equation.end(), rI, " ");

    stringstream resultO;
    regex_replace(ostream_iterator<char>(resultO), equation.begin(), equation.end(), rO, "");

    stringstream RItoIV(resultI.str());

    int number;
    while (RItoIV >> number)
        intVect.push_back(number);

    opString = resultO.str();

    accum = intVect[0] + preVal;
 

    for (int i = 1; i < intVect.size(); i++) 
    {
            nums[0] = accum;
            nums[1] = intVect[i];


        for (int j = 0; j < opString.length(); j++)
        {
            operators = opString[i - 1];

            for (int k = 0; k < (opString.length()); k++)
            {
                    switch (operators) 
                    {
                    case '+':
                       accum = nums[0] + nums[1];
                       break;
                    case '-':
                        accum = nums[0] - nums[1];
                        break;
                    case '*':
                        accum = nums[0] * nums[1];
                        break;
                    case '/':
                        accum = nums[0] / nums[1];
                        break;
                    case '%':
                        accum = nums[0] % nums[1];
                        break;
                    case '^':
                        accum = nums[0] ^ nums[1];
                        break;
                    case '0':
                        cout << "Error: No opertation has taken place.";
                        break;
                    default:
                        cout << "Error: Invalid operator";
                    }

            }    
        }
    }

    cout << accum;

    for (;;) 
    {
        switch (_getch()) 
        {
        case 27:
            return 0;
        }
    }
}


