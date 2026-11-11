/* unit_088813E0: 0x088813E0-0x08881438 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_08A62D94;
extern int func_08881438(s32, s32);
extern int func_088865B0(s32, s32);

void func_088813E0(s32 arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_08881438(arg0, var_s0);
        func_088865B0(D_08A62D94, var_s0 + 0x12);
        var_s0 += 1;
    } while (var_s0 < 3);
}
