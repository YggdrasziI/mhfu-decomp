/* unit_0887DD88: 0x0887DD88-0x0887DDD0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

extern s32 func_0887E9AC(s32, s32, s32);

void func_0887DD88(char *arg0) {
    *(s16 *)(arg0 + 0xA4) = 0;
    *(s16 *)(arg0 + 0xA6) = 0;
    *(s16 *)(arg0 + 0xAA) = 0xE10;
    *(s16 *)(arg0 + 0xA8) = 0xA;
    *(s32 *)(arg0 + 0x14) = func_0887E9AC((s32) arg0, *(s32 *)(arg0 + 0x120), 0);
}
