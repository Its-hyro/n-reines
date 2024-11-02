#include <stdbool.h>

bool check_same_diagonal(const int c0, const int r0, const int c1, const int r1);
bool check_column_ok(const int c, const int r, const int queen_row[]);
bool find_solution(const int n, int queen_row[]);

void print_chessboard(int n, const int queen_row[]);
int find_available(const int min, const int n, const bool available[]);
int parse_args(int argc, char *argv[]);
