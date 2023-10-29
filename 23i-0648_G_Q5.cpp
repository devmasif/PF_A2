/*	Muhammad Asif
	23i-0648
	Assignment#2 */

#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<unistd.h>
#include<cmath>
using namespace std;
int main(){

//Variable Declaration
string name1,name2;
int rn1,rn2;
int sum1=0,sum2=0,round=1; // sum1=player1's score and sum2 = player2's score
char opt;

//Input player names and roll numbers
cout<<"Enter player1's name  "<<endl;
getline(cin,name1);
cout<<"Enter your roll #  "<<endl;
cin>>rn1;

cin.ignore();
cout<<"Enter player2's name  "<<endl;
getline(cin,name2);
cout<<"Enter your roll #  "<<endl;
cin>>rn2;
//Declaring more variables
int length1,length2;
bool default_turn = 1;
//Extracting last alphabet ascii value 
length1=name1.length();
length2=name2.length();	
int n1=name1.at(length1-1);	
int n2=name2.at(length2-1);	

//Converting last alphabet ascii value to its index (1 , 2 , 3 , ... 26 for a , b , c ... z respectively )
	if (n1>=65&&n1<=122)
	{
		if (n1<=90)
			n1=n1-64;
		else 
			n1=n1-96;
	}
	if (n2>=65&&n2<=122)
	{
		if (n2<=90)
		n2=n2-64;
		else 
		n2=n2-96;
	}
//Random number generator
srand(time(0));
//Screen clearing
system("clear");
//Game's loop
while(1)
{
int roll1,roll2,roll3,roll4;

cout<<"\n\tRound"<<round<<endl;
cout<<"\n"<<name1<<"'s turn "<<endl;
cout<<"Press D to roll dice "<<endl;
cin>>opt;
//Loop for player 1's turn 
while (true)
	{
	if (opt == 'D' || opt == 'd' )
	{
		if (default_turn==1)
		{
			roll1 = rand() % (6) + 1;
			roll2 = rand() % (6) + 1;
			usleep(500000);
			cout<<"1st roll: "<<roll1<<endl;
			usleep(500000);
 			cout<<"2nd roll: "<<roll2<<endl;
 			usleep(500000);
 			// Checking all conditions and adding score accordingly
 			if (roll1+roll2==(rn1%10)+(rn1%100/10))
			{
				sum1 = sum1 + roll1 + roll2 + rn1%10;
				cout<<"You got +"<<rn1%10<<" bonus"<<endl;
			}
			else 
			{
				sum1 = sum1 + roll1 + roll2;
			}
			
			if (roll1+roll2==n1&&n1>0&&n1<=26)
			{
				sum1=sum1+5;
				cout<<"Congratulations "<<name1<<" you got +5 points "<<endl;
			}
			if (roll1+roll2==4)
			{
				cout<<"\n\nCongratulations! You got an extra dice roll "<<endl;
				cout<<"Press D to Roll Dice "<<endl;
				while (1)
				{
					cin>>opt;
					if (opt=='D' || opt =='d')
					{
						roll1 = rand() % (6) + 1;
						roll2 = rand() % (6) + 1;
						usleep(500000);
						cout<<"\n Bonus Turn"<<endl;
						usleep(500000);
						cout<<"1st roll : "<<roll1<<endl;
						usleep(500000);
						cout<<"2nd roll : "<<roll2<<endl;
						sum1=sum1+roll1+roll2;
						break;
					}
					else 
					{
						cout<<"Invalid input,try again"<<endl;
					}
				}
			}
			
		
		}
		//If scores are same after five round 
		else 
		{
		roll1 = rand() % (6) + 1;
		cout<<"Extra roll: "<<roll1<<endl;
		sum1=sum1+roll1;
		}
		//Printing player's score after every round
	cout<<"\n"<<name1<<"'s Score till now: "<<sum1<<endl<<flush;	
	break;
	}
	else
	{
	usleep(500000);
	cout<<"Invalid option,try again ";
	cin>>opt;
	}
	
	}


cout<<"\n"<<name2<<"'s turn "<<endl;
cout<<"Press D to roll dice "<<endl;
cin>>opt;
//Loop for player 2's turn 
while (true)
{
	if (opt == 'D' || opt == 'd' )
	{
		if (default_turn==1)
		{
			roll3 = rand() % (6) + 1;
			roll4 = rand() % (6) + 1;
			usleep(500000);
			cout<<"1st roll: "<<roll3<<endl;
			usleep(500000);
			cout<<"2nd roll: "<<roll4<<endl;
			// Checking all conditions and adding score accordingly
			if (roll3+roll4==(rn2%10)+(rn2%100/10))
			{
				sum2 = sum2 + roll3 + roll4 + rn2%10;
				cout<<"You got +"<<rn2%10<<" bonus"<<endl;
			}
			else
			{
				sum2 = sum2 + roll3 +roll4;
			}	
			if (roll3+roll4==n2&&n2>0&&n2<=26)
			{
				sum2=sum2+5;
				cout<<"Congratulations you got +5 points "<<endl;
			}
			if (roll3+roll4==4)
			{
				cout<<"\n\nCongratulations! You got an extra dice roll "<<endl;
				cout<<"Press D to Roll Dice "<<endl;
				while (1)
				{
					cin>>opt;
					if (opt=='D' || opt =='d')
					{
						roll3 = rand() % (6) + 1;
						roll4 = rand() % (6) + 1;
						usleep(500000);
						cout<<"\n Bonus Turn "<<endl;
						usleep(500000);
						cout<<"1st roll : "<<roll3<<endl;
						usleep(500000);
						cout<<"2nd roll : "<<roll2<<endl;
						sum2=sum2+roll3+roll4;
						break;
					}
					else 
					{
						cout<<"Invalid input,try again"<<endl;
					}
				}
			}	
			
		}
		//If scores are same after five round 
		else 
		{
			roll3 = rand() % (6) + 1;
			roll4 = 0;
		
			cout<<"Extra roll : "<<roll3<<endl<<flush;
			sum2=sum2+roll3;
		}
		usleep(500000);	
		//Printing player's score after every round
		cout<<"\n"<<name2<<"'s Score till now: "<<sum2<<endl<<flush;	
		break;
	}
	else
	{
		usleep(500000);
		cout<<"Invalid option,try again \n";
		cin>>opt;
	}
	
}
	
	
	
round = round +1;
//Check whether scores are same or different after five rounds			
if 	(round>5)
	{
	if 	(sum1!=sum2)
		{ break ; }
	else 
	{	
		if (sum1==sum2&&round==6)
		{		
		default_turn = 0 ;
		cout<<"\n\n"<<name1<<"'s total is : " <<sum1<<endl<<flush;
		cout<<name2<<"'s total is : " <<sum2<<endl<<flush;
		cout<<"It's a Tie,Lets play another round but in this round you will roll only 1 dice "<<endl<<flush;
		}
		else 
		{
		default_turn = 0 ;
		cout<<"\n\n"<<name1<<"'s total is : " <<sum1<<endl<<flush;
		cout<<name2<<"'s total is : " <<sum2<<endl<<flush;
		cout<<"It's a Tie again,Lets play again "<<endl<<flush;
		}
	}	
	}
//Clearing screen after every round
sleep (2);
system("clear");	
}
//Printing Final  score of both players
cout<<"\n\n"<<name1<<"'s total is : " <<sum1<<endl;
cout<<name2<<"'s total is : " <<sum2<<endl;

//Declaring Winner
string winner;
winner = sum1>sum2 ? name1 : name2;
cout<<"\nWinner is : "<<winner<<endl;

return 0;
}         
                                                                                                                                          
