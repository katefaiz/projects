#include <TXLib.h>
#include <stdio.h>
#include <math.h> 
#include <assert.h> 

#include "tests.h"
#include "SolveSquare.h"
#include "inoutput.h"
#include "enum_and_struct.h"
#include "utils.h"

int main() { 
#ifdef TEST
    int failed = 0;
    Errors status = run_test(&failed);
    failed_funk(status);
    if (failed) {
        printf("meow %d tests failed\n", failed);
        return 1;
    }
#endif

    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    printf("Enter the coefficients a, b, c of the equation a*x^2 + b*x + c\n");
    enter_funk(&a, &b, &c);
    Korny count_roots = kvadr(a, b, c, &x1, &x2);
    output_funk(count_roots, x1, x2);

    return 0;
}




