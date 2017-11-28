/** Kevin Griffin
 *  Ex-6
 *  Decimal to bnary conversion
 */

/**pre preccessor directives*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h>
#include <math.h>

using namespace std;
//Global function declarations
void bin_2_dec(void);
void dec_2_bin(void);
char displaymenu(void);
//main function
int main()
{
    /**< variable declarations */
    char choice;
    /** Do while loop to select which function to use*/
    do
    {
        choice = displaymenu();
    /*switch case displays the options to the user*/
        switch (choice)
        {
            case 'b' :  bin_2_dec();
                        break;

            case 'd' :  dec_2_bin();
                        break;

            case 'q' :  system("cls");
                        cout << "Goodbye" << endl;
                        break;

            default :   cout << "invalid selection" << endl;
                        break;
        }
    }
    while (choice != 'q');

    return 0;
}

/*Charactor funtion that displays the options to the user. when d is selected the function returns
to the swithc case which envokes the related function*/
char displaymenu(void)
{
    char choice;

    system("cls");

    cout << "conversion Calculator \n \n";
    cout << "press b for bin-dec conversion \n";
    cout << "press d for dec-bin conversion";
    cout << " Press q to quit \n \n ";

    choice = getchar();

    return choice;
}

/* Binary to decimal function*/
void bin_2_dec()
{
    //local declarations
    long int bin, dec = 0, remainder;
    int i = 0;

    system ("cls");
    //display to the user and inserted to the bin location in memory
    cout << "enter binary number to be converted : \t";
    cin >> bin;
    //while loop to calculate the decimal equivalent of binary number
    while (bin != 0)
    {
        remainder = bin % 10;

        bin /= 10;

        dec = dec + remainder * pow(2, i);
        i++;
    }
    //Displays decimal value of the bianry value entered
    cout << "decimal value : " << dec;

    //prompts the user to press the return to go to original menu
    cout << "\n\n Press any key to return to the main menu.";
    //fflush cleans the system
    fflush(stdin);
    getchar();

    return ;
}

//decimal to binary conversion function
void dec_2_bin()
{
    //local declarations
    long int decimal, rem, arrayval[8] = {0};
    int i = 0;

    system ("cls");

    cout << "Enter Decimal number to be converted : \t";
    cin >> decimal;
    /*while loop to calculate the binary equivalent value of the decimal value entered,
    using the division by 2 method. this fills an array which is then displayed as the binary number*/
    while (decimal != 0)
    {
        rem = decimal % 2;
        decimal /= 2;
        arrayval[i] = rem;
        i++;
    }
    //For loop displays the resulting array values.
    for (i=7; i>=0; i--)
    {
        cout << arrayval [i];
    }
    //prompts the user to hit the return key
    cout << "\n\nPress any key to return to the main menu.";
    //cleans the system
    fflush (stdin);

    getchar();

    return;
}

