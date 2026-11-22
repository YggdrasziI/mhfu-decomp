/* unit_0888C794: 0x0888C794-0x0888C9F8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;

void func_0888C794(char *arg0, float *u, float *a, float *b, float *c, float *r, s32 n) {
    float gam[64];
    float bet;
    s32 j;
    s32 i;

    bet = b[0];
    if (bet != 0.0f) {
        bet = 1.0f / bet;
    }
    u[0] = r[0] * bet;
    for (j = 1; j < n; j++) {
        gam[j - 1] = c[j - 1] * bet;
        bet = b[j] - a[j] * gam[j - 1];
        if (bet != 0.0f) {
            bet = 1.0f / bet;
        }
        u[j] = bet * (r[j] - a[j] * u[j - 1]);
    }
    for (i = n - 2; i >= 0; i--) {
        u[i] -= gam[i] * u[i + 1];
    }
}
