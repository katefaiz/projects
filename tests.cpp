#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
//#include <calloc.h>

#include "utils.h"
#include "tests.h"
#include "SolveSquare.h"

Errors one_test_kvadr(double a, double b, double c, int nRootsref, double x1ref, double x2ref ) {
    double x1 = 0, x2 = 0;
    Korny nRoots = kvadr(a, b, c, &x1, &x2);
    if (nRootsref != nRoots ) {
        return TEST_ERROR;
    }
    switch (nRoots) {
            case ANY_ROOTS:    
            case 0:
                return ERROR_OK;
                break;
            case 1: 
                if (ravenstvo(x1, x1ref) || ravenstvo (x1, x2ref)) {
                    return ERROR_OK;
                } 
                else {
                    printf("error: function kvadr(%lg, %lg, %lg) gives out the wrong roots  \n", a, b, c);
                    printf("reference: x = %lg. The function returned: x =  %lg\n", x1ref, x1);
                    return TEST_ERROR;
                }
                break;
            case 2:
                if ((ravenstvo(x1, x1ref) && ravenstvo(x2, x2ref)) || (ravenstvo(x1, x2ref) && ravenstvo(x2, x1ref))) {
                    return ERROR_OK;
                }
                else { 
                    printf("error: function kvadr(%lg, %lg, %lg) gives out the wrong roots  \n", a, b, c);
                    printf("reference: x1 = %lg, x2 = %lg. The function returned: x1 = %lg, x2 = %lg\n", x1ref, x2ref, x1, x2);
                    return TEST_ERROR;
                }
                break;
            
            default:
                return TEST_ERROR; 
        }
    } 

/*Errors run_test(int * failed) { 
    int count_tests = 0;

    FILE * in = fopen("./source/data_for_tests.txt", "rb");
    if (in == NULL) {
        printf("Cannot open file.\n");
        return OPENFILE_ERROR;
    }
     if(fscanf (in, "%d", &count_tests) != 1){
         return INPUT_ERROR;
        }
        
    Equation data_tests = {};
    for (int i = 0; i < count_tests; i++) {
        if (fscanf(in, "%lg%lg%lg%d%lg%lg",
                                            &(data_tests.a), &(data_tests.b), &(data_tests.c),
                                            (int*) &(data_tests.nRoots), &(data_tests.x1), &(data_tests.x2)) != 6){ 
            return INPUT_ERROR;
        }
        
        if (one_test_kvadr(data_tests.a, data_tests.b, data_tests.c, data_tests.nRoots, data_tests.x1, data_tests.x2) != ERROR_OK){
            *failed += 1;
            printf("Error in %lf %lf %lf %d %lf %lf \n", data_tests.a,  data_tests.b, data_tests.c, data_tests.nRoots, data_tests.x1, data_tests.x2 );
            return TEST_ERROR;
        }
    }
    fclose(in);
    return ERROR_OK;     
}*/




Errors run_test(int * failed) { 
    int count_tests = 0;

    FILE * in = fopen("./source/data_for_tests.txt", "rb");
    if (in == NULL) {
        printf("Cannot open file.\n");
        return OPENFILE_ERROR;
    }
    if(fscanf (in, "%d", &count_tests) != 1){
         return INPUT_ERROR;
        }
    //char buffer[255] = {'\n'}; // так можно???
    
    fseek(in, 0, SEEK_END); //ставит указатель на конец

    long fsize = ftell(in); //ftell() возвращает текущее значение указателя, считает размер файла
    fseek(in, 0, SEEK_SET); // перемещает на начало

    char *string = calloc(1, fsize + 1); // выделяем память для строки-буффера
    fread(string, fsize, 1, in);  
    fclose(in);

    string[fsize] = 0; // завершаем нуль-символом

    Equation data_tests = {};
    for (int i = 0; i < count_tests; i++) {
        if (fscanf(in, "%lg%lg%lg%d%lg%lg",
                                            &(data_tests.a), &(data_tests.b), &(data_tests.c),
                                            (int*) &(data_tests.nRoots), &(data_tests.x1), &(data_tests.x2)) != 6){ 
            return INPUT_ERROR;
        }
        
        if (one_test_kvadr(data_tests.a, data_tests.b, data_tests.c, data_tests.nRoots, data_tests.x1, data_tests.x2) != ERROR_OK){
            *failed += 1;
            printf("Error in %lf %lf %lf %d %lf %lf \n", data_tests.a,  data_tests.b, data_tests.c, data_tests.nRoots, data_tests.x1, data_tests.x2 );
            return TEST_ERROR;
        }
    }


    
    /*struct Equation * data_tests = (struct Equation *)calloc(count_tests, sizeof(struct Equation)); // указатель на ячейку память, где начинается массив??
      
    int j = 0;
    while (fgets(buffer, sizeof(buffer), in) != NULL) {
        assert(j < count_tests);
        
        sscanf (buffer , "%lg %lg %lg %d %lg %lg", &(data_tests[j].a), &(data_tests[j].b), &(data_tests[j].c),
                                                (int*) &(data_tests[j].nRoots), &(data_tests[j].x1), &(data_tests[j].x2));
        j++;
    }
    // return ERROR_OK;
       
    //можно ли написатьт без буфера
    for (int i = 0; i < count_tests; i++){
        if (one_test_kvadr(data_tests[i].a, data_tests[i].b, data_tests[i].c, data_tests[i].nRoots, data_tests[i].x1, data_tests[i].x2) != ERROR_OK){
            *failed += 1;
            printf("Error in %lf %lf %lf %d %lf %lf \n", data_tests[i].a,  data_tests[i].b, data_tests[i].c, data_tests[i].nRoots, data_tests[i].x1, data_tests[i].x2 );
            return TEST_ERROR;
        }
    }*/
    
    return ERROR_OK;
}



