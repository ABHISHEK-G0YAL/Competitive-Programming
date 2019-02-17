#include <stdio.h>

int main()
{
  float f = 12.978F;
  double d = -97.4583;

  printf("Floats & Doubles:\n");
  printf("%f, %e, %g\n", f, f, f);
  printf("%.2f, %.2e\n", f, f);
  printf("%.0f, %.0e\n", f, f);
  printf("%7.2f, %7.2e\n", f, f);
  printf("%f, %e, %g\n", d, d, d);
  printf("%.*f\n", 3, d);
  printf("%*.*f\n", 8, 2, d);
  printf("%0*.*f\n", 8, 2, d);

  return 0;
}

