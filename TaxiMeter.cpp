//TaxiMeter.cpp
//Written in Code::Blocks 10.05
//This program is about taxi meter
//Calculating the salary, fuel amount, kilometers and other factors for a taxi driver!

//list of libraries
# include <iostream>
# include <cmath>
# include <conio.h>
# include <cstdlib>

using namespace std;

//list of global variables
int salary=0;
int fuel;
int kilometers=0;
int passengers=0;

//list of functions
void menu ();
int charge_0_8 (int,int);
int charge_8_14 (int,int);
int charge_14_24 (int,int);



int main ()
{
    cout << "Enter the first amount of fuel in liter: ";
    cin >> fuel;
    system ("cls");
    int n;
    cout << "\n\tWelcome to the Taxi Meter Program!\n";
    cout << "To see the menu again during the program enter '0'.\n\n";
    menu();


    while (true)
    {
        cout << "\nEnter the task you want to do: ";
        cin >> n;
        switch (n)
            {
                case 1 :{passengers++;
                         int t1, t2, v0, t;
                         char c1, c2;
                         system("cls");
                         cout << "Enter the interval time you drive the passenger (e.g. 9 a means 9 AM)\n and the initial speed of the taxi (in km/h): ";
                         cin >> t1 >> c1 >> t2 >> c2 >> v0;
                         
                         
                         //list of conditions of time
                         if (t1>=0 && t1<8 && c1=='a' && t2>=0 && t2<8 && c2=='a')
                            {salary = salary + charge_0_8(t1,t2);
                            kilometers = kilometers + v0*(t2-t1);}
                         if (t1>=0 && t1<8 && c1=='a' && t2>=8 && t2<12 && c2=='a') 
                            {salary = salary + charge_0_8(t1,12);
                            kilometers = kilometers + v0*(t2-t1);}
                         if (t1>=0 && t1<8 && c1=='a' && t2>=0 && t2<2 && c2=='p') 
                            {salary = salary + charge_8_14(t1,2);
                            kilometers = kilometers + v0*(t1+t2);}
                         if (t1>=0 && t1<8 && c1=='a' && t2>=2 && t2<12 && c2=='p') 
                            {salary = salary + charge_0_8(t1,12) + 1800 + charge_14_24(2,t2);
                            kilometers = kilometers + v0*(t1+(t2-2));}

                         if (t1>=8 && t1<12 && c1=='a' && t2>=8 && t2<12 && c2=='a') 
                            {salary = salary + charge_8_14(t1,t2);
                            kilometers = kilometers + v0*(t2-t1);}
                         if (t1>=8 && t1<12 && c1=='a' && t2>=0 && t2<2 && c2=='p') 
                            {salary = salary + charge_8_14(t1,12) + charge_8_14(0,t2);
                            kilometers = kilometers + v0*((t1-8)+t2);}
                         if (t1>=8 && t1<12 && c1=='a' && t2>=2 && t2<12 && c2=='p') 
                            {salary = salary + charge_8_14(t1,12) + 600 + charge_14_24(2,t2);
                            kilometers = kilometers + v0*((t1-8)+(t2-2));}
                         if (t1>=0 && t1<2 && c1=='p' && t2>=0 && t2<2 && c2=='p') 
                            {salary = salary + charge_8_14(t1,t2);
                            kilometers = kilometers + v0*(t2-t1);}
                         if (t1>=0 && t1<2 && c1=='p' && t2>=2 && t2<12 && c2=='p') 
                            {salary = salary + charge_8_14(t1,2) + charge_14_24(2,t2);
                            kilometers = kilometers + v0*(t2-t1);}


                         if (t1>=2 && t1<12 && c1=='p' && t2>=2 && t2<12 && c2=='p')
                            {salary = salary + charge_14_24(t1,t2);
                            kilometers = kilometers + v0*(t2-t1);}

                   //      if () cout << "The fuel amount is not enough to take passenger.";
                         if (t1>=0 && t1<12 && c1=='a' && t2>=0 && t2<12 && c2=='a') 
                            t=t2-t1;
                         if (t1>=0 && t1<12 && c1=='p' && t2>=0 && t2<12 && c2=='p')
                            t=t2-t1;
                         if (t1>=0 && t1<12 && c1=='a' && t2>=0 && t2<12 && c2=='p') 
                            t=12-t1+12-t2;
                         fuel = fuel - abs(log2(v0)) - abs(cos(v0));

                        }break;

                case 2 :{int liter;
                         system("cls");
                         cout << "Enter the amount of fuel in liter: ";
                      a: cin >> liter;
                         if (100*liter>salary) {cout << "Your salary is not enough! Please try a new amount: "; goto a;}
                         else {fuel+=liter; salary = salary - 100*liter;}
                        }

                case 3 : cout << "Your salary is " << salary << " tomans."; break;
                case 4 : cout << "Available fuel is " << fuel << " liters."; break;
                case 5 : cout << "Up to now you have driven " << kilometers << " kilometers."; break;
                case 6 : cout << "Up to now you have taken " << passengers << " passengers."; break;
                case 0 : {system("cls"); menu();} break;
                default : cout << "Your choice is out of list! Try again!\n";

            }
    }
    return 0;
}

void menu () {
    cout << "1. take passenger\n";
    cout << "2. take fuel\n";
    cout << "\n\n";
    cout << "3. salary amount\n";
    cout << "4. fuel amount\n";
    cout << "5. total kilometers\n";
    cout << "6. total passengers\n";
}

int charge_0_8 (int a, int b)
{
    return (b-a)*500;
}

int charge_8_14 (int a,int b)
{
    return (b-a)*300;
}

int charge_14_24 (int a,int b)
{
    return (b-a)*400;
}
