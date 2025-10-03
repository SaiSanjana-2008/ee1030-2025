#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    // Point through which line passes
    double Px = -1, Py = 3, Pz = -2;

    // Direction vectors of given lines
    double d1x = 1, d1y = 2, d1z = 3;
    double d2x = -3, d2y = 2, d2z = 5;

    // Solve for direction vector u of required line
    // Equations: u1 + 2*u2 + 3*u3 = 0
    //            -3*u1 + 2*u2 + 5*u3 = 0
    // Solve manually, choose u3 = 4
    double u3 = 4;
    double u2 = -7.0/4.0 * u3;
    double u1 = 0.5 * u3;

    // Foot of perpendicular from origin: t = -(P . u) / (u . u)
    double dot_Pu = Px*u1 + Py*u2 + Pz*u3;
    double dot_UU = u1*u1 + u2*u2 + u3*u3;
    double t = -dot_Pu / dot_UU;

    // Foot of perpendicular coordinates
    double Qx = Px + t*u1;
    double Qy = Py + t*u2;
    double Qz = Pz + t*u3;

    // Distance from origin
    double D = sqrt(Qx*Qx + Qy*Qy + Qz*Qz);

    // Print results
    printf("Required line passes through P(-1,3,-2)\n");
    printf("Direction vector u = (%.0f, %.0f, %.0f)\n", u1, u2, u3);
    printf("Vector equation: r = P + t*u = (%.0f, %.0f, %.0f) + t*(%.0f, %.0f, %.0f)\n",
           Px, Py, Pz, u1, u2, u3);
    printf("Foot of perpendicular from origin: Q = (%.2f, %.2f, %.2f)\n", Qx, Qy, Qz);
    printf("Distance from origin: D = %.5f\n", D);

    // Write results to file
    FILE *file = fopen("values.dat", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(file, "Px\tPy\tPz\tu1\tu2\tu3\tQx\tQy\tQz\tD\n");
    fprintf(file, "%.0f\t%.0f\t%.0f\t%.0f\t%.0f\t%.0f\t%.2f\t%.2f\t%.2f\t%.5f\n",
            Px, Py, Pz, u1, u2, u3, Qx, Qy, Qz, D);

    fclose(file);
    printf("Results written to values.dat\n");

    return 0;
}

