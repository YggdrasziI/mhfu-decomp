/* unit_08868E54: 0x08868E54-0x08868F0C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08868E54: copies a result text after a dialog (hypothesis: the
 * on-screen keyboard, from the neighbouring code). */

#pragma optimize_for_size off
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

extern char *D_089CC01C;
extern char *D_08A62C64;
extern void func_0884D790(char *, s16, s32);

void func_08868E54(char *arg0) {
    char *p;
    u16 *src;
    u16 *dst;
    s32 n;

    p = arg0 + 0x40;
    func_0884D790(D_089CC01C, 1, 0);
    switch (*(s32 *)(p + 0x2C)) {
    case 0:
        break;
    case 1:
        n = *(s32 *)(p + 0x24);
        src = *(u16 **)(p + 0x20);
        dst = *(u16 **)(p + 0x28);
        while (n != 0) {
            *dst = *src;
            if (*src == 0) {
                break;
            }
            n--;
            dst++;
            src++;
        }
        if (n == 0) {
            dst[-1] = 0;
        }
        break;
    case 2:
        break;
    }
    D_08A62C64[0x17] = 0;
    arg0[0x74] = 0;
}
