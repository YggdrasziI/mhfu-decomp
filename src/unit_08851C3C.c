/* unit_08851C3C: 0x08851C3C-0x08851D3C (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef struct { char b[12]; } E12;

extern s32 func_08851D3C(s32, s32, s32, s32);
extern s32 func_08856D14(s32, s32);

s32 func_08851C3C(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v1;
    char *temp_s0;

    temp_s0 = (char *) (arg0 + (arg1 * 0x8C) + 0x30);
    temp_v1 = func_08856D14(arg0, arg2 & 0xFF) & 0xFF;
    if (temp_v1 < 5) {
        return func_08851D3C(arg0, arg2, (s32) *(u8 *)(temp_s0 + 0x10), (s32) *(u16 *)((E12 *)(temp_s0 + 0x3E))[temp_v1].b);
    }
    return 0;
}

s32 func_08851CC8(s32 arg0, s32 arg1) {
    s32 temp_v1;
    char *temp_s0;

    temp_s0 = (char *) (arg0 + 0x4A0);
    temp_v1 = func_08856D14(arg0, arg1 & 0xFF) & 0xFF;
    if (temp_v1 < 5) {
        return func_08851D3C(arg0, arg1, (s32) *(u8 *)(temp_s0 + 0x13), (s32) *(u16 *)((E12 *)(temp_s0 + 0x2E))[temp_v1].b);
    }
    return 0;
}
