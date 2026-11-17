/* unit_0887D65C: 0x0887D65C-0x0887D884 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly. Its jump
 * table (0x08931910-0x08931934) is linked from this unit.
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern s32 D_08A62C6C;
extern char *D_08A62CB4;
extern s32 D_08A62D8C;
extern s32 D_09A4F0C4;

extern s32 func_0884FB6C(s32);
extern int func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_088854A0(s32, s32, s32);
extern s32 func_088DCEBC(s32, u8);

s32 func_0887D65C(char *arg0) {
    func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
    if (*(s16 *)(arg0 + 0xAA) > 0) {
        *(s16 *)(arg0 + 0xAA) -= 1;
    }
    switch (*(s16 *)(arg0 + 0xA4)) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        if (--*(s16 *)(arg0 + 0xA8) < 0) {
            *(s16 *)(arg0 + 0xA4) += 1;
            *(s16 *)(arg0 + 0xA8) = 0xA;
            if (*(s16 *)(arg0 + 0xA4) < 7) {
                func_08883988(D_08A62D8C, 0, 0x10, 0, 0, 0, 0, 0, 0);
            }
            *(s32 *)(D_08A62CB4 + 0x14) = 0;
            *(s16 *)(arg0 + 0xAE) = 0;
        }
        break;
    case 7:
        if (*(s32 *)(arg0 + 0x14) != *(s32 *)(arg0 + 0x120)) {
            if (*(s16 *)(arg0 + 0xAE) == 0) {
                *(s32 *)(arg0 + 0xC8) = func_08883988(D_08A62D8C, 0, 8, 0, 0, 0, 0, 0, 0);
                *(s16 *)(arg0 + 0xAE) += 1;
            }
            if (D_08A62C6C & 0x4000) {
                *(s32 *)(arg0 + 0x14) = *(s32 *)(arg0 + 0x120);
            } else {
                *(s32 *)(arg0 + 0x14) += 1;
            }
        } else {
            func_088854A0(D_08A62D8C, *(s32 *)(arg0 + 0xC8), 0);
            *(s16 *)(arg0 + 0xA4) += 1;
            func_08883988(D_08A62D8C, 0, 0x19, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 8:
        if (*(s16 *)(arg0 + 0xAA) > 0) {
            if (!((u16) func_0884FB6C((s32) D_089CC438) & 0x4000)) {
                break;
            }
        }
        func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        return 1;
    }
    return 0;
}
