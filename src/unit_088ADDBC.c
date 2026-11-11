/* unit_088ADDBC: 0x088ADDBC-0x088ADDF4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern int func_088ACC60(s32, s32);

void func_088ADDBC(char *arg0) {
    func_088ACC60(2, 0);
    *(s32 *)(arg0 + 8) = 0;
    *(s8 *)(arg0 + 0xC) = 1;
}
