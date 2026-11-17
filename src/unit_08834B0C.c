/* unit_08834B0C: 0x08834B0C-0x08834D04 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_0883488C and unit_08834D04.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern s32 D_08A62D8C;
extern void func_0881BF80(char *, u8 *, s32, s32);
extern s32 func_08834D3C(char *, u8);
extern u16 func_08835098(char *arg0, u8 arg1, s32 arg2);
extern void func_0883448C(char *arg0);
extern int func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);

s32 func_08834B0C(char *arg0, s32 arg1) {
    u8 *p = (u8 *)(arg0 + 0x1118);
    u16 keys;
    u16 res;

    if (p[5] == 0) {
        return 1;
    }
    *(u16 *)(p + 6) = 0;
    switch (p[0]) {
    case 0:
        func_0881BF80(arg0, p + 4, arg1, 0xE);
        *(u16 *)(arg0 + 0x5FC) = p[4];
        keys = arg1;
        if (keys & 0x4000) {
            if (func_08834D3C(arg0, p[4]) == 0) {
                p[0]++;
                *(s32 *)(arg0 + 0x121C) = 0;
                func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
            } else {
                func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
            }
        } else if (keys & 0x2008) {
            p[5] = 0;
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            return 1;
        }
        break;
    case 1:
        res = func_08835098(arg0, p[4], arg1);
        if (*(s32 *)(arg0 + 0x121C) != 0) {
            break;
        }
        if (res & 8) {
            p[5] = 0;
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            return 1;
        }
        if (res & 0x2000) {
            func_0883448C(arg0);
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        }
        break;
    }
    return 0;
}
