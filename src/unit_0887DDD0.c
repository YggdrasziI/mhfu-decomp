/* unit_0887DDD0: 0x0887DDD0-0x0887E030 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern s32 D_08A62D8C;
extern s32 D_08A62C6C;
extern char *D_08A62CB4;

extern s32 func_088DCEBC(s32, u8);
extern int func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_0884FC0C(char *, s32);
extern void func_088854A0(s32, s32, s32);
extern u16 func_0884FB6C(char *p);

s32 func_0887DDD0(char *arg0) {
    func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
    if (*(s16 *)(arg0 + 0xAA) > 0) {
        *(s16 *)(arg0 + 0xAA) -= 1;
    }
    switch (*(s16 *)(arg0 + 0xA4)) {
    case 0:
    case 1:
    case 2:
        *(s16 *)(arg0 + 0xA8) -= 1;
        if (*(s16 *)(arg0 + 0xA8) >= 0) {
            break;
        }
        *(s16 *)(arg0 + 0xA4) += 1;
        *(s16 *)(arg0 + 0xA8) = 10;
        if (*(s16 *)(arg0 + 0xA4) < 3) {
            func_08883988(D_08A62D8C, 0, 0x10, 0, 0, 0, 0, 0, 0);
        }
        *(s16 *)(arg0 + 0xAE) = 0;
        break;
    case 3:
        if (*(s32 *)(arg0 + 0x14) != 0) {
            if (*(s16 *)(arg0 + 0xAE) == 0) {
                *(s32 *)(arg0 + 0xC8) = func_08883988(D_08A62D8C, 0, 8, 0, 0, 0, 0, 0, 0);
                *(s16 *)(arg0 + 0xAE) += 1;
            }
            if (D_08A62C6C & 0x4000) {
                func_0884FC0C(D_089CC438, *(s32 *)(D_08A62CB4 + 0x14));
                *(s32 *)(D_08A62CB4 + 0x14) = 0;
            } else {
                func_0884FC0C(D_089CC438, 1);
                *(s32 *)(D_08A62CB4 + 0x14) -= 1;
            }
        } else {
            func_088854A0(D_08A62D8C, *(s32 *)(arg0 + 0xC8), 0);
            *(s16 *)(arg0 + 0xA4) += 1;
            func_08883988(D_08A62D8C, 0, 0x19, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 4:
        if (*(s16 *)(arg0 + 0xAA) <= 0 || (func_0884FB6C(D_089CC438) & 0x4000)) {
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
            return 1;
        }
        break;
    }
    return 0;
}
