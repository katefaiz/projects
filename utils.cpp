#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "utils.h"

int ravenstvo(double num1, double num2) {
    const double minimum = 1e-8;
    if (fabs(num1 - num2) > minimum)
        return false;
    else
        return true;
}

int if_zero (double f) {
    const double minimum = 1e-8;
    if (fabs(f) < minimum)
        return true;
    else
        return false;
}
