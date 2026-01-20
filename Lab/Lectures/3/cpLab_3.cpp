//This is a raw cpp/c++ file that can be compiled with GCC or other c/c++ compiler

//Problem
/*

For a symmetric slab wave-guide, to obtain the mode one need to solve the following Equation.

	tan(hd - m*(pie/2)) = (v^2 - (h^2 * d^2))^0.5 / h*d

    where,
	h --> propagation constant
	d --> is the thickness of slab
	v --> v-numbers-

    plot, i) y = tan(hd - m*(pie/2)) and
         ii) y = (v^2 - (h^2 * d^2))^0.5 / h*d 

    for hd is [0, 20], for m = 0, 1, 2, 3, 4 and 5. And v = 5*pie.
    This will give you 6 different solutions of the above equation(for 6 different values of m).

    Use c++ to write a code to solve the above equation by using Newton-Raphson Method.

*/

//Solution

#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#define E 0.00001

using namespace std;

//func_a represnts the LHS of the given equation
double func_a(double x, int m){
    double y;
    double a;
    
    a = m*(M_PI/2);
    y = sin(x - a)/cos(x - a);

    return y;
}

//func_b represents the RHS of the given equation
double func_b(double x, double v){
    double y;
    double a;
    double b;

    a = pow(v, 2) - pow(x, 2);
    b = sqrt(a); 
    y = b/x;

    return y;
}

//f represnts the equation
double f(double x, int m){
    double a;
    double b;

    a = func_a(x, m);
    b = func_b(x, 5*M_PI);    //since v = 5*pie

    return a - b;
}

//dfunc_a represents the derivative of func_a
double dfunc_a(double x, int m){
    double y;
    double a;
    double b;

    a = x - m*(M_PI/2);
    b = 1/cos(a);
    y = pow(b, 2);

    return y;
}

//dfunc_b represents the derivative of func_b
double dfunc_b(double x, double v){
    double y;
    double a;
    double b;
    double c;

    a = pow(x, 2);
    b = pow(v, 2);
    c = a*sqrt(b - a);
    y = -b/c;

    return y;
}

//df represents the derivative of the given equation
double df(double x, int m){
    double a;
    double b;

    a = dfunc_a(x, m);
    b = dfunc_b(x, 5*M_PI);    //since v = 5*pie

    return a - b;
}

//Function for Newton-Raphson Method
double NR(double x, int m){
    double h;
    
    do{
	h = f(x, m)/df(x, m);
	x = x - h;
    }while(abs(h) >= E);
    
    return x;
}

int main(){
    
    //A file to store the outputs of func_a
    ofstream fadata("func_a.dat");

    for(double i = 0.00; i <= 20; i += 0.01){
	if(func_a(i, 0) < 40 && func_a(i, 0) > -40 && func_a(i, 1) < 40 && func_a(i, 1) > -40){
	    fadata << fixed << setprecision(4) << i << "\t" << func_a(i, 0) <<"\t" << func_a(i, 1) << endl;
	}
	else if(func_a(i, 0) > 40 || func_a(i, 0) < -40){
	    if(func_a(i, 1) < 40 && func_a(i, 1) > -40 ){
		fadata << fixed << setprecision(4) << i << "\t" << "nan\t" << func_a(i, 1) << endl;
	    }
	    else{
		fadata << fixed << setprecision(4) << i << "\t" << "nan\t" << "nan" << endl;
	    }
	}
	else if(func_a(i,1) > 40 || func_a(i,1) < -40){
	    if(func_a(i, 0) < 40 && func_a(i, 0) > -40){
		fadata << fixed << setprecision(4) << i << "\t" << func_a(i, 0) << "\t" << "nan" << endl;
	    }
	}
    }    

    fadata.close();

    //Plot Script for func_a.dat
    //gnuplot -e "set term windows; set grid; plot 'func_a.dat' u 1:2  w l title 'm = 0' '' u 1:3 w l title 'm = 1'; pause-1"
    
    //A file to store the outputs of func_b
    ofstream fbdata("func_b.dat");

    for(double i = 0.00; i <= 20.00; i += 0.01){
	if(func_b(i, 5*M_PI) < 40 && func_b(i, 5*M_PI) > -40){
	    fbdata << fixed << setprecision(4) << i << "\t" << func_b(i, 5*M_PI) << endl;
	}
	else{
	    fbdata << fixed << setprecision(4) << i << "\t" << "nan" << endl;
	}
    }

    fbdata.close();

    //Plot script for func_b.dat
    //gnuplot -e "set term windows; set grid; plot 'func_b.dat' w l lw 2 title 'RHS'; pause-1"
    
    //A file to store the outputs of both func_a and func_b for ploting
    ofstream allplot("all_plot.dat");

    for(double i = 0.00; i <= 20.00; i += 0.01){
	
	if(func_a(i, 0) > 40 || func_a(i, 0) < -40){
	    if(func_a(i, 1) < 40 && func_a(i, 1) > -40){
		if(func_b(i, 5*M_PI) < 40 && func_b(i, 5*M_PI) > -40){
		    allplot << fixed << setprecision(2) << i << "\t" << "nan\t" << func_a(i, 1) << "\t" << func_b(i, 5*M_PI) << endl;
		}
		else if(func_b(i, 5*M_PI) > 40 || func_b(i, 5*M_PI) < -40){
		    allplot << fixed << setprecision(2) << i << "\t" << "nan\t" << func_a(i, 1) << "\t" << "nan" << endl;
		}
	    }
	    else if(func_a(i, 1) > 40 || func_a(i, 1) < 40){
		if(func_b(i, 5*M_PI) < 40 && func_b(i, 5*M_PI) > -40){
		    allplot << fixed << setprecision(2) << i << "\t" << "nan\t" << "nan\t" << func_b(i, 5*M_PI) << endl;
		}
		else if(func_b(i, 5*M_PI) > 40 || func_b(i, 5*M_PI) < -40){
		    allplot << fixed << setprecision(2) << i << "\t" << "nan\t" << "nan\t" << "nan" << endl;
		}
	    }
	}
	else if(func_a(i, 0) < 40 && func_a(i, 0) > -40){
	    if(func_a(i, 1) < 40 && func_a(i, 1) > -40){
		if(func_b(i, 5*M_PI) < 40 && func_b(i, 5*M_PI) > -40){
		    allplot << fixed << setprecision(2) << i << "\t" << func_a(i, 0) << "\t" << func_a(i, 1) << "\t" << func_b(i, 5*M_PI) << endl;
		}
		else if(func_b(i, 5*M_PI) > 40 || func_b(i, 5*M_PI) < -40){
		    allplot << fixed << setprecision(2) << i << "\t" << func_a(i, 0) << "\t" << func_a(i, 1) << "\t" << "nan" << endl;
		}
	    }
	    else if(func_a(i, 1) > 40 || func_a(i, 1) < -40){
		if(func_b(i, 5*M_PI) < 40 && func_b(i, 5*M_PI) > -40){
		    allplot << fixed << setprecision(2) << i << "\t" << func_a(i, 0) << "\t" << "nan\t" << func_b(i, 5*M_PI) << endl;
		}
		else if(func_b(i, 5*M_PI) > 40 || func_b(i, 5*M_PI) < -40){
		    allplot << fixed << setprecision(2) << i << "\t" << func_a(i, 0) << "\t" << "nan\t" << "nan" << endl;
		}
	    }
	}    //Huge nested if-else statement, I know because I wrote it.
    }

    allplot.close();

    //plot script for all_plot.dat
    //gnuplot -e "set term windows; set grid; plot 'all_plot.dat' u 1:2 w l title 'tan(hd), m=0', '' u 1:3 w l title 'm=1', '' u 1:4 w l lw 2 title 'RHS'; pause-1"

    //from the plot of all_plot.dat file you can take 6 aproximate solution, 3 from m=0 and 3 from m=1

    double a[6] = {1.49, 2.95, 4.43, 5.88, 7.38, 8.82};    //aproximate solutions

    for(int i = 0; i < 6; i++){
	cout << "For m = " << i << "\t" "The value of hd is: " << fixed << NR(a[i], i) << endl;
    }

    return 0;
}