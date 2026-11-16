/* unit_08885E9C: 0x08885E9C-0x08885F50 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern s32 D_08A62D8C;
extern int func_08882C24(s32, s32, s32, s32);
extern void func_08882F58(s32, s32);

void func_08885E9C(char *arg0) {
    s32 temp_a0;

    if (*(u16 *)(arg0 + 0xA) == 0x18E9) {
        func_08882F58(D_08A62D8C, 1);
    }
    temp_a0 = *(s32 *)(arg0 + 0x14);
    if (temp_a0 & 0x402) {
        *(s32 *)(arg0 + 0x14) = (s32) (temp_a0 & ~0x402);
        if (*(s32 *)(arg0 + 4) >= 4) {
            func_08882C24(D_08A62D8C, 0, 0xF, 0x7F);
        } else {
            func_08882C24(D_08A62D8C, 0, 0xF, *(s32 *)(arg0 + 0x10));
        }
    }
    *(s32 *)(arg0 + 0x14) = (s32) (*(s32 *)(arg0 + 0x14) & ~0x100);
    *(s16 *)(arg0 + 0x2A) = 0;
}
