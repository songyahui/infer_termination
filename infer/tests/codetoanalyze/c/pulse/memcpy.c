/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

struct X {
  int f;
};

typedef struct X X;

void test_ok() {
  X x;
  X* p = malloc(sizeof(X));
  if (p)
    memcpy(p, &x, sizeof(X));
  free(p);
}

void FN_test_bad1() {
  X x;
  X* p = 0;
  memcpy(p, &x, sizeof(X)); // crash
}

void FN_test_bad2() {
  X x;
  X* r;
  X* p = 0;
  r = p;
  memcpy(r, &x, sizeof(X)); // crash
}

void FN_test_bad3() {
  X* x = 0;
  X* p = malloc(sizeof(X));
  if (p) {
    memcpy(p, x, sizeof(X)); // crash
    free(p);
  }
}
