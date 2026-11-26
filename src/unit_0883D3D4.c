/* unit_0883D3D4: 0x0883D3D4-0x0883D40C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 *D_09B22D70;

/* The argument is unused; callers pass one (src/unit_0883D0EC.c). */
s32 func_0883D3D4(char *arg0) {
    s32 x = *D_09B22D70;

    if (x == 0 || x == 0x16 || x == 8) {
        return 1;
    }
    return 0;
}
