/* unit_088E30B0: 0x088E30B0-0x088E30C4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

extern char func_088E30C4;

void func_088E30B0(char *arg0) {
    **(char ***)(arg0 + 0x190) = &func_088E30C4;
}
