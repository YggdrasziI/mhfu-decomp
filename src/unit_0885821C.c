/* unit_0885821C: 0x0885821C-0x08858238 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885821C: copies one float of the table D_0899C994 (index arg2). */

extern float D_0899C994[];

void func_0885821C(float *arg0, void *arg1, int arg2) {
    *arg0 = D_0899C994[arg2];
}
