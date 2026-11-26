/* unit_0884FE80: 0x0884FE80-0x0884FEEC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * The table word is read through a volatile pointer: the original loads it
 * before the branches of the signed `% 32`, a plain read sinks after them.
 */

typedef unsigned short u16;
typedef int s32;

extern u16 func_0884FDC4(void *arg0, u16 arg1);

int func_0884FE80(char *arg0, u16 arg1) {
    u16 id = func_0884FDC4(arg0, arg1);
    int w;

    if (id != 0xFFFF) {
        w = ((volatile int *)(arg0 + 0x4428))[(u16)(id >> 5)];
        return (w & (1 << (u16)(id % 32))) != 0;
    }
    return 0;
}
