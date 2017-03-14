//This is my wierd number wikipedia that I made when I was just learning C++.
//Please do not judge.

#include <iostream>
using namespace std;

int main() 
{
     cout << " " << endl;
    cout << "Welcome to the Number Wikipedia."
    << endl; cout << "Please enter an integer:\n" << endl;
    int number =13;
    cin >> number;
    cout << " " << endl;
      
    // checks if the number is positive
    if ( !(number == 0) && (number > 0) )
    {cout << "You entered a positive integer: " << number << endl;
    cout << " " << endl;
    std::cout << "Your number's double is " << number*2 << "." << endl;
    std::cout << "Your number's triple is " << number*3 << "." << endl;
    std::cout << "Your number's quadruple is " << number*4 << "." << endl;
    std::cout << "Your number's pentuple is " << number*5 << "." << endl;
    std::cout << "Your number's hexuple is " << number*6 << "." << endl;
    std::cout << "Your number's heptuple is " << number*7 << "." << endl;
    std::cout << "Your number's octuple is " << number*8 << "." << endl;
    std::cout << "Your number's nonuple is " << number*9 << "." << endl;
    
    int other =60;
    cin >> other;
    }
    
    if ( !(number == 0) && (number < 0) )
    {cout << "You entered a negative integer: " << number << endl;
    cout << " " << endl;
    std::cout << "Your number's double is " << number*2 << "." << endl;
    std::cout << "Your number's triple is " << number*3 << "." << endl;
    std::cout << "Your number's quadruple is " << number*4 << "." << endl;
    std::cout << "Your number's pentuple is " << number*5 << "." << endl;
    std::cout << "Your number's hexuple is " << number*6 << "." << endl;
    std::cout << "Your number's heptuple is " << number*7 << "." << endl;
    std::cout << "Your number's octuple is " << number*8 << "." << endl;
    std::cout << "Your number's nonuple is " << number*9 << "." << endl;
    
    int another =60;
    cin >> another;
    }
    
    if ( number == 0) {cout << "You entered 0." << endl;
    int abother =60;
    cin >> abother;}
    
    cout << " " << endl;
    
    if ( number%5 == 0)
    { std::cout << "Two of the factors of your number are " << number/5;
    std::cout << " and 5." << endl;
    
    if (number/5 == 1)
    {std::cout << "Your number is 5, eh?" << endl;} }
    
    if ( number%4 == 0)
    { std::cout << "Two of the factors of your number are " << number/4;
    std::cout << " and 4." << endl;
    
    if (number/4 == 1)
    {std::cout << "Your number is 4, eh?" << endl;} }
    
    if ( number%3 == 0)
    { std::cout << "Two of the factors of your number are " << number/3;
    std::cout << " and 3." << endl;
    
    if (number/3 == 1)
    {std::cout << "Your number is 3, eh?" << endl;} }
    
    if ( number%2 == 0)
    { std::cout << "Two of the factors of your number are " << number/2 ;
    std::cout << " and 2." << endl;
    
    if (number/2 == 1){std::cout << "Your number is 2, eh?" << endl;} }
    std::cout << " " << endl;
    
    string antother;
    cin >> antother;
    
    std::cout << "We hope we satisfied all of your numberly needs." << endl;
    std::cout << "Please visit again soon." << endl;
    std::cout << ":)" << endl;
    
}
