/*
** EPITECH PROJECT, 2021
** runner - option_dealing.c
** File description:
** jitter jitter
*/

#include "include/my_root.h"

int main_overflow(int argc, char **argv)
{
    if (argv[1][0] == '-' && (argv[1][1] == 'c' || argv[1][1] == 'C')) {
        show_credits();
    }
    if (argv[1][0] == '-' && (argv[1][1] == 'l' || argv[1][1] == 'L')) {
        return launch_game();
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        if_none();
        return 84;
    }
    if (argv[1][0] == '-' && (argv[1][1] == 'h' || argv[1][1] == 'H')) {
        show_help(argv);
    }
    if (argv[1][0] == '-' && (argv[1][1] == 'k' || argv[1][1] == 'K')) {
        show_howto();
    }
    return main_overflow(argc, argv);
}

void show_help(char **argv)
{
    my_putstr("Welcome to the help sections :-)\n");
    my_putstr("\nHOW TO CALL:\n");
    my_putstr("To display a section listed below please call the program the ");
    my_putstr("following way:\n\t-\t");
    my_putstr(argv[0]);
    my_putstr(" followed by one of the options (-h, -l, -k, -c).\n");
    my_putstr("\nTHE OPTIONS:\n");
    my_putstr("To display this section you cna use the '-h' option.\n");
    my_putstr("To start the game you can use the '-l' option.\n");
    my_putstr("To display the cheatset of keys for the game,");
    my_putstr("use the '-k' option.\n");
    my_putstr("To show the credits, you can use the '-c' option.\n");
}

void if_none(void)
{
    my_putstr("Please enter -h for help\n");
    my_putstr("Please enter -l to launch the game\n");
}
