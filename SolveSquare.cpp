#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "SolveSquare.h"
#include "utils.h"

Korny kvadr(double a,double b, double c, double * const x1, double * const x2) {
    assert(x1 != NULL);
    assert(x2 != NULL);
    
    if (!(if_zero(a))) { //if a != 0

        double dis = b * b - 4 * a * c; //discriminant

        if (dis >= 0) {

            if (if_zero(dis)) { // dis == 0
                *x1 = (- b) / (2 * a);
                *x2 = NAN ;
                return ONE_ROOT;
            }
            else { // dis > 0
                *x1 = (- b - sqrt(dis)) / (2 * a);
                *x2 = (- b + sqrt(dis)) / (2 * a);
                return TWO_ROOTS;
            }
        }
        else { // dis < 0
            return NO_ROOTS;
        }
    } 
    else { 
        return lineyn(b, c, x1, x2); 
    }
}

Korny lineyn(double b, double c, double *  const x1, double * const x2) {   
    assert(x1 != NULL);
    assert(x2 != NULL);

    if (if_zero(b)) { // b == 0
        if (if_zero(c)) // c == 0
            return ANY_ROOTS;
        else
            return NO_ROOTS; 
    }
    else { // b != 0
        *x1 = - c / b;
        *x2 = *x1;
        return ONE_ROOT;
    }
}


