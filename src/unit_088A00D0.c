/* unit_088A00D0: 0x088A00D0-0x088A014C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;

extern s32 *func_0889F4BC(void);
extern s32 *func_0889F4F0(void);
extern void func_0889F5D8(s32 *);

s32 func_088A00D0(void) {
    s32 *p;
    s32 *q;

    p = func_0889F4BC();
    while (p != 0) {
        if (*p == 7) {
            *p = 0;
            q = p;
            p = func_0889F4F0();
            func_0889F5D8(q);
        } else {
            p = func_0889F4F0();
        }
    }
    return 0;
}
