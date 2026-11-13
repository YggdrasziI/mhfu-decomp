/* unit_088AFFBC: 0x088AFFBC-0x088AFFD0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

void func_088AFFBC(char *arg0, s32 arg1) {
    s32 temp_a1;

    temp_a1 = arg1 & 0xFFFF;
    *(s8 *)(arg0 + 0xC) = (s8) (temp_a1 >> 8);
    *(s8 *)(arg0 + 0xD) = temp_a1;
}
