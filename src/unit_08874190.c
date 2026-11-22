/* unit_08874190: 0x08874190-0x088741D4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef short s16;
typedef int s32;

extern s16 D_089A8564[];

s32 func_08874190(s32 arg0, s16 arg1) {
    s16 *p = D_089A8564;

    while (*p != -1) {
        if (*p == arg1) {
            return 1;
        }
        p++;
    }
    return 0;
}
