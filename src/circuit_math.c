#include <stdio.h>
#include <math.h>
#include "circuit_math.h"

double calculate_rl_tau(double r, double l) {
    if (r <= 0 || l <= 0) return NAN;
    return l / r;
}

double calculate_rc_tau(double r, double c) {
    if (r <= 0 || c <= 0) return NAN;
    return r * c;
}

double calculate_rc_charge(double v_source, double t, double tau) {
    if (tau <= 0) return NAN;
    return v_source * (1.0 - exp(-t / tau));
}

double calculate_rc_discharge(double v_source, double t, double tau) {
    if (tau <= 0) return NAN;
    return v_source * exp(-t / tau);
}

double calculate_rl_charge(double i_max, double t, double tau) {
    if (tau <= 0) return NAN;
    return i_max * (1.0 - exp(-t / tau));
}

double calculate_rl_discharge(double i_initial, double t, double tau) {
    if (tau <= 0) return NAN;
    return i_initial * exp(-t / tau);
}