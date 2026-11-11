/* unit_088DAE98: 0x088DAE98-0x088DAEB0 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;

s32 func_088DAE98(char *arg0, s32 arg1) {
    return (*(s32 *)(arg0 + 0x6CC) & arg1) != 0;
}

s32 func_088DAEA8(char *arg0) {
    return *(s32 *)(arg0 + 0x6CC);
}
