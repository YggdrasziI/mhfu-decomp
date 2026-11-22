/* unit_08882A74: 0x08882A74-0x08882AEC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_089AC3F8;
extern s32 D_089AC3FC;
extern s32 D_089AC400;
extern s32 D_089AC244;
extern s32 D_089AC248;
extern s32 D_089AC24C;

extern void func_0888291C(char *, s32);

void func_08882A74(char *arg0, s32 arg1, s32 arg2) {
    *(s32 *)(arg0 + 0x562434) = 0;
    D_089AC244 = D_089AC3F8;
    D_089AC248 = D_089AC3FC;
    D_089AC24C = D_089AC400;
    if (*(s32 *)(arg0 + 0x308BC0) != arg1) {
        *(s32 *)(arg0 + 0x308BC0) = arg1;
        func_0888291C(arg0, arg2);
    }
}
