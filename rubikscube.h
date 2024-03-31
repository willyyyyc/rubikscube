//
// Created by will on 29/03/24.
//

#ifndef RUBIKSCUBE_RUBIKSCUBE_H
#define RUBIKSCUBE_RUBIKSCUBE_H

typedef void * RubiksCube_t;

extern RubiksCube_t new_cube();
extern void destroy_cube(RubiksCube_t cube);
extern char* show_states(RubiksCube_t cube);

// moves
extern void move_u(RubiksCube_t cube);
extern void move_r(RubiksCube_t cube);
extern void move_f(RubiksCube_t cube);
extern void move_d(RubiksCube_t cube);
extern void move_l(RubiksCube_t cube);
extern void move_b(RubiksCube_t cube);
extern void move_m(RubiksCube_t cube);
extern void move_e(RubiksCube_t cube);
extern void move_s(RubiksCube_t cube);
extern void move_u_prime(RubiksCube_t cube);
extern void move_r_prime(RubiksCube_t cube);
extern void move_f_prime(RubiksCube_t cube);
extern void move_d_prime(RubiksCube_t cube);
extern void move_l_prime(RubiksCube_t cube);
extern void move_b_prime(RubiksCube_t cube);
extern void move_m_prime(RubiksCube_t cube);
extern void move_e_prime(RubiksCube_t cube);
extern void move_s_prime(RubiksCube_t cube);

#endif //RUBIKSCUBE_RUBIKSCUBE_H
