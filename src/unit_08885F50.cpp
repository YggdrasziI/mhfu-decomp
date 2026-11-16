/* unit_08885F50: 0x08885F50-0x08886048 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef unsigned short u16;
typedef int s32;

extern "C" {

extern char *D_089CC438;
extern s32 D_08A62D8C;
extern s32 func_08882B4C(s32, s32);
extern int func_08882C24(s32, s32, s32, s32);
extern int func_08882F58(s32, s32);
extern int func_09A63A98(char *);

void func_08885F50(char *arg0) {
    s32 temp_v1;

    temp_v1 = *(s32 *)arg0;
    if (temp_v1 > 0) {
        *(s32 *)arg0 = (s32) (temp_v1 - 1);
    }
    if (((*(s32 *)(arg0 + 0x14) & 0x102) == 2) && (func_08882B4C(D_08A62D8C, 1) >= 5)) {
        func_08882F58(D_08A62D8C, 1);
        *(u16 *)(arg0 + 0xA) = 0xFFFF;
        if (*(s32 *)(arg0 + 4) >= 4) {
            func_08882C24(D_08A62D8C, 0, 0xF, 0x7F);
        } else {
            func_08882C24(D_08A62D8C, 0, 0xF, *(s32 *)(arg0 + 0x10));
        }
        *(s32 *)(arg0 + 0x14) = (s32) (*(s32 *)(arg0 + 0x14) & ~2);
    }
    if (((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 1) == 0)) {
        func_09A63A98(arg0);
    }
}

}
