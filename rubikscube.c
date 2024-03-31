//
// Created by will on 29/03/24.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "rubikscube.h"

typedef struct CubeFace {
    char orientation;
    char face[3][3];

} CubeFace;

typedef struct RubiksCube {
    CubeFace **faces;
} RubiksCube;


static CubeFace *new_face(char orientation, char colour) {
    CubeFace *cube_face = malloc(sizeof(CubeFace));
    if (cube_face == NULL) {
        // Handle memory allocation failure
        printf("Memory allocation failed");
        exit(1);
    }
    cube_face->orientation = orientation;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cube_face->face[i][j] = colour;
        }
    }
    return cube_face;
}

// Function to create rubik's cube (initialize cube struct and all 6 face structs)
extern RubiksCube_t new_cube() {
    RubiksCube *rubiks_cube = malloc(sizeof(RubiksCube));
    if (rubiks_cube == NULL) {
        // Handle memory allocation failure
        printf("Memory allocation failed");
        exit(1);
    }

    rubiks_cube->faces = malloc(6*sizeof(CubeFace));
    if (rubiks_cube->faces == NULL) {
        // Handle memory allocation failure
        free(rubiks_cube); // Free previously allocated memory
        printf("Memory allocation failed");
        exit(1);
    }
    rubiks_cube->faces[0] = new_face('F', 'W');
    rubiks_cube->faces[1] = new_face('U', 'B');
    rubiks_cube->faces[2] = new_face('R', 'R');
    rubiks_cube->faces[3] = new_face('B', 'Y');
    rubiks_cube->faces[4] = new_face('D', 'G');
    rubiks_cube->faces[5] = new_face('L', 'O');

    return rubiks_cube;
}

extern void destroy_cube(RubiksCube_t cube) {
    RubiksCube *rubiks_cube = (RubiksCube *)cube;
    assert(rubiks_cube != NULL);
    free(rubiks_cube->faces);
    free(rubiks_cube);
}

extern char* show_states(RubiksCube_t cube) {
    RubiksCube *rubiks_cube = (RubiksCube *)cube;
    char *cube_states = malloc(256*sizeof(char));
    strcpy(cube_states, "Cube State:\n");

    for (int i = 0; i < 6; i++) {
        strcat(cube_states, "Side: ");
        char buffer_1[2] = {rubiks_cube->faces[i]->orientation, '\0'};
        strcat(cube_states, buffer_1);
        strcat(cube_states, "\n");

        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                char buffer_2[2] = {rubiks_cube->faces[i]->face[row][col], '\0'};
                strcat(cube_states, buffer_2);
            }
            strcat(cube_states, "\n");
        }
        strcat(cube_states, "\n");
    }

    return cube_states;
}