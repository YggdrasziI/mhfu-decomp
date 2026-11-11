/* unit_088ADD80: 0x088ADD80-0x088ADDBC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern char D_089B2840;
extern int func_088ACC60(s32, char *);

void func_088ADD80(char *arg0) {
    func_088ACC60(1, &D_089B2840);
    *(s32 *)(arg0 + 8) = 0;
    *(s8 *)(arg0 + 0xC) = 1;
}
