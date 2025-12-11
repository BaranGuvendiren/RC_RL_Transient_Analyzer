#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "circuit_math.h"
#include "circuit_io.h"

char *export_rc_charging_to_csv(double v_source, double tau, int steps) {
    FILE *fptr = fopen("output/rc_charging.csv", "w");
    if (fptr == NULL) return NULL;

    fprintf(fptr, "Time,Voltage\n");

    double total_duration = 5 * tau;
    double time_step = total_duration / steps;
    double t = 0.0;
    
    for (int i = 0; i <= steps; i++) {
        fprintf(fptr, "%f,%f\n", t, calculate_rc_charge(v_source, t, tau));
        t += time_step;
    }

    fclose(fptr);
    return "output/rc_charging.csv";
}

char *export_rc_discharging_to_csv(double v_source, double tau, int steps) {
    FILE *fptr = fopen("output/rc_discharging.csv", "w");
    if (fptr == NULL) return NULL;

    fprintf(fptr, "Time,Voltage\n");

    double total_duration = 5 * tau;
    double time_step = total_duration / steps;
    double t = 0.0;
    
    for (int i = 0; i <= steps; i++) {
        fprintf(fptr, "%f,%f\n", t, calculate_rc_discharge(v_source, t, tau));
        t += time_step;
    }

    fclose(fptr);
    return "output/rc_discharging.csv";
}

char *export_rl_charging_to_csv(double i_max, double tau, int steps) {
    FILE *fptr = fopen("output/rl_charging.csv", "w");
    if (fptr == NULL) return NULL;

    fprintf(fptr, "Time,Current\n");

    double total_duration = 5 * tau;
    double time_step = total_duration / steps;
    double t = 0.0;
    
    for (int i = 0; i <= steps; i++) {
        fprintf(fptr, "%f,%f\n", t, calculate_rl_charge(i_max, t, tau));
        t += time_step;
    }

    fclose(fptr);
    return "output/rl_charging.csv";
}

char *export_rl_discharging_to_csv(double i_initial, double tau, int steps) {
    FILE *fptr = fopen("output/rl_discharging.csv", "w");
    if (fptr == NULL) return NULL;

    fprintf(fptr, "Time,Current\n");

    double total_duration = 5 * tau;
    double time_step = total_duration / steps;
    double t = 0.0;
    
    for (int i = 0; i <= steps; i++) {
        fprintf(fptr, "%f,%f\n", t, calculate_rl_discharge(i_initial, t, tau));
        t += time_step;
    }

    fclose(fptr);
    return "output/rl_discharging.csv";
}

int graph_csv_with_python(const char *csv_file, const char *title) {
    char command[300];
    snprintf(command, sizeof(command), "python3 scripts/circuit_graph.py %s '%s'", csv_file, title);

    return system(command);
}