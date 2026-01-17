//This is a raw cpp/c++ file that can be compiled with GCC or other c/c++ compiler

//problem
/*
Find the root of the following functions using Bi-section method.

1. x*e^x = 1
2. cos(x) - x*e^x = 0
3. x*sin(x) + cos(x) = 0

Make sure the root is currected upto n decimal places, where n can be declared by the users.
Plot f(x) vs x graph for each functions.
*/

//Solution

#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>

using namespace std;

//Function for 1st equation
double func_1(double x){
    double y;

    y = x*exp(x) - 1;

    return y;
}

//Function for 2nd equation
double func_2(double x){
    double y;

    y = cos(x) - x*exp(x);

    return y;
}

//Function for 3rd equation
double func_3(double x){
    double y;

    y = x*cos(x) + sin(x);

    return y;
}

int main(){

	return 0;
}
