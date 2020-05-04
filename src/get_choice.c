#include "get_choice.h"

char CHOICE;

void get_choice()
{
    scanf( " %c", &CHOICE );

    switch ( CHOICE ) {

        case '1':
            calculator();
            break;

        case '2':
            view_constants();
            break;

        case 'q':
            exit_program();
            break;

        default:
            printf( "ERROR: invalid option\n" );
    }
}

void view_constants()
{
    printf( "Constants:\n \
pi: 3.141592\n");
}

int exit_program()
{
    printf( "Goodbye!\n" );
    exit(0);
}
