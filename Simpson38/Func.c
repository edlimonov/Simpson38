#include <stdio.h>
#include <math.h>

double Const (double x){
    return (5);
}

double LinearFunc (double x){
    double k = 7;
    double b = 4;
    return (x*k + b);
}

double SquareFunc (double x){
    double a = -1;
    double b = 4;
    double c = 0.5;
    return (a*x*x + b*x + c);
}

double TrigFunc (double x){
    return (sin(x));
}



