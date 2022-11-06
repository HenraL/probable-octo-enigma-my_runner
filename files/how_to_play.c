/*
** EPITECH PROJECT, 2021
** runner - how_to_play.c
** File description:
** jitter jitter
*/

#include "include/my_lib.h"

void show_howto(void)
{
    my_putstr("KEYS TO PLAY THE GAME:\n\n");
    my_putstr(".--------------------------------------------------------.\n");
    my_putstr("| [Esc]                                            o o o |\n");
    my_putstr("| |                                                      |\n");
    my_putstr("| |[`][1][2][3][4][5][6][7][8][9][0][-][=]  [_<_]        |\n");
    my_putstr("| |[|-][Q][W][E][R][T][Y][U][I][O][P][{][}]   | |        |\n");
    my_putstr("| |[CAP]|[A][S][D]|[F][G][H][J][K][L][;]['][#]|_|        |\n");
    my_putstr("| |[^][\\|]|[Z|][X]|[C][V][B][N][M][,][.][/][^]|.___[^]   |\n");
    my_putstr("| |[c]  | |[a|][__|_|_____|____|______][a][c] ||[<][V][>]|\n");
    my_putstr("`-|-----|-|--|----|-|--|--|----|--------------|||--|-/---'\n");
    my_putstr("  |     | |  |    | |  |  |    |              |||  |/_>Right\n");
    my_putstr("  |     | |  |    | |  |  |    |              |||  |_> Down\n");
    my_putstr("  |     | |  |    | |  |  |    |              |||__> Left\n");
    my_putstr("  |     | |  |    | |  |  |    |              ||___> Jump\n");
    my_putstr("  |     | |  |    | |  |  |    |______________|_> Main menu\n");
    my_putstr("  |     | |  |____|_|__|__|___________________|_> Start Game\n");
    my_putstr("  |     | |_______|_|_____|_____________________> Super Jump\n");
    my_putstr("  |     |         |_____________________________> Retry\n");
    my_putstr("  |_____|_______________________________________> Quit\n");
}

