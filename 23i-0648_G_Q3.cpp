/*	Muhammad Asif
	23i-0648
	Assignment#2 */
	
#include <iostream>
#include <iomanip>
#include <cmath>
	
using namespace std;	


int main() {
const double G = 9.8 , dt = 0.01 ; 

    double v0,T=1,t=0,s=0;
    
    cout << "Enter initial velocity (50-150 m/s): ";
    cin >> v0;

    	if (v0 < 50 || v0 > 150) {
        	cout << "Enter valid velocity ,  Initial velocity must be between 50 and 150 m/s." << endl;
        return 1;
    	}

    double v = v0;

    while (s >= 0) 
    {
        t += dt;
        v -= G * dt;
        s += v * dt - 0.5 * G * dt * dt;

        if (t >= 1.0) 
        {
            cout << "Time : " << T << " s,  Position: " << string(static_cast<int>(s) / 10, ' ') << "0" << endl;
            t = 0;
            T=T+1;
        }
    }

    return 0;
}
