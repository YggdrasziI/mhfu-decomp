/* unit_08851DBC: 0x08851DBC-0x08851E54 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;

extern char *D_08A62C54;

extern s32 func_08851C3C(char *, s32, s32);
extern s32 func_08856D14(char *, u8);
extern u8 *func_0885CB68(char *, s32, s16);

u8 func_08851DBC(char *arg0, s32 arg1, s32 arg2) {
    char *p = arg0 + arg1 * 0x8C + 0x30;
    u8 idx;

    if ((u8)func_08851C3C(arg0, arg1, arg2) == 1) {
        idx = func_08856D14(arg0, (u8)arg2);
        return func_0885CB68(D_08A62C54, idx, *(s16 *)((char *)(idx * 12) + (s32)p + 0x3E))[0x13];
    }
    return 0;
}
