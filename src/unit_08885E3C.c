/* unit_08885E3C: 0x08885E3C-0x08885E9C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

extern s32 D_08A62D8C;
extern int func_08882D20(s32, s32, s16);

void func_08885E3C(char *arg0, s16 arg1) {
    func_08882D20(D_08A62D8C, 1, arg1);
    *(s32 *)(arg0 + 0x14) = (s32) (*(s32 *)(arg0 + 0x14) | 2);
    *(s16 *)(arg0 + 0xA) = arg1;
    *(s32 *)(arg0 + 0x14) = (s32) (*(s32 *)(arg0 + 0x14) & ~0x400);
}
