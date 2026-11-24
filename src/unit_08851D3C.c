/* unit_08851D3C: 0x08851D3C-0x08851DBC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern s32 func_08856D14(char *, u8);
extern u16 *func_0885CB68(s32, u8, s16);
extern s32 D_08A62C54;

s32 func_08851D3C(char *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 k;
    s32 v;

    k = (u8)func_08856D14(arg0, (u8)arg1);
    if (k < 5) {
        if (arg2 == 0) {
            v = func_0885CB68(D_08A62C54, k, (s16)arg3)[0];
        } else {
            v = func_0885CB68(D_08A62C54, k, (s16)arg3)[1];
        }
        return v != 0;
    }
    return 0;
}
