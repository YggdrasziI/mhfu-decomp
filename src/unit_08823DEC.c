/* unit_08823DEC: 0x08823DEC-0x08823E18 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;

extern void func_08823DB0(char *);

void func_08823DEC(char *arg0) {
    func_08823DB0(arg0);
    *(s8 *)(arg0 + 0x1218) = 1;
}
