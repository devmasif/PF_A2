/*	Muhammad Asif
	23i-0648
	Assignment#2 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int outer_space = 25, inner_space = 0, h = 1; //h=height

    cout << "\n\n";

    while (true) 
    {
        if (h == 1 || h == 4 || h == 7 || h == 10 || h == 13) 
        {
            // Print outer spaces, 6 stars, inner spaces, and a star
            for (int temp = outer_space; temp > 0; temp--) cout << " ";
            for (int star = 6; star > 0; star--) cout << "*";
            for (int temp = inner_space; temp > 0; temp--) cout << " ";
            cout << "*" << endl;
            h++;
        } 
        else if (h <= 15) 
        {
            inner_space += 5;
            for (int i = 1; i <= 2; i++) {
                // Print outer spaces, a star, inner  spaces, and a star
                for (int temp = outer_space; temp > 0; temp--) cout << " ";
                cout << "*";
                for (int temp = inner_space; temp > 0; temp--) cout << " ";
                cout << "*" << endl;
            }
            outer_space -= 5;
            h += 2;
        }
        else if (h == 16) 
        {
            // Print a line of 32 stars and exit the loop
            for (int i = 1; i <= 32; i++) cout << "*";
            break;
        }
    }
    cout << "\n\n";
    return 0;
}

