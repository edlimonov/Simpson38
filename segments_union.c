#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

//Объявление структуры point_2d
struct segment{
    double x;
    int weight;
};

//Обработка input: количество чисел четное и их больше нуля
int getLen(FILE *input, FILE *output) {
    int len = 0; double n;
    while(fscanf(input, "%lf", &n) == 1) len++;

    if ((len == 0) || (len%2 != 0)){
        fprintf(output, "Недостаточно данных");
        fclose(input);
        fclose(output);
        return -1;
    }
    return (len);
}

//Записываю в один массив концы отрезков с указанием типа
void get_dots(int len, struct segment *array, FILE *input){
    
    bool A = true;
    for (int i = 0; i < len; i++){
        if (A == true){
            fscanf(input, "%lf", &array[i].x);
            array[i].weight = 1;
            A = false;
        }
        else {
            fscanf(input, "%lf", &array[i].x);
            array[i].weight = -1;
            A = true;
        }
    }
}

//Сортировка массива точек по координате без учета типа
void sort_dots(int len, struct segment *array){
    int tmp = 0;
    for (int i = 0; i < len - 1; i++){
        for (int j = 0; j < len - i - 1; j++){
            if (array[j].x > array[j+1].x){
                tmp = array[j].x;
                array[j].x = array[j+1].x;
                array[j+1].x = tmp;
            }
        }
    }
}

int segment_union(int len, struct segment *array, struct segment L, struct segment R){

    int count = 0;
    //Проверка правой точки заданного отрезка
    for (int i = 0; i < len; i++){
        if (array[i].x < R.x){
            count += array[i].weight;
        } else break;
    }
    
    if (count == 0){
        return 2;
    }
    
    //Проверка точек разбиения
    for (int i = 0; i < len; i++){
        if (array[i].x < R.x && array[i].x > L.x){
            
            int count = 0;
            for (int j = 0; j < len; i++){
                if (array[j].x < array[i].x){
                    count += array[j].weight;
                } else break;
            }
            
            if (count == 0){
                return 2;
            }
        }
    }
    
    return 1;
}

int main(void) {
    
    //Проверка файлов
    FILE *input = fopen("/Users/nail/Desktop/proga_points /DOTS.txt", "r");
    if(input == NULL) return -1;
    
    FILE *output = fopen("/Users/nail/Desktop/proga_points /DOTSout.txt", "w");
    if(output == NULL){
        fclose(input);
        fclose(output);
        return -1;
    }
    
    //Получение количества концов отрезков
    int len = getLen(input, output);
    rewind(input);
    
    struct segment *dots = (struct segment *) malloc(sizeof(struct segment) * len);
    get_dots(len, dots, input);
    sort_dots(len, dots);
    
    //Ввод отрезка
    struct segment L;
    struct segment R;
    double x0 = 0;
    double y0 = 0;
    int a = scanf("%lf", &x0);
    int b = scanf("%lf", &y0);
    
    if (a + b < 2){
        fprintf(output, "Ошибка ввода");
        fclose(input);
        fclose(output);
        return -1;
    }
    
    L.x = x0;
    R.x = y0;
    L.weight = 2;
    R.weight = 2;
    
    int res = segment_union(len, dots, L, R);
    
    if (res == 1){
        fprintf(output, "Отрезок покрыт!\n");
    }
    else {
        fprintf(output, "Отрезок не покрыт!\n");
    }
    
    fclose(input);
    fclose(output);
    return 0;
}
