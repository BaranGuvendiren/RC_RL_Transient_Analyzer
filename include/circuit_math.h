#ifndef CIRCUIT_MATH_H
#define CIRCUIT_MATH_H

double calculate_rc_tau(double r, double c);
double calculate_rl_tau(double r, double l);

double calculate_rc_charge(double v_source, double t, double tau);
double calculate_rc_discharge(double v_initial, double t, double tau);

double calculate_rl_charge(double i_max, double t, double tau);
double calculate_rl_discharge(double i_initial, double t, double tau);

#endif