#include <stdio.h>
#include <math.h>
#include "Func.h"
#include "Integral.h"

int main(void) {
    
    //Отрезок
    double start_point = 0;
    double stop_point = 3;
    
    //Настоящие значения интегралов
    double real_const = 5*stop_point - 5*start_point;
    double real_linear = 3.5*(pow(stop_point,2)-pow(start_point,2))+4*(stop_point-start_point);
    double real_square = -1./3*(pow(stop_point,3)-pow(start_point,3))+2*(pow(stop_point,2)-pow(start_point,2))+0.5*((stop_point-start_point));
    double real_trig = -(cos(stop_point)-cos(start_point));
    
    printf("Константа\n");
    for (int i = 15; i < 20; i++){
        int number = pow(2, i);
        
        double integral = Integral(start_point, stop_point, Const, number);
        printf("%d %lf\n", number, fabs(integral-real_const));
    }
    
    printf("\n");
    printf("Линейная функция\n");
    for (int i = 15; i < 20; i++){
        int number = pow(2, i);
        
        double integral = Integral(start_point, stop_point, LinearFunc, number);
        printf("%d %lf\n", number, fabs(integral-real_linear));
    }
    
    printf("\n");
    printf("Парабола\n");
    for (int i = 15; i < 20; i++){
        int number = pow(2, i);
        
        double integral = Integral(start_point, stop_point, SquareFunc, number);
        printf("%d %lf\n", number, fabs(integral-real_square));
    }
    
    printf("\n");
    printf("Тригонометрическая функция\n");
    for (int i = 15; i < 20; i++){
        int number = pow(2, i);
        
        double integral = Integral(start_point, stop_point, TrigFunc, number);
        printf("%d %lf\n", number, fabs(integral-real_trig));
    }
    
    return 0;
}
