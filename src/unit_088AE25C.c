/* unit_088AE25C: 0x088AE25C-0x088AE274 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

void func_088AE25C(char *arg0) {
    *(s8 *)(arg0 + 0x21) = 1;
    *(s8 *)(arg0 + 0x22) = 0;
    *(s32 *)(arg0 + 0xC) = 0x5A;
}
