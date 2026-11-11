/* unit_088ADE7C: 0x088ADE7C-0x088ADEAC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern void func_088ACD38(void);

void func_088ADE7C(char *arg0) {
    func_088ACD38();
    *(s32 *)(arg0 + 8) = 0;
    *(s8 *)(arg0 + 0xC) = 1;
}
