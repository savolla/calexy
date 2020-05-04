#include "calculator.h"

double NUM_0;
double NUM_1;
char OPERATOR;
double RESULT;

void calculator()
{
    NUM_0 = get_number();
    NUM_1 = get_number();
    OPERATOR = get_operator();
    RESULT = calculate( NUM_0, NUM_1, OPERATOR );
    show_result( RESULT );
}

double get_number()
{
    double number;
    printf( "n0: " );
    scanf( "%lf", &number );
    return number;
}

char get_operator()
{
    char operator;
    printf( "operator: " );
    scanf( " %c", &operator );
    return operator;
}

void show_result( double result )
{
    printf( "%f", result );
}
