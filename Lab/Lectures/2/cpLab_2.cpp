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

//Function for Bisection Method
double Bisection(double a, double b, double n, int f){   
    double y;

    //f indicates the function we want to solve.
    switch(f){
	case 1:
	    while((b-a) >= n){
		y = (a + b)/2;
		
		if(func_1(y) == 0){
		    break;
		}   
		else if(func_1(y)*func_1(b) < 0){
		    a = y;
		}
		else{
		    b = y;
		}		
	    }

	    break; 
	case 2:
	    while((b-a) >= n){
		y = (a + b)/2;
		
		if(func_2(y) == 0){
		    break;
		}   
		else if(func_2(y)*func_2(b) < 0){
		    a = y;
		}
		else{
		    b = y;
		}		
	    } 

	    break;
	case 3:
	    while((b-a) >= n){
		y = (a + b)/2;
		 
		if(func_3(y) == 0){
		    break;
		}  
		else if(func_3(y)*func_3(b) < 0){
		    a = y;
		}
		else{
		    b = y;
		}		
	    }

	    break; 
    }
    return y;
}

int main(){
    double a, b, n;
    int f;
    
    cout << " You can solve one function at a time. " << endl;
    cout << " 1) f(x) = x*e^x -1 " << endl;
    cout << " 2) f(x) = cos(x) - x*e^x " <<endl;
    cout << " 3) f(x) = x*sin(x) + cos(x) " << endl;

    while(f != 1 || f != 2 || f != 3){
	cout << " Enter the coresponding number for the function you want to solve(1, 2, 3): ";
	cin >> f;
	
	if(f == 1 || f == 2 || f == 3){
	    break;
	}
	else{
	    cout << "    ERROR! INPUT IS NOT VALID!    " << endl;
	}
    }

    cout << " Enter the decimal point(ex- 0.001): ";
    cin >> n;

    cout << " Enter the first interval: ";
    cin >> a;
    cout << " Enter the last interval: ";
    cin >> b;
    
    switch(f){
	case 1:
	    while(func_1(a)*func_1(b) >= 0){
		cout << " Your Input Values are not Valid!" << endl;
		cout << " Hint: solve the probloem on paper or draw some plot." << endl;
		cout << " Please Enter The Values Again." << endl;
		cout << " Enter The 1st interval: ";
		cin >> a;
		cout << " Enter The Last interval: ";
		cin >> b;
	    }

	    cout << fixed << setprecision(4) << " Root = " << Bisection(a, b, n, f) << endl;

	    break;
	case 2:
	    while(func_2(a)*func_2(b) >= 0){
		cout << " Your Input Values are not Valid!" << endl;
		cout << " Hint: solve the probloem on paper or draw some plot." << endl;
		cout << " Please Enter The Values Again." << endl;
		cout << " Enter The 1st interval: ";
		cin >> a;
		cout << " Enter The Last interval: ";
		cin >> b;
	    }

	    cout << fixed << setprecision(4) << " Root = " << Bisection(a, b, n, f) << endl;

	    break;
	case 3:
	    while(func_3(a)*func_3(b) >= 0){
		cout << " Your Input Values are not Valid!" << endl;
		cout << " Hint: solve the probloem on paper or draw some plot." << endl;
		cout << " Please Enter The Values Again." << endl;
		cout << " Enter The 1st interval: ";
		cin >> a;
		cout << " Enter The Last interval: ";
		cin >> b;
	    }

	    cout << fixed << setprecision(4) << " Root = " << Bisection(a, b, n, f) << endl;

	    break;
    }

    double x, y, p;
    int q;

    cout << " You can plot one function at a time. " << endl;
    cout << " 1) f(x) = x*e^x - 1 " << endl;
    cout << " 2) f(x) = cos(x) - x*e^x " << endl;
    cout << " 3) f(x) = x*sin(x) + cos(x) " << endl;
    
    while(q != 1 || q != 2 || q != 3){
	cout << " Enter the coresponding number for the function you want to solve(1, 2, 3): ";
	cin >> q;
	
	if(q == 1 || q == 2 || q == 3){
	    break;
	}
	else{
	    cout << "    ERROR! INPUT IS NOT VALID!    " << endl;
	}
    }

    cout << " Enter the first value of x for graph: ";
    cin >> x;
    cout << " Enter the last value of x for graph: ";
    cin >> y;

    cout << " Enter the minimum difference through x axis for graph: ";
    cin >> p;

    if(q == 1){
	ofstream fadata("func_1.dat");

	for(double i = x; i <= y; i +=p){
	    fadata << fixed << setprecision(4) << i << "\t" << func_1(i) << endl;
	}

	fadata.close();

	 cout << " You can now run GNUPlot " << endl;
    }
    else if(q == 2){
	ofstream fbdata("func_2.dat");

	for(double i = x; i <= y; i +=p){
	    fbdata << fixed << setprecision(4) << i << "\t" << func_2(i) << endl;
	}

	fbdata.close();

	 cout << " You can now run GNUPlot " << endl;
    }
    else if(q == 3){
	ofstream fcdata("func_3.dat");

	for(double i = x; i <= y; i +=p){
	    fcdata << fixed << setprecision(4) << i << "\t" << func_3(i) << endl;
	}

	fcdata.close();

	 cout << " You can now run GNUPlot " << endl;	
    }

//create a brach for plot input...

    ofstream testdata("cos.dat");

    for(double i = -1; i <= 1; i += 0.01){
	testdata << fixed << setprecision(4) << i << "\t\t" << i*exp(i) - 1 << endl;
    }

    testdata.close();

    cout << func_1(M_PI) << endl;    
    cout << func_2(M_PI) << endl;
    cout << func_3(M_PI) << endl;
	
    return 0;
}
