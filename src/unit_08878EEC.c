/* unit_08878EEC: 0x08878EEC-0x08878F08 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;

extern void func_08876574(char *);

void func_08878EEC(char *arg0) {
    *(s16 *)(arg0 + 0xa8) = 0x5a;
    *(s16 *)(arg0 + 0xaa) = 1;
    *(s16 *)(arg0 + 0xac) = 0x384;
    func_08876574(arg0);
}
