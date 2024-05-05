#include <stdio.h>
#include "math.h"
#include "Interpolation.h"

double Integral (double a, double b, double(*f)(double), int number){
    
    //Шаг разбиения всего отрезка
    double step = (b-a)/number;
    
    //Шаг разбиения отрезка разбиения
    double in_step = step/3;
    
    //Начальное значение интеграла
    double integral = 0;
    
    //Цикл по отрезкам разбиения
    for (int i = 0; i < number; i++){
        
        //Четыре точки для интерполяции
        double dot1 = a + step*i;
        double dot2 = a + step*i + in_step;
        double dot3 = a + step*i + in_step*2;
        double dot4 = a + step*(i+1);
        
        //Массив точек для интерполяции
        double dots[4][2] = {{dot1, f(dot1)}, {dot2, f(dot2)}, {dot3, f(dot3)}, {dot4, f(dot4)}};
        
        integral += Interpolation(*dots);
    }
    
    return integral;
}
