/**
 * fixed_point_iteration.c
 * Implementation of the fixed-point iteration method.
 *
 * Author: Dr Keegan D. Anderson
 * Created: 2026-07-20
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITER 100
#define TOL 1e-15

/* Mathematical function definition */
double f(double x) {
  return log(2*x + 1);
}

/* Main function */
int main() {
  /* Algorithm parameters */
  double x0 = 1.0; // Initial condition
  double x1 = 0; // Iteration variable
  double err = 0;
  int k = 0; // Iteration counter
                     
  /* Fixed-point iteration method implementation */
  for (k = 0; k < MAX_ITER; k++) {
    x1 = f(x0);
    err = fabs(x1 - x0);

    printf("%3d %12.8f %12.8f %12.8g\n",
        k, x0, x1, err);

    /* Tolerance met */
    if (err < TOL) {
      printf("Convergence after %d iterations.\n", k);
      break;
    }
    x0 = x1;
  }

  // Print results to console
  printf("\nApproximate fixed point = %.15f\n", x1);
  printf("f(root) = %.15e\n", f(x1));
  printf("Final absolute error = %.15e\n", err);

  return EXIT_SUCCESS;
}
