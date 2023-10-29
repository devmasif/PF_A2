/*	Muhammad Asif
	23i-0648
	Assignment#2 */


#include <iostream>
using namespace std;

int main() {
    int total_lamps, rounds;

    cout << "Enter the total number of lamps: ";
    cin >> total_lamps;

    rounds=total_lamps;

    int onLamps = 0;

    for (int i = 1; i <= rounds; i++) {
        int count = 0;

        // If the i number is divisible by 3, toggle it once
        //Rule 1 for round 1 only
        if (i % 3 == 0) {
            count++;
        }

        // Check all the factors of the i number and toggle it for each factor
        //Rule for second and onwards.
        for (int round = 2; round <= rounds && round <= i; round++) {
            if (i % round == 0) {
                count++;
            }
        }

        // If the count is even, it mean it is on.
        if (count % 2 == 0) {
            onLamps++;
        }
    }

    // Output the number of lamps that are left on after the specified number of rounds
    cout << "Number of lamps that are ON after " << rounds << " rounds: " << onLamps << endl;

    return 0;
}
