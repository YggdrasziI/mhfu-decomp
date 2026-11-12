/* unit_088A59C4: 0x088A59C4-0x088A59FC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 func_088A53A4(s32);

s32 func_088A59C4(s32 arg0) {
    if (func_088A53A4(arg0) != 1) {
        return 0x80000006;
    }
    return *(s32 *)(arg0 + 0x10);
}
