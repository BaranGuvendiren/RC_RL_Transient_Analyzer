#ifndef CIRCUIT_IO
#define CIRCUIT_IO

char *export_rc_charging_to_csv(double v_source, double tau, int steps);
char *export_rc_discharging_to_csv(double v_initial, double tau, int steps);

char *export_rl_charging_to_csv(double i_max, double tau, int steps);
char *export_rl_discharging_to_csv(double i_initial, double tau, int steps);

int graph_csv_with_python(const char *csv_file, const char *title);

#endif