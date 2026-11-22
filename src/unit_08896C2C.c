/* unit_08896C2C: 0x08896C2C-0x08896C58 (ULES01213) */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern u16 D_089B152C[];

extern s32 func_0884FB38(char *, s32);

s32 func_08896C2C(char *arg0, u8 arg1, u8 arg2) {
    return func_0884FB38(D_089CC438, arg2 + D_089B152C[arg1 * 2]);
}
