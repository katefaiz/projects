#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "inoutput.h"

int failed_funk(Errors failed) {
    switch(failed) {
        case INPUT_ERROR:
            printf("Error entering one of the tests\n");
            break;
        case TEST_ERROR:
            printf("The function failed the tests\n");
            break;
        case OPENFILE_ERROR:
            printf("File reading error\n");
            break;
        case ERROR_OK:
            printf("No errors\n");
            break;
        default: 
            printf("Error\n");
        
    }
    return 0;
}

int output_funk(Korny count__roots, double x1, double x2) {                                                                                                                             
    switch (count__roots) {
        case ANY_ROOTS :
            printf("X belongs to the set of real numbers\n");
            break;
        case NO_ROOTS :
            printf("No roots\n");
            break;
        case ONE_ROOT :
            printf("x = %g\n", x1);
            break;
        case TWO_ROOTS :
            printf(" The roots of this equation: \n x1 = %g \n x2 = %g \n", x1, x2);
            break;
        default: printf("Error\n");
    }
    return 0;
}

void clear_enter (void) { //clearing the buffer
    int ch = NAN;
    while ((ch = getchar( )) != EOF && ch  != '\n')
        ;
}

void enter_funk(double * const a, double * const b, double * const c) { //checking the input
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    while (scanf("%lf %lf %lf", a, b, c) != 3) {
        printf("Check that the input is correct\n");
        clear_enter();
    }
}
