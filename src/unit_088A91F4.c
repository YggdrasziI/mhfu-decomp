/* unit_088A91F4: 0x088A91F4-0x088A920C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

s32 func_088A91F4(char *arg0) {
    *(s32 *)(arg0 + 0x9C) = 0;
    *(s32 *)(arg0 + 0xA0) = 0;
    *(s32 *)(arg0 + 0xA4) = 0;
    *(s32 *)(arg0 + 0xA8) = 0;
    return 0;
}
