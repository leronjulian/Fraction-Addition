//===========================================================================
//                     Adding Two Fractions - Part 2
//                      Developed By: Leron Julian
//               PROGRAM COMPLETED PER PROGRAM SPECIFICATION
//===========================================================================

#include <iostream>
#include <string>
using namespace std;

int stroi(string number);
int greatestCommonDem(int num1, int num2);
void simplify(int &den3, int &num3, int &leading_Result, bool &print);
void addFractions(int num1, int den1, int num2, int den2, int &num3, int &den3, int &leading1, int &leading2, int &result_Leading, bool &print);


int main() {
    string fraction_One;
    string fraction_Two;
    
    cout << "Enter Fraction 1 -> ";
    cin >> fraction_One;
    
    cout << "Enter Fraction 2 -> ";
    cin >> fraction_Two;
    
    int num1, num2, result_Num;
    int den1, den2, result_Den;
    
    int leading_Num1, leading_Num2, result_Leading;
    
    char letter;
    int i = 0;
    string temp;
    string temp2;
    
    string leadingTemp;
    
    while (letter != '/')
    {
        letter = fraction_One[i];
        temp += letter;
        i++;
        
        if (letter == '/')
        {
            int j = i;
            for (j = i; j < fraction_One.size(); j++)
                temp2 += fraction_One[j];
        }
        
        if (letter == '(')
        {
            int k = i;
        
            for (k = 0; k < i - 1; k++)
                leadingTemp += fraction_One[k];
        }
    }
    
    i = 0;
    
    int size = temp.size();
    
    char tempChar;
    int count;
    string holder = temp;
    while (count < size)
    {
        tempChar = temp[count];
        if (tempChar == '(')
        {
            temp = "";
            for (int index = count; index < size; index++)
                temp += holder[index];
        }
        count++;
    }
    
    temp.erase(remove(temp.begin(),temp.end(),'/'),temp.end());
    temp.erase(remove(temp.begin(),temp.end(),'('),temp.end());
    temp2.erase(remove(temp2.begin(),temp2.end(),')'),temp2.end());
    
    num1 = stroi(temp);
    den1 = stroi(temp2);
    leading_Num1 = stroi(leadingTemp);
    
    temp = temp2 = leadingTemp = holder = "";
    letter = tempChar = ' ';
    
    while (letter != '/')
    {
        letter = fraction_Two[i];
        temp += letter;
        i++;
        
        if (letter == '/')
        {
            int j = i;
            for (j = i; j < fraction_Two.size(); j++)
                temp2 += fraction_Two[j];
        }
        
        if (letter == '(')
        {
            int k = i;
            
            for (k = 0; k < i - 1; k++)
                leadingTemp += fraction_Two[k];
        }
    }
    
    i = count = 0;
    
    size = temp.size();
    holder = temp;
    while (count < size)
    {
        tempChar = temp[count];
        if (tempChar == '(')
        {
            temp = "";
            for (int index = count; index < size; index++)
                temp += holder[index];
        }
        count++;
    }
    
    temp.erase(remove(temp.begin(),temp.end(),'/'),temp.end());
    temp.erase(remove(temp.begin(),temp.end(),'('),temp.end());
    temp2.erase(remove(temp2.begin(),temp2.end(),')'),temp2.end());

    num2 = stroi(temp);
    den2 = stroi(temp2);
    leading_Num2 = stroi(leadingTemp);

    bool print;
    
    int improper_Num1 = (leading_Num1*den1) + num1;
    int improper_Num2 = (leading_Num2*den2) + num2;
    
    addFractions(improper_Num1, den1, improper_Num2, den2, result_Num, result_Den, leading_Num1, leading_Num2, result_Leading, print);
    
    cout << endl;
    
    if (print == true)
        cout << "The sum of " << fraction_One << " and " << fraction_Two << " is " << result_Leading << "(" << result_Num << "/" << result_Den << ")" << endl;
    
    else
        cout << "The sum of " << fraction_One << " and " << fraction_Two << " is " << result_Num << "/" << result_Den << endl << endl;
    
    return 0;
}

//===========================================================================
//  This function converts strings to integers
//===========================================================================
int stroi(string number)
{
    int i;
    int n = 0;
    
    for(i = 0; number[i] >= '0' && number[i] <= '9'; i++)
        n = (10 * n) + (number[i] - '0');
    
    return n;
}

//===========================================================================
//  This function adds two fractions together and calls the other functions
//===========================================================================
void addFractions(int num1, int den1, int num2, int den2, int &num3, int &den3, int &leading1, int &leading2, int &result_Leading, bool &print)
{
    den3 = greatestCommonDem(den1,den2);
    
    den3 = (den1*den2) / den3;
    
    num3 = (num1)*(den3/den1) + (num2)*(den3/den2);
    
    simplify(den3,num3, result_Leading, print);
}

//===========================================================================
//  This function simplifies the fraction to its simpliest form
//===========================================================================
void simplify(int &den3, int &num3, int &leading_Result, bool &print)
{
    int common_factor = greatestCommonDem(num3,den3);
    
    den3 = den3/common_factor;
    num3 = num3/common_factor;
    
    if (num3 > den3)
    {
        int tempHolder = (num3/den3);
        int rem = (num3 % den3);
        num3 = rem;
    
        leading_Result = tempHolder;
        
        print = true;
    }
}

//===========================================================================
//  This function finds the greatest common denomenator of two fractions
//===========================================================================
int greatestCommonDem(int num1, int num2)
{
    if (num1 == 0)
        return num2;
    return greatestCommonDem((num2 % num1), num1);
}


