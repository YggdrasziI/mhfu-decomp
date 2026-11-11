/* unit_08874A94: 0x08874A94-0x08874AB0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;

extern void func_08876574(char *);

void func_08874A94(char *arg0) {
    *(s16 *)(arg0 + 0xa8) = 0x5a;
    *(s16 *)(arg0 + 0xaa) = 1;
    *(s16 *)(arg0 + 0xac) = 0x384;
    func_08876574(arg0);
}
