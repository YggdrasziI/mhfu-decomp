/* unit_088A10E0: 0x088A10E0-0x088A10F8 (ULES01213)
 *
 * Bounds (hypothesis): 3 small functions between code still in assembly.
 */

extern void func_088A13AC(char *);
extern void func_088A140C(char *);
extern void func_088A146C(char *);

void func_088A10E0(char *arg0) {
    func_088A13AC(arg0 + 0x8);
}

void func_088A10E8(char *arg0) {
    func_088A140C(arg0 + 0x8);
}

void func_088A10F0(char *arg0) {
    func_088A146C(arg0 + 0x8);
}
