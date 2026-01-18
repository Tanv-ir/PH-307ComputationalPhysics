//This is a raw cpp/c++ file that can be compiled with GCC or other c/c++ compiler

//Problem

/*
f(x) = sin(x) + e^x .
    
write a c++ code using Newton
	 1) Forward Method
     2) Backward Method
     3) Central Method
	 
    Plot f(x) Vs x
*/

//Solution

#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>

using namespace std;

//Given Function
double func(double x){
	double y;

	y = sin(x) - exp(x);

	return y;
}

//Forward Method
double forward(double x, double h){
	double y;

	y = (func(x+h) - func(x))/h;

	return y;
}

//Backward Method
double backward(double x, double h){
	double y;

	y = (func(x) - func(x-h))/h;

	return y;
}

//Central Method
double central(double x, double h){
	double y;

	y = (func(x+h) - func(x-h))/(2*h);

	return y;
}

int main(){
	double x;
	double h;

	cout << "Enter a Value for x: ";
	cin >> x;
	cout << "Enter a Value for h: ";
	cin >> h;
	
	cout << fixed << setprecision(4) << forward(x, h) << endl;
	cout << fixed << setprecision(4) << backward(x, h) << endl;
	cout << fixed << setprecision(4) << central(x, h) << endl;

	double a;     //smallest input value for plot
    double b;     //largest input value for plot

	cout << "Enter the smallest value of x to draw a plot: ";
	cin >> a;
	cout << "Enter the largest value of x to draw a plot: ";
	cin >> b;

	ofstream plotdata("func.dat");    //creates an empty file name func.dat

	for(double i = a; i <= b; i += 0.001){
		plotdata << fixed << setprecision(4) << func(i) << "\t\t" << i << endl;
	}

	plotdata.close();    //prevents the func.dat file to take anymore inputs
	
    return 0;
}
