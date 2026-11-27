/* unit_088160F0: 0x088160F0-0x08816264 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088160F0: six plane tests of a transformed point (purpose is a hypothesis). */

typedef unsigned char u8;
typedef int s32;
typedef float f32;

#define F(p, o) (*(f32 *)((p) + (o)))

s32 func_088160F0(char *arg0, char *arg1, f32 fparg0, f32 fparg1) {
    f32 y;
    f32 x;
    f32 z;
    s32 var_v0;

    if (*(u8 *)(arg0 + 0xAAA) == 0) {
        return 1;
    }
    y = F(arg0, 0xBB8) + ((F(arg0, 0xBA8) * F(arg1, 8)) + ((F(arg0, 0xB88) * F(arg1, 0)) + (F(arg0, 0xB98) * F(arg1, 4))));
    if ((y - fparg0) > F(arg0, 0xD90)) {
        return 0;
    }
    if ((y + fparg0) < fparg1) {
        return 0;
    }
    x = F(arg0, 0xBB0) + ((F(arg0, 0xBA0) * F(arg1, 8)) + ((F(arg0, 0xB80) * F(arg1, 0)) + (F(arg0, 0xB90) * F(arg1, 4))));
    if ((x * F(arg0, 0xD50)) + (y * F(arg0, 0xD58)) > fparg0) {
        return 0;
    }
    if ((x * F(arg0, 0xD60)) + (y * F(arg0, 0xD68)) > fparg0) {
        return 0;
    }
    z = F(arg0, 0xBB4) + ((F(arg0, 0xBA4) * F(arg1, 8)) + ((F(arg0, 0xB84) * F(arg1, 0)) + (F(arg0, 0xB94) * F(arg1, 4))));
    if ((z * F(arg0, 0xD74)) + (y * F(arg0, 0xD78)) > fparg0) {
        return 0;
    }
    var_v0 = 1;
    if (!((z * F(arg0, 0xD84)) + (y * F(arg0, 0xD88)) > fparg0)) {
        var_v0 = 0;
    }
    return var_v0 ^ 1;
}
