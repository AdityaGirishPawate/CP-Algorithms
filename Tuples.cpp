#include<bits/stdc++.h>

using namespace std;
#define ll long long

/*
tuple <> name
->make_tuple()
->tie()
->get<>()
->decltype()
->tup1.swap(tup2)
->

*/
int main()
{
    // Declaring tuple 
    tuple <char, int, float> geek; 
  
    // Assigning values to tuple using make_tuple() 
    geek = make_tuple('a', 10, 15.5); 
  
    // Printing initial tuple values using get() 
    cout << "The initial values of tuple are : "; 
    cout << get<0>(geek) << " " << get<1>(geek); 
    cout << " " << get<2>(geek) << endl; 
  
    // Use of get() to change values of tuple 
    get<0>(geek) = 'b'; 
    get<2>(geek) =  20.5; 
  
     // Printing modified tuple values 
    cout << "The modified values of tuple are : "; 
    cout << get<0>(geek) << " " << get<1>(geek); 
    cout << " " << get<2>(geek) << endl; 
    
    // Initializing tuple 
    tuple <char,int,float> geek(20,'g',17.5); 
  
    // Use of size to find tuple_size of tuple 
    cout << "The size of tuple is : "; 
    cout << tuple_size<decltype(geek)>::value << endl; 
  
    // Initializing 1st tuple 
    tuple <int,char,float> tup1(20,'g',17.5); 
      
    // Initializing 2nd tuple 
    tuple <int,char,float> tup2(10,'f',15.5); 
      
    // Printing 1st and 2nd tuple before swapping 
    cout << "The first tuple elements before swapping are : "; 
    cout <<  get<0>(tup1) << " " << get<1>(tup1) << " "
         << get<2>(tup1) << endl; 
    cout << "The second tuple elements before swapping are : "; 
    cout <<  get<0>(tup2) << " " << get<1>(tup2) << " " 
         << get<2>(tup2) << endl; 
      
    // Swapping tup1 values with tup2 
    tup1.swap(tup2); 
      
    // Printing 1st and 2nd tuple after swapping 
    cout << "The first tuple elements after swapping are : "; 
    cout <<  get<0>(tup1) << " " << get<1>(tup1) << " " << get<2>(tup1) << endl;       
    cout << "The second tuple elements after swapping are : "; 
    cout <<  get<0>(tup2) << " " << get<1>(tup2) << " " << get<2>(tup2) << endl; 
    
    // Initializing variables for unpacking 
    int i_val; 
    char ch_val; 
    float f_val;    
      
    // Initializing tuple 
    tuple <int,char,float> tup1(20,'g',17.5); 
  
    // Use of tie() without ignore 
    tie(i_val,ch_val,f_val) = tup1; 
      
    // Displaying unpacked tuple elements 
    // without ignore 
    cout << "The unpacked tuple values (without ignore) are : "; 
    cout << i_val << " " << ch_val << " " << f_val; 
    cout << endl; 
      
    // Use of tie() with ignore 
    // ignores char value 
    tie(i_val,ignore,f_val) = tup1; 
      
    // Displaying unpacked tuple elements 
    // with ignore 
    cout << "The unpacked tuple values (with ignore) are : "; 
    cout << i_val  << " " << f_val; 
    cout << endl; 
    
    
    return 0; 
}