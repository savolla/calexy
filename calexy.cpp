#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <regex>
using namespace std;

int b2d(string bin)
{
    // initialize power of two (-1)
    int counter = -1;
    // sum of 2^n + 2^n-1 etc
    int sum = 0;
    // calculate the decimal number of a binary
    for(int i=0;i<bin.size();i++)
    {
        counter += 1;
        if(bin[bin.size()-i-1] == '1')
        {
            sum += pow(2,counter);
        }
    }
    return sum;
}

//int shr(int howManyShifts, vector<char> binaryNumber)
//{
//    vector<char> tmp;
//    // fill the vector with 0s
//    for(int i=0;i<howManyShifts;i++)
//    {
//        tmp.push_back('0');
//    }
//    // remove the last element (I don't actually know the reason of this)
//    //binaryNumber.pop_back();
//
//    for(int i=0;i<binaryNumber.size();i++)
//    {
//        tmp.push_back(binaryNumber[i]);
//    }
//
//    // shift the number $howManyShifts times
//    for (int i=0;i<howManyShifts; i++)
//    {
//        binaryNumber.pop_back();
//    }
//
//    return b2d(binaryNumber);
//}

int main(void)
{
    vector<char> binaryNumber;  // for storing Binary numbers
    char c;                     // binary character
    string syntax;              // actual syntax
    float answer = 0;

    cout << "Welcome To calexy !\n\ntype help ;)\n";
    while(syntax != "exit" && syntax != "quit")
    {
        cout << ">> "; cin >> syntax;
        regex addPattern("(add)[(]([0-9a-z]*),([0-9a-z]*)[)]");
        regex subPattern("(sub)[(]([0-9]*),([0-9]*)[)]");
        regex mulPattern("(mul)[(]([0-9]*),([0-9]*)[)]");
        regex divPattern("(div)[(]([0-9]*),([0-9]*)[)]");
        regex b2dPattern("b2d[(]([0-9]*)[)]");
        smatch matchResult;

        if(syntax == "help")
        {
            cout << R"(
calexy Functions:
=================

+---------------------+ +--------------------------------------+
|        basic        | |           base convertion            |
+---------------------+ +--------------------------------------+
| add(a,b)   ->   a+b | | b2d(binary)   ->   binary to decimal |
| sub(a,b)   ->   a-b | | b2x(binary)   ->   binary to hex     |
| mul(a,b)   ->   a*b | | d2b(decimal)  ->   decimal to binary |
| div(a,b)   ->   a/b | | d2x(decimal)  ->   decimal to hex    |
+---------------------+ | x2b(hex)      ->   hex to binary     |
                        | x2d(hex)      ->   hex to decimal    |
                        +--------------------------------------+
)";
        }
        // clear
        else if(syntax == "clear" || syntax == "cls")
        {
            system("clear");
        }
        else if(syntax == "ans")
        {
            cout << answer << endl;
        }
        // add()
        else if(regex_search(syntax, addPattern))
        {
            regex_search(syntax, matchResult, addPattern);

            if(matchResult[2] == "ans")
            {
                answer = answer + stof(matchResult[3]);
            }
            else if(matchResult[3] == "ans")
            {
                answer = stof(matchResult[2]) + answer;
            }
            else
            {
                answer = stof(matchResult[2]) + stof(matchResult[3]);
            }
            cout << answer << endl;
        }
        // sub()
        else if(regex_search(syntax, subPattern))
        {
            regex_search(syntax, matchResult, subPattern);
            cout << stof(matchResult[2]) - stof(matchResult[3]) << endl;
        }
        // mul()
        else if(regex_search(syntax, mulPattern))
        {
            regex_search(syntax, matchResult, mulPattern);
            cout << stof(matchResult[2]) * stof(matchResult[3]) << endl;
        }
        // div()
        else if(regex_search(syntax, divPattern))
        {
            regex_search(syntax, matchResult, divPattern);
            cout << stof(matchResult[2]) / stof(matchResult[3]) << endl;
        }
        // b2d
        else if(regex_search(syntax, b2dPattern))
        {
            regex_search(syntax, matchResult, b2dPattern);
            cout << b2d(matchResult[1]) << endl;
        }
    }

    cout << "seeya :*\n";

    return 0;
}
