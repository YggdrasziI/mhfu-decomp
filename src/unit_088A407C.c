/* unit_088A407C: 0x088A407C-0x088A412C (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;

s32 func_0889786C();
extern s32 D_09A0E390;

s32 func_088A407C(void) {
    if ((D_09A0E390 == 0) && (func_0889786C() != 0)) {
        return 0x80000014;
    }
    D_09A0E390 += 1;
    return 0;
}

s32 func_08897850();
extern s32 D_09A0E394;

s32 func_088A40D4(void) {
    if ((D_09A0E394 == 0) && (func_08897850() != 0)) {
        return 0x80000016;
    }
    D_09A0E394 += 1;
    return 0;
}
