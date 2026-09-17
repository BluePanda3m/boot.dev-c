#include "exercise.h"
#include "munit/munit.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static MunitResult test_swap_ints(const MunitParameter params[], void *user_data) {
  (void)params;
  (void)user_data;

  int a = 5;
  int b = 6;

  swap_ints(&a, &b);

  assert_int(a, ==, 6, "a is now 6");
  assert_int(b, ==, 5, "b is now 5");

  return MUNIT_OK;
}

static MunitResult test_swap_ints_same(const MunitParameter params[], void *user_data) {
  (void)params;
  (void)user_data;

  int a = 5;

  swap_ints(&a, &a);

  assert_int(a, ==, 5, "a is still 5");

  return MUNIT_OK;
}

int main() {
  MunitTest tests[] = {
      munit_test("/swap_ints", test_swap_ints),
      munit_test("/swap_ints_same", test_swap_ints_same),
      munit_null_test,
  };

  MunitSuite suite = munit_suite("void-pointer", tests);
  return munit_suite_main(&suite, NULL, 0, NULL);
}
