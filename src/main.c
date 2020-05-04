#include "dialog.h"
#include "get_choice.h"

int main( void ) {

    welcome();

    while ( 1 )
    {
        print_main_menu();
        get_choice();
    }

    return 0;
}
