#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void Gauss (double (*matrix)[5], double *solution){
    
    //Проверка наличия нулевой строки и сдвиг вниз (точки различны, если 0 есть, он он в одной строке)
    for (int i = 0; i < 3; i++){
        if (matrix[i][0] == 0){
            for (int j = 0; j < 5; j++){
                double tmp = matrix[3][j];
                matrix[3][j] = matrix[i][j];
                matrix[i][j] = tmp;
            }
            break;
        }
    }
    
    //Приведение к треугольному виду
    //Цикл по количеству строк
    for (int i = 3; i > 0; i--){
        
        //Цикл по строкам
        for (int j = 3; j > 3-i; j--){
            
            //Цикл по столбцам
            for (int n = 0; n < 5; n++){
                matrix[j][n] = matrix[j][n] - matrix[3-i][n]/matrix[3-i][3-i]*matrix[j][3-i];
            }
        }
    }
    
    //Обратный ход
    solution[3] = matrix[3][4]/matrix[3][3];
    solution[2] = (matrix[2][4]-matrix[2][3]*solution[3])/matrix[2][2];
    solution[1] = (matrix[1][4]-matrix[1][3]* solution[3]-matrix[1][2]*solution[2])/matrix[1][1];
    solution[0] = (matrix[0][4]-matrix[1][3]* solution[3]-matrix[1][2]*solution[2] - matrix[0][1]*solution[1])/matrix[0][0];
    
    
}

double Interpolation (double (*dots)[2]){
    
    /*
     Заполнить циклом
     */
    
    //Заполнение матрицы коэффициентов
    double matrix[4][5] = {};
    for (int i = 0; i < 4; i++){
        matrix[i][0] = pow(dots[i][0],3);
        matrix[i][1] = pow(dots[i][0],2);
        matrix[i][2] = pow(dots[i][0],1);
        matrix[i][3] = 1;
        matrix[i][4] = dots[i][1];
    }
    
    double *solution = (double*)malloc(sizeof(double)*(4));
    
    //Решение слу для определения коэффициентов
    Gauss(matrix, solution);
    
    //Возвращаемое значение - интеграл многочлена
    double a = dots[0][0];
    double b = dots[3][0];
    double integral = 1./4*solution[0]*(pow(b,4)-pow(a,4)) + 1./3*solution[1]*(pow(b,3)-pow(a,3)) + 1./2*solution[2]*(pow(b,2)-pow(a,2)) + solution[3]*(b-a);
    
    return integral;
}
