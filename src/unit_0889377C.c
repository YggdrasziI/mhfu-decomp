/* unit_0889377C: 0x0889377C-0x08893894 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

extern s32 func_08894874(s32, s32);
extern void func_08893894(s32, s32, s32, s32);
extern s32 func_088952A4(s32, s32, s32, s32);

void func_0889377C(s32 arg0, s32 arg1) {
    s32 g;
    u16 *p;
    s32 c;

    p = *(u16 **)(arg1 + 8);
    *(s16 *)(arg0 + 0x126) = *(s16 *)(arg1 + 0);
    *(s16 *)(arg0 + 0x128) = *(s16 *)(arg1 + 2);
    *(s16 *)(arg0 + 0x12A) = *(s16 *)(arg0 + 0x124);
    for (;;) {
        c = *p++;
        if (c == 0) {
            break;
        }
        if (c == 0xA) {
            *(s16 *)(arg0 + 0x126) = *(s16 *)(arg1 + 0);
            *(s16 *)(arg0 + 0x128) += *(u8 *)(arg1 + 7);
            continue;
        }
        g = func_08894874(arg0, c);
        if (c != 0x20 && c != 0xA0 && c != 0x2002 && c != 0x2003 && c != 0x3000) {
            func_08893894(arg0, c, g, arg1);
        }
        *(s16 *)(arg0 + 0x126) += (u8)func_088952A4(arg0, c, g, *(u8 *)(arg1 + 4));
    }
}
