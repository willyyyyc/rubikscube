#include <stdio.h>
#include "rubikscube.h"

int main() {
    RubiksCube_t rubiks_cube = new_cube();
    char *string = show_states(rubiks_cube);
    printf("%s",string);
    destroy_cube(rubiks_cube);
    return 0;
}
