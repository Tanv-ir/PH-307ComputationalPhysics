//This is a raw cpp/c++ file that can be compiled with GCC or other c/c++ compiler

//Problem
/*
write a c++ code to determine the value of e^x using e = (x^0)/0! + (x^1)/1! + (x^2)/2! + ... + (x^n)/n!

Also plot a graph of
    i)e^x vs x where n is a fixed value
   ii)e^x vs n where x is a fixed value
*/

//Solution

//In this Solution I decided not to use the cmath library

#include<iostream>
#include<fstream>
#include<iomanip>

long double power(double x, int n){
    long double c = 1, p;

    if(n == 0){
        p = 1;
    }
    else{
        for(int i = 1; i <= n; i++){
            c *= x;
        }
        p = c;
    }
    return p;
}

long double factorial(int n){
    long double c = 1, f;

    if(n == 0 || n == 1){
        f = 1;
    }
    else{
        for(int i = 2; i <= n; i++){

            c *= i;
        }
        f = c;
    }
    return f;
}

long double nthturmOFtaylor(double x, int n){
    long double t;

    t = power(x, n)/factorial(n);

    return t;
}

long double exponantial(double x, int n){
    long double e = 0;

    for(int i = 0; i <= n; i++){
        e += nthturmOFtaylor(x, i);
    }
    return e;
}

int main(){

    std::cout << "This program can only plot two types of plots. " << std::endl;
    std::cout << "Enter 1 if you want to draw a (e^x) Vs x plot for a fixed n. " << std::endl;
    std::cout << "Enter 2 if you want to draw a (e^x) Vs n plot for a fixed x. " << std::endl;

    double a;

    while( a != 1 || a != 2){
        std::cout << "Please Enter a value between 1 and 2: ";
        std::cin >> a;

        if( a == 1 || a == 2){
            break;
        }
        else{
           std::cout << "Error!" << std::endl;
        }
    }

    std::cout << "You have sucessfully entered: " << a <<std::endl;

    if( a == 1){

	double maximum_x;

	std::cout << "Please enter a value of maximum x: " << std::endl;
        std::cin >> maximum_x;

	std::ofstream testdata("exponantialxVSx_data.dat");

        for(double i = 0; i <= maximum_x; i += 0.01){
	    long double y = exponantial(i, 1000);

            testdata << std::fixed << std::setprecision(4) << i << "\t" << y << std::endl;
        }
    
	testdata.close();
    }
    else{

	double x;
	int minimum_n;
	int maximum_n;

	std::cout << "Enter a value for x: ";
	std::cin >> x;
	
	while( 1 > minimum_n || 500 < minimum_n ){
	    std::cout << "Please make sure the minimum value of n is between 1 and 500. " << std::endl;
	    std::cout << "Please Enter the minimum value of n: ";
	    std::cin >> minimum_n;
	    
	    if( 1 < minimum_n && minimum_n < 500){
		break;
	    }
	    else{
	        std::cout << "ERROR!" << std::endl;
	    }
	}

	while( 500 > maximum_n || 1000 < maximum_n ){
	    std::cout << "Please maxke sure the maximum value of n is between 500 and 1000. " << std::endl;
	    std::cout << "Please Enter the maximum value of n: ";
	    std::cin >> maximum_n;

	    if( 500 < maximum_n && maximum_n < 1000){
		break;
	    }
	    else{
		std::cout << "ERROR!" << std::endl;
	    }
	}
	
	std::ofstream testdata("exponantialxVSn_data.dat");

	for(int i = minimum_n; i <= maximum_n; i++){
	    long double y = exponantial(x, i);

	    testdata << std::fixed << std::setprecision(4) << i << "\t" << y << std::endl;
	}

	testdata.close();
	
    }

    std::cout << "You can now run GNUPlot" << std::endl;
    
    return 0;
}
