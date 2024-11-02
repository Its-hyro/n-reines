#include <stdint.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>
#include <stdio.h>

#include "queens.h"

// Teste la fonction check_same_diagonal avec plusieurs cas
static void test_same_diagonal(void **state) {
  (void) state;
  assert_true(check_same_diagonal(0, 0, 1, 1)); 
  assert_true(check_same_diagonal(2, 0, 3, 1));
  assert_false(check_same_diagonal(0, 0, 1, 2)); 
  assert_false(check_same_diagonal(1, 0, 2, 3)); 
}

// Teste la fonction check_column_ok avec des colonnes et lignes spécifiques
static void test_check_column_ok(void **state) {
  (void) state;
  int queen_row[] = {0, 2, -1, -1}; 
  assert_false(check_column_ok(2, 1, queen_row)); 
  assert_false(check_column_ok(2, 0, queen_row));
  assert_false(check_column_ok(2, 3, queen_row)); 
}

// Teste la fonction find_available pour trouver une ligne disponible
static void test_find_available(void **state) {
  (void) state;
  bool available[] = {true, false, true, true};
  assert_int_equal(find_available(0, 4, available), 0); 
  assert_int_equal(find_available(1, 4, available), 2); 
  assert_int_equal(find_available(3, 4, available), 3); 
  assert_int_equal(find_available(4, 4, available), -1); 
}

// Teste la fonction find_solution pour résoudre le problème des 4 reines
static void test_find_solution(void **state) {
  (void) state;
    int queen_row[4];
    assert_true(find_solution(4, queen_row)); 

    for (int i = 0; i < 4; i++) {
        assert_in_range(queen_row[i], 0, 3); 
    }
}
// Fonction principale pour exécuter les tests avec CMocka
int main(void) {
  int result = 0;
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_same_diagonal),
    cmocka_unit_test(test_check_column_ok),
    cmocka_unit_test(test_find_available),
    cmocka_unit_test(test_find_solution),
  };
  result |= cmocka_run_group_tests_name("queens", tests, NULL, NULL);

  return result;
}