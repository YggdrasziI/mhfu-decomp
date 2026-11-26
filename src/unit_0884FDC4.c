/* unit_0884FDC4: 0x0884FDC4-0x0884FE10 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
typedef unsigned short u16;

extern u16 D_0899C0A8[];

u16 func_0884FDC4(void *arg0, u16 arg1) {
    u16 i;
    u16 *p;

    i = 0;
    for (p = D_0899C0A8; *p != 0xEA60; i++, p++) {
        if (*p == arg1) {
            return i;
        }
    }
    return 0xFFFF;
}
