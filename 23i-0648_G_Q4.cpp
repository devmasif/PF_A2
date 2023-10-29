/*	Muhammad Asif
	23i-0648
	Assignment#2 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int base, exponent, h = 0, y, temp;

    // Prompt the user to enter values for base and exponent
    cout << "Enter the value of base(x) which should be non-negative: ";
    cin >> base;
    cout << "Enter the value of exponent (n) which should be positive ";
    cin >> exponent;
    temp = base;

    // Check if user has provided valid inputs, otherwise ask again
    while (base<0 || exponent <1)
    {
        if (base<0)
        {
            cout<<"\nEnter the value of base(x) again (should be non-negative): ";
            cin>>base;
        }
        if (exponent<1)
        {
            cout<<"\nEnter the value of exponent(x) again (should be positive): ";
            cin>>exponent;
        }
        temp = base;
    }

    // Calculate the function value y = x^n + x^(n-1)
    y = (pow(base, exponent) + pow(base, exponent - 1));

    // Display the equation and prepare for the graph
    cout << "\nGraph for equation ""f("<<base<<")"<<"= "<<base<<"^"<<exponent<<"+ "<<base<<"^"<<"("<<exponent<<"-1) is given below\n\n\n";


        while (y >= 0) 
        {
            // Loop through the y-axis values
            while (y >= 0) 
            {
                // Display the '*' at the appropriate x position on the graph
                if (y > 0 && y == pow(base, exponent) + pow(base, exponent - 1)) 
                {
                    // Print y-values with appropriate padding
                    if (y >= 10) 
                        cout << y;
                    else 
                        cout << "0" << y;

                    // Draw spaces before the '*'
                    while (base >= 0 && h < ((base * 4 + 1))) 
                    {
                        cout << " ";
                        h = h + 1;
                    }
                    cout << "*" << endl;
                    base = base - 1;
                    h = 0;
                } 
                else 
                {
                    // Print y-values with appropriate padding
                    if (y >= 10) 
                        cout << y << endl;
                    else 
                        cout << "0" << y << endl;    
                }
                y = y - 1;
            }

            // Print the x-axis values
            while (h <= temp) 
            {
                if (h > 10) 
                {
                    cout << "  " << h;
                    h = h + 1;
                } 
                else 
                {
                    cout << "   " << h;
                    h = h + 1;
                }
            }
        }
        cout << endl;
     

    return 0;
}

