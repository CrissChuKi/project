#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

string get_number(); //Initialize loop for credit number 
char Not_valid();    //Initialization
char if_valid(string b, string number, int array, int mul, int add);    //Initialize loops for x card 

int main(void)
{
    string number = get_number(); //Get the credit number of user
    int array = strlen(number);    //Get the length of the number

    if (array == 15 && (number[0] == '3' && (number[1] == '4' || number[1] == '7')))
    {
        if_valid("AMEX\n", number, array, 1, 0);    //Check validity of the credit card
        return 0;
    }
    else if (array == 16 && (number[0] == '5' && (number[1] == '1' || number[1] == '2' || number[1] == '3' || number[1] == '4' || number[1] == '5')))
    {
        if_valid("MASTERCARD\n", number, array, 0, 1);    //Check validity of the card
        return 0;
    }    
    else if ((array == 13 || array == 16) && number[0] == '4')
    {
        if (array == 13)
        {
            if_valid("VISA\n", number, array, 1, 0);    //Check validity of the card
            return 0;
        }
        else if (array == 16)
        {
            if_valid("VISA\n", number, array, 0, 1);    //Check validity of the card
            return 0;
        }
    }
    else
    {
        Not_valid();    //Prompt that the card is not valid
    }
}

string get_number(void)    //Get a valid number from user input
{
    string i;
    int c = 0;    //Initialize count for letter
    int n;    
    do    //Loop to get the right input
    {
        i = get_string("Number: ");
        n = strlen(i);
        for (int j = 0; j<n;j++)    //Check if a letter was in the number, is so put the count down
        {
            if(isalpha(i[j]) || ispunct(i[j]) || isspace(i[j]))
            {
                c--;
            }
        }
    }while((n != 13 || n != 15 || n != 16) && c != 0);
    return i;
}

char Not_valid(void)    //Prompt that the card is not valid
{
    char i = printf("INVALID\n");
    return i;
}

char if_valid(string b, string number, int array, int mul, int add)    //Check the validity of the card with card name,
{                                                                      //right number array, modifier for * and +
    int d = 0;    //Start count for multiplication
    int e = 0;    //Start count for addition
    char f;        //return from the function valid or not
    for (int i = mul; i < array; i = i+2)
    {
        int c = (number[i]-48)*2;    //Get the number
        if(c > 9)
        {
            e = e + ((c%10)+1);
        }
        else
        {
            e = e+c;
        }
    }
    for (int i = add; i < array; i = i+2)
    {
        d = (d + number[i])-48;    //addition each x digit from number starting from second last
    }
    if(((e+d)%10) == 0)
    {
        f = printf("%s", b); //print the card name
    }
    else
    {
        f = Not_valid();    //print the not validity of the card
    }
    return f;   
}
