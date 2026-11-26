/* unit_08822BF4: 0x08822BF4-0x08822C58 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern s32 D_08A62C54;
extern u8 *func_0885E834(s32 arg0, u16 arg1);

s32 func_08822BF4(s32 arg0, u16 arg1) {
    u8 *p;
    s32 i;
    s32 n;

    if (arg1 == 0) {
        return 0;
    }
    p = func_0885E834(D_08A62C54, arg1) + 8;
    n = 0;
    i = 0;
    do {
        if (*p == 0) {
            break;
        }
        i++;
        n++;
        p += 2;
    } while (i < 4);
    return (n + 1) >> 1;
}
