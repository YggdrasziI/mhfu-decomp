/* unit_08872BFC: 0x08872BFC-0x08872CC0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern char D_089A8040;
extern char D_089A8054;
extern s32 D_089CC438;
extern s32 func_08856DA0(s32, s32);
extern s32 func_0886B8DC(void *);
extern s32 func_08872CC0(s32, s32, s32);

void func_08872BFC(char *arg0, s8 *arg1) {
    s32 var_v0;

    if (!(*(s32 *)(arg0 + 0x28) & 0x4000)) {
        if (func_08856DA0(D_089CC438, 0x1D) == 0) {
            var_v0 = func_08872CC0((s32) arg0, (s32) *arg1, (s32) *(&D_089A8040 + ((s32) (func_0886B8DC(arg0) & 0xFFFF) % 20)));
        } else {
            var_v0 = func_08872CC0((s32) arg0, (s32) *arg1, (s32) *(&D_089A8054 + ((s32) (func_0886B8DC(arg0) & 0xFFFF) % 20)));
        }
        *arg1 = (s8) var_v0;
    }
}
