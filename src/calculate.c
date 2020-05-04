#include "calculate.h"

double calculate( double a, double b, char operator )
{
    switch (operator) {
        case '+':
            return add( a, b );
            break;

        case '/':
            return divide( a, b );
            break;

        case '-':
            return substract( a, b );
            break;

        case '*':
            return multiply(a, b);
            break;

        default:
            printf( "ERROR: invalid number or operator.." );
    }
    return -1;
}

double substract( double a, double b )
{
    return a - b;
}

double divide( double a, double b )
{
    return a / b;
}

double add( double a, double b )
{
    return a + b;
}

double multiply( double a, double b )
{
    return a * b;
}
