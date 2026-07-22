/**
 * bisection_analysis.c
 * Implementation of the bisection method.
 * Stores the complete iteration history for convergence analysis.
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
  const double a0 = 1; // Lower bound of bracketing interval
  const double b0 = 2; // Upper bound of bracketing interval
  
  double fa0 = f(a0); // Function value at lower bound
  double fb0 = f(b0); // Function value at upper bound
                     
  /* Verify that the interval brackets the root */
  if (fa0 * fb0 > 0) {
    fprintf(stderr, 
        "Error: interval [%.6f, %.6f] does not bracket a root.\n",
        a0, b0);
    return EXIT_FAILURE;
  }
                      
  /* Required number of iterations */
  int iter_req = ceil((log(fabs(b0 - a0)) - log(tol))/log(2));
  printf("Required number of iterations for specified tolerance %g: %d\n", tol, iter_req);

  /* Allocate storage for iteration history */
  //int *iter = malloc((iter_req + 1) * sizeof(int));
  //double *a = malloc((iter_req + 1) * sizeof(double));
  //double *b = malloc((iter_req + 1) * sizeof(double));
  //double *c = malloc((iter_req + 1) * sizeof(double));
  //double *fa = malloc((iter_req + 1) * sizeof(double));
  //double *fb = malloc((iter_req + 1) * sizeof(double));
  //double *fc = malloc((iter_req + 1) * sizeof(double));
  //double *width = malloc((iter_req + 1) * sizeof(double));

  //if (!iter || !a || !b || !c || 
  //    !fa || !fb || !fc || !width ) {
  //  fprintf(stderr, "Memory allocation failed.\n");
  //  free(iter);
  //  free(a);
  //  free(b);
  //  free(c);
  //  free(fa);
  //  free(fb);
  //  free(fc);
  //  free(width);
  //  return EXIT_FAILURE;
  //}
  int iter[iter_req + 1];
  double a[iter_req + 1];
  double b[iter_req + 1];
  double c[iter_req + 1];
  double fa[iter_req + 1];
  double fb[iter_req + 1];
  double fc[iter_req + 1];
  double width[iter_req + 1];
  
  // Initial iteration
  iter[0] = 0;
  a[0] = a0;
  b[0] = b0;
  c[0] = (a0 + b0)/2;
  
  fa[0] = f(a[0]);
  fb[0] = f(b[0]);
  fc[0] = f(c[0]);

  width[0] = fabs(b[0] - a[0]);

  /* Bisection method implementation */
  int final_iter = iter_req;
  for (int k = 0; k < iter_req; k++) {
    if (fabs(fc[k]) < 1e-15 || width[k] < tol) {
      final_iter = k;
      break;
    }

    iter[k+1] = k + 1;

    if (fa[k]*fc[k] < 0) {
      a[k+1] = a[k];
      b[k+1] = c[k];
    } else {
      a[k+1] = c[k];
      b[k+1] = b[k];
    }
    c[k+1] = (a[k+1] + b[k+1])/2;

    fa[k+1] = f(a[k+1]);
    fb[k+1] = f(b[k+1]);
    fc[k+1] = f(c[k+1]);
    width[k+1] = fabs(b[k+1] - a[k+1]);
    final_iter = k+1;
  } 

  /* Print results to console */
  for (int k = 0; k < iter_req; k++) {
    printf("%3d %13.8f %13.8f %13.8f | %14.6e %14.6e\n", 
        iter[k], a[k], c[k], b[k], fc[k], width[k]);
  }
  printf("\nApproximate root = %.15f\n", c[final_iter]);
  printf("f(root) = %.15e\n", f(c[final_iter]));
  printf("Final absolute error = %.15e\n", fabs(width[final_iter]));

  /* Free memory */
  //free(iter);
  //free(a);
  //free(b);
  //free(c);
  //free(fa);
  //free(fb);
  //free(fc);
  //free(width);

  return EXIT_SUCCESS;

  return 0;
}
