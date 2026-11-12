/* unit_088A5ECC: 0x088A5ECC-0x088A5EF8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

s32 func_088A4654(s32, s32, s32);

s32 func_088A5ECC(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 != 0x309) {
        return 0;
    }
    return func_088A4654(arg0, arg1, arg2);
}
