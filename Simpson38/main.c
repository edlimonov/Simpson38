#include <stdio.h>
#include <math.h>
#include "Func.h"
#include "Integral.h"

int main(void) {
    
    for (int i = 15; i < 20; i++){
        
        //Количество отрезков разбиения
        int number = pow(2, i);
        
        double integral = Integral(3, 8, SquareFunc, number);
        printf("%d %lf\n", number, integral);
        
    }
    
    return 0;
}
