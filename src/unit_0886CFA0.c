/* unit_0886CFA0: 0x0886CFA0-0x0886D024 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886CFA0 (ULES01213) */

typedef unsigned short u16;
typedef short s16;
typedef int s32;

extern char *func_0886CEA8(char *, s32);
extern u16 func_0886D26C(char *, s32);

u16 func_0886CFA0(char *arg0, s32 arg1) {
    char *e;
    u16 v;

    if ((e = func_0886CEA8(arg0, arg1)) != 0) {
        if (*(u16 *)(e + 0x12) > 0) {
            v = func_0886D26C(arg0, *(u16 *)(e + 0x10) & 0x7FFF);
            if (*(u16 *)(e + 0x12) != 0xFF) {
                *(u16 *)(e + 0x12) = *(u16 *)(e + 0x12) - 1;
            }
            return v;
        } else {
            return 0xFFFE;
        }
    } else {
        return 0;
    }
}
