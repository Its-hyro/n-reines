#include <stdint.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>
#include "queens.h"

// Teste la fonction parse_args avec différents cas
static void test_parse_args(void **state) {
(void) state;
  /* no arg, too many args */
  assert_int_equal(-1, parse_args(1, (char*[]){"queens"}));
  assert_int_equal(-1, parse_args(3, (char*[]){"queens", "1", "2"}));
  /* invalid arg */
  assert_int_equal(-1, parse_args(2, (char*[]){"queens", "notanint"}));
  assert_int_equal(-1, parse_args(2, (char*[]){"queens", "-10"}));
  assert_int_equal(-1, parse_args(2, (char*[]){"queens", "0"}));
  /* valid arg */
  assert_int_equal(153, parse_args(2, (char*[]){"queens", "153"}));
  /* avec un arguement tres grand */
  assert_int_equal(-1, parse_args(2, (char*[]){"queens", "9999999999999999999999999999"}));
  /* limits positif ou negatif*/
  assert_int_equal(2147483647, parse_args(2, (char*[]){"queens", "2147483647"})); 
  assert_int_equal(-1, parse_args(2, (char*[]){"queens", "2147483648"})); 
  /* notation scientifique avec exposant*/
  assert_int_equal(-1, parse_args(2, (char*[]){"queens", "1e6"}));
  /* argument vide */
  assert_int_equal(-1, parse_args(2, (char*[]){"queens", ""}));
  /* avec chaine de caractere */
  assert_int_equal(-1, parse_args(2, (char*[]){"queens", "153abc"}));
}
// Teste si deux reines sont sur la même diagonale
static void test_same_diagonal(void **state) {
    (void)state;
    assert_true(check_same_diagonal(0, 0, 1, 1)); 
    assert_false(check_same_diagonal(0, 0, 1, 2)); 
}

static void test_main_no_args(void **state) {
    (void) state;

    assert_int_equal(-1, parse_args(1, (char*[]){"queens"}));
}

static void test_main_invalid_args(void **state) {
    (void) state; 

    assert_int_equal(-1, parse_args(2, (char*[]){"queens", "invalid"}));
    assert_int_equal(-1, parse_args(2, (char*[]){"queens", "-999"}));
    assert_int_equal(-1, parse_args(2, (char*[]){"queens", "1e10"}));  
}

static void test_main_large_valid_arg(void **state) {
    (void) state; 

    assert_int_equal(2147483647, parse_args(2, (char*[]){"queens", "2147483647"}));  
}

static void test_main_empty_arg(void **state) {
    (void) state;

    assert_int_equal(-1, parse_args(2, (char*[]){"queens", ""}));
}
// Fonction principale pour exécuter les tests avec CMocka
int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_same_diagonal),
        cmocka_unit_test(test_parse_args),
        cmocka_unit_test(test_main_no_args),
        cmocka_unit_test(test_main_invalid_args),
        cmocka_unit_test(test_main_large_valid_arg),
        cmocka_unit_test(test_main_empty_arg),
    };
    // Exécution des tests
    return cmocka_run_group_tests(tests, NULL, NULL);
}
