/**
 * bisection.c
 * Implementation of the bisection method.
 *
 * Author: Dr Keegan D. Anderson
 * Created: 2026-07-18
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Mathematical function definition */
double f(double x) {
  return exp(x) - 2*x - 1;
}

/* Main function */
int main() {
  /* Algorithm parameters */
  const double tol = 1e-5; // Tolerance
  const double a0 = 1.0; // Lower bound of bracketing interval
  const double b0 = 2.0; // Upper bound of bracketing interval
  
  /* Initial interval */
  double a = a0;
  double b = b0;
  double fa = f(a);
  double fb = f(b);
  double c, fc;
  int k = 0; // Iteration counter
                     
  /* Verify that the interval brackets the root */
  if (fa*fb > 0) {
    fprintf(stderr,
        "Error: interval [%.6f, %.6f] does not bracket a root.\n",
        a0, b0);
    return EXIT_FAILURE;
  }
                      
  /* Calculate the required number of iterations for the given tolerance and
   * interval */
  int iter_req = ceil((log(fabs(b0 - a0)/tol)/log(2)));
  printf("Required number of iterations for specified tolerance %g: %d\n\n", 
    tol, iter_req);

  /* Bisection method implementation */
  for (k = 0; k < iter_req; k++) {
    // Calculate midpoint
    c = (a + b)/2; // Use c = a + (b - a)/2 to avoid floating-point arithmetic
                   // issues
    fc = f(c);

    printf("%3d %12.8f %12.8f %12.8f %12.8e\n",
        k, a, c, b, fabs(b-a));

    // Exact root found
    if (fabs(fc) < 1e-15) {
      printf("Exact root found.\n");
      break;
    }

    // Update interval
    if (fa*fc < 0) {
      b = c;
      fb = fc;
    } else {
      a = c;
      fa = fc;
    }

    // Optional convergence test
    if (fabs(b-a) < tol) {
      break;
    }
  }

  // Print results to console
  printf("\nApproximate root = %.15f\n", c);
  printf("f(root) = %.15e\n", f(c));
  printf("Final absolute error = %.15e\n", fabs(b - a));

  return EXIT_SUCCESS;
}
