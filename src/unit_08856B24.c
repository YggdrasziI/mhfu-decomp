/* unit_08856B24: 0x08856B24-0x08856BC8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned short u16;
typedef unsigned char u8;

extern char *D_08A631A0;
extern u8 func_0884FB38(char *, s32);
extern void func_0884FAC4(char *, s32);
extern u16 func_088900C4(char *, s32);

void func_08856B24(char *arg0) {
    if ((s32) ((*(s32 *)(arg0 + 0x6ADF8) & 0x1000) != 0) == 1) {
        if (func_0884FB38(arg0, 0x22) == 0) {
            func_0884FAC4(arg0, 0x22);
            arg0[0x44BD] = 0;
        } else {
            arg0[0x44BD] = func_088900C4(D_08A631A0, 1) % 5;
        }
    } else {
        arg0[0x44BD] = (func_088900C4(D_08A631A0, 1) & 3) + 1;
    }
}
