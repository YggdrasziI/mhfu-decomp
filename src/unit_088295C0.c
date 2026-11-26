/* unit_088295C0: 0x088295C0-0x08829674 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Search the next used slot from the current index.
 */

typedef int s32;
typedef short s16;
typedef unsigned short u16;

extern char *D_089CC438;

extern u16 *func_08856884(char *, s32);

s32 func_088295C0(char *arg0, char *arg1) {
    u16 n;
    u16 i;

    if (*func_08856884(D_089CC438, *(u16 *)(arg1 + 0x648)) != 0) {
        return *(u16 *)(arg1 + 0x648);
    }
    i = *(u16 *)(arg1 + 0x648);
    n = 24;
    do {
        if (*func_08856884(D_089CC438, i) != 0) {
            *(u16 *)(arg1 + 0x648) = i;
            return i;
        }
        i++;
        if (i >= 24) {
            i = 0;
        }
        n--;
    } while ((s32)n > 0);
    return -1;
}
