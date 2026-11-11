/* unit_088DCF3C: 0x088DCF3C-0x088DCF70 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

extern char D_089BAE28;
extern void func_088CE05C(char **);

char **func_088DCF3C(char **arg0) {
    func_088CE05C(arg0);
    *arg0 = &D_089BAE28;
    return arg0;
}
