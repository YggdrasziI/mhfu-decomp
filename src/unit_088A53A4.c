/* unit_088A53A4: 0x088A53A4-0x088A5454 (ULES01213)
 *
 * Bounds (hypothesis): 4 small functions between code still in assembly.
 */

typedef int s32;

extern char D_089B267C;
extern char D_089B2684;
extern char D_089B268C;
extern char D_089B2694;
extern s32 func_0880EFF8(s32, s32, s32);

s32 func_088A53A4(s32 arg0) {
    return func_0880EFF8(arg0, (s32) &D_089B267C, 4) == 0;
}

s32 func_088A53D0(s32 arg0) {
    return func_0880EFF8(arg0, (s32) &D_089B2684, 4) == 0;
}

s32 func_088A53FC(s32 arg0) {
    return func_0880EFF8(arg0, (s32) &D_089B268C, 4) == 0;
}

s32 func_088A5428(s32 arg0) {
    return func_0880EFF8(arg0, (s32) &D_089B2694, 4) == 0;
}
