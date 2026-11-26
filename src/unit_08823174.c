/* unit_08823174: 0x08823174-0x088232A0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

extern char *D_08A62C54;
extern u8 D_08938600[];
extern char *func_0885CA50(char *, char *);
extern u8 func_0885CD18(char *arg0, u8 arg1, u16 arg2);
extern s32 func_088DA398(s32, s32);

void func_08823174(s32 arg0, s32 arg1, u8 *arg2, s16 *arg3, s16 *arg4, s16 *arg5) {
    char *e;

    *arg4 = -1;
    if (arg2[1] == 5) {
        e = func_0885CA50(D_08A62C54, (char *)arg2);
        *arg5 = ((u8 *)e)[0xC];
        if (((u8 *)e)[0xE] != 0) {
            *arg4 = ((u8 *)e)[0xE] - 1;
        } else if (((u8 *)e)[0x10] != 0) {
            *arg4 = ((u8 *)e)[0x10] + 4;
        }
    } else {
        e = func_0885CA50(D_08A62C54, (char *)arg2);
        *arg5 = ((u8 *)e)[0xA];
        if (func_0885CD18(D_08A62C54, arg2[1], *(u16 *)(arg2 + 2)) == 10) {
            if (((u8 *)e)[0x11] != 0) {
                *arg4 = ((u8 *)e)[0x11] - 1;
            }
        }
    }
    if (*arg4 >= 0) {
        *arg3 = func_088DA398(arg1, D_08938600[*arg4]);
    }
}
