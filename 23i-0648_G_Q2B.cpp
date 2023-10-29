	/*Muhammad Asif
	23i-0648
	Assignment#2 */

#include <iostream>
using namespace std;

int main() {
	//Declaring Variables
    int space = 8;
    int space1 = 1;
    int star = 4;
    int count = 1;

    for (int h = 1; h <= 24; h++) {
        // Check if 'h' is an odd number and within the specified range
        if (h % 2 == 1 && (h <= 12 || h > 16)) {
            for (int i = 1; i <= space; i++)
                cout << " ";
            if (h == 1)
                cout << "*" << endl;
            else if ((h == 3) || (h == 23)) {
                if (h == 3)
                    cout << "* - *" << endl;
                else
                    cout << "* *" << endl;
            } else {
                if (h < 8 || h > 16) {
                    cout << "* -";
                    for (int i = 1; i <= space1; i++)
                        cout << " ";
                    if (h < 23)
                        cout << "- *" << endl;
                } else if (h >= 9 && h <= 16) {
                    cout << "* -";
                    cout << " ";
                    for (int temp = star; temp >= 1; temp--)
                        cout << "*";
                    for (int i = 1; i <= count && i <= 5; i++) {
                        cout << i;
                    }
                    if (h < 12) {
                        if (count <= 6) {
                            for (int i = (count - 1); i > 0; i--) {
                                cout << i;
                            }
                        }
                        count = count + 1;
                    } else {
                        int temp = count;
                        if (temp <= 6) {
                            for (int i = 1; i < 5; i++) {
                                cout << " ";
                            }
                        }
                    }
                    for (int temp = star; temp >= 1; temp--)
                        cout << "*";
                    if (h < 12) {
                        star = star - 1;
                    } else {
                        star = star + 1;
                    }
                    cout << " ";
                    cout << "- *" << endl;
                }
            }
        } 
        // Check if 'h' is an even number and within the specified range
        else if (h % 2 == 0 && (h <= 12 || h > 16)) {
            for (int i = 1; i <= space; i++)
                cout << " ";
            if (h == 2 || h == 22 || h == 24) {
                if (h == 2)
                    cout << "- -" << endl;
                else if (h == 22)
                    cout << "- * -" << endl;
                else
                    cout << "-" << endl;
            } else {
                if (h < 8 || h > 16) {
                    cout << "- *";
                    for (int i = 1; i <= space1; i++)
                        cout << " ";
                    if (h < 23)
                        cout << "* -" << endl;
                } else if (h >= 8 && h <= 16) {
                    cout << "- *";
                    if (h == 8) {
                        for (int temp = star; temp >= 1; temp--)
                            cout << "*";
                        for (int i = 1; i <= count; i++)
                            cout << i;
                        for (int temp = star; temp >= 1; temp--)
                            cout << "*";
                        star = star - 1;
                        count = count + 1;
                    } 
                    else if (h <= 12) {
                        cout << " ";
                        for (int temp = star; temp >= 1; temp--)
                            cout << "*";
                        for (int i = 1; i <= count && i <= 5; i++) {
                            cout << i;
                        }
                        count = count + 1;
                        if (count <= 6) {
                            for (int i = (count - 2); i > 0; i--) {
                                cout << i;
                            }
                        }
                        for (int temp = star; temp >= 1; temp--)
                            cout << "*";
                        star = star - 1;
                        cout << " ";
                    } else {
                        cout << " ";
                        for (int temp = star; temp >= 1; temp--)
                            cout << "*";
                        for (int i = 1; i <= count && i <= 5; i++) {
                            cout << i;
                        }
                        if (count <= 6) {
                            for (int i = 1; i < 5; i++) {
                                cout << " ";
                            }
                        }
                        star = star - 1;
                        cout << " ";
                    }
                    cout << "* -" << endl;
                }
            }
        } 
        // Special handling for rows within the range 13 to 16
        else if (h > 12 && h <= 16) {
            star = star + 1;
            count = count - 1;
            int i = 0, j = 1;
            if (h%2==0)
           		cout << "- * ";
           	else
           		cout<<"* - ";
            for (int temp = star; temp >= i; i++) {
                cout << "*";
            }
            for (int temp = count; temp >= 2; temp--) {
                cout << j;
                j = j + 1;
            }
            for (int temp = (count - 1); temp >= 2; temp--) {
                cout << " ";
                j = j - 1;
            }
            i = 0;
            for (int temp = star; temp >= i; i++) {
                cout << "*";
            }
            if (h%2==0)
            cout << " * -" << endl;
            else 
            cout<<" - *"<<endl;
        }

        // Adjust space variables based on the row
        if (h < 16) {
            if (space > 0)
                space = space - 1;
        } else {
            space = space + 1;
        }

        if (h > 3 && h < 9)
            space1 = space1 + 2;
        else if (h > 15 && h < 22)
            space1 = space1 - 2;
    }

    cout << "\n\n\n\n";
    return 0;
}

