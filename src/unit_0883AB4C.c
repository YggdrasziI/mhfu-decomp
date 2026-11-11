/* unit_0883AB4C: 0x0883AB4C-0x0883AB8C (ULES01213)
 *
 * Bounds (hypothesis): 1 forwarder with fixed arguments, between unrelated code.
 */

typedef signed char s8;

extern void func_0883488C(void *p, int a);
extern void func_0883A758(void *p, int a, int b, int c, int d);

void func_0883AB4C(char *p) {
    func_0883488C(p, 1);
    func_0883A758(p, 0xF0, 0x28, *(s8 *)(p + 0x57F), 1);
}
