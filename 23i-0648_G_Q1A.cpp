/*	Muhammad Asif
	23i-0648
	Assignment#2 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long int num, binaryToDecimal = 0;
    int a = 1, b = 0, gate1, gate2, gate3, gate4;

    // Input decimal number
    cout << "Enter the decimal number  ";
    // Input validation loop
    do {
        cin >> num;
        
        // Checking if entered number is >= 0 ( if not ask again)
        if (num < 0) {
            cout << "Invalid input. Please enter a number greater than 0 : "  ;
        }
    } while (num < 0);
    
	
    // Convert and display decimal to 32-bit binary
    cout << "32-bit Binary representation: ";
    
    if (num>0){
    for (int i = 31; i >= 0; --i) {
        if (pow(2, i) > num) {
            cout << b;
            binaryToDecimal += pow(2, i) * b;
        } else if (pow(2, i) <= num) {
            cout << a;
            num -= pow(2, i);
            binaryToDecimal += pow(2, i) * a;
        } 
    }
    cout<<endl;
    }
    num = binaryToDecimal;

	{
    // Gate1
    gate1 = num & 1023;
    cout << "\nGate 1= ";
    for (int i = 9; i >= 0; --i) {
        if (pow(2, i) > gate1) cout << b;
        else if (pow(2, i) <= gate1) {
            cout << a;
            gate1 -= pow(2, i);
        } 
    }
    }
    cout << endl;

    // Gate2
    gate2 = (num & (1023 << 10)) >> 10;
    int temp = gate2;
    cout << "Gate 2= ";
    for (int i = 9; i >= 0; --i) {
        if (pow(2, i) > temp) cout << b;
        else if (pow(2, i) <= temp) {
            cout << a;
            temp -= pow(2, i);
        } 
    }
    cout << endl;
    
    
	{
    // Gate3
    gate3 = (num & (1023 << 20)) >> 20;
    int temp = gate3;
    cout << "Gate 3= ";
    for (int i = 9; i >= 0; --i) {
        if (pow(2, i) > temp) cout << b;
        else if (pow(2, i) <= temp) {
            cout << a;
            temp -= pow(2, i);
        } 
    }
    }
    cout << endl;

	{
    // Gate4
    gate4 = (num & (3 << 30)) >> 30;
    int temp = gate4;
    cout << "Gate 4= ";
    for (int i = 1; i >= 0; --i) {  // Only 2 bits, so loop runs from 1 to 0
        if (pow(2, i) > temp) cout << b;
        else if (pow(2, i) <= temp) {
            cout << a;
            temp -= pow(2, i);
        }
    }
    }   
	
    // Decision based on Gate4
    switch (gate4) 
    {
    	//Operation 1 
        case 0:
        	cout<<"\n\n\tOperation 1 "<<endl;
            cout << "\nConverted back to decimal: " << binaryToDecimal << endl;
            break;

		//Operation 2
        case 1:
        {   
        	cout<<"\n\n\tOperation 2 "<<endl;
            char temp = num;
            cout << "\nHexadecimal number of " << num << " is : ";
            int hexabase = 1;
            while (num / hexabase >= 16) {
                hexabase *= 16;
            }

            while (hexabase > 0) {
                temp = (num / hexabase) % 16;  // Extract the current hex digit
                switch (temp <= 9) {
                    case true:
                        temp += 48;  // Convert to ASCII for 0-9
                        cout << temp;
                        break;
                    case false:
                        temp += 55;  // Convert to ASCII for A-F
                        cout << temp;
                        break;
                }
                hexabase /= 16;  // Move to the next hex digit
            }
            cout << endl;  
            break;
        }

		//Operation 3 (Swapping numbers)
        case 2:
        {
        	cout<<"\n\n\tOperation 3 "<<endl;
            gate3 = gate2 + gate3;
            gate2 = gate3 - gate2;
            gate3 = gate3 - gate2;
            cout << "\nSwap gates are " << endl;
            cout << "Gate 2(decimal)= " << gate2 << endl;
            cout << "Gate 2(binary)= ";
            for (int i = 9; i >= 0; --i) {
                if (pow(2, i) > gate2) cout << b;
                else if (pow(2, i) <= gate2) {
                    cout << a;
                    gate2 -= pow(2, i);
                } 
            }
            cout << endl;

            cout << "Gate 3(decimal)= " << gate3 << endl;
            cout << "Gate 3(binary)= ";
            for (int i = 9; i >= 0; --i) {
                if (pow(2, i) > gate3) cout << b;
                else if (pow(2, i) <= gate3) {
                    cout << a;
                    gate3 -= pow(2, i);
                } 
            }
            cout << endl;
        }
        //Operation 4
        case 3:
        {
        	cout<<"\n\n\tOperation 4 "<<endl;
        	int num1,num2;
        	char Operator;
        	cout<<"\nEnter two numbers"<<endl;
        	cout<<"Number 1 : ";cin>>num1;
        	cout<<"Number 2 : ";cin>>num2;
        	cout<<"Press * for multiplication and / for Division: ";
        	do
        	{
        	cin>>Operator;	
        	if (Operator!='*'&&Operator!='/')
        	cout<<"Invalid operator, please enter * for multiplication and / for Division: "  ;
        	}
        	while(Operator!='*'&&Operator!='/');
        	switch(Operator)
        	{	
        	
        			case char('*'):
        			{
        			int i=1;
        				if (num1*num2>0)
        				{
        					for ( ; i<num1*num2  ; i++ );
        					cout<<"Multiplication is "<<i<<endl<<"\n\n";
        				}	
        				else 
        				{
        					for ( ; i>num1*num2   ; i-- );
        					cout<<"Multiplication is "<<i<<endl<<"\n\n";
        				}	
        			break;
        			}
        			case char('/'):
        			{	
        			int i=0;
        				if (num1*num2>0)
        				{
        				for ( ; i<num1/num2 ; i++);
        				cout<<"Division is "<<i<<endl<<"\n\n";
        				}
        				else 
        				{
        				for ( ; i>num1/num2 ; i--);
        				cout<<"Division is "<<i<<endl<<"\n\n";
        				}
        			break;
        			}   	
        	}	
    	}
	}
    return 0;
}

