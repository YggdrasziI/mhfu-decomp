/* unit_0887C708: 0x0887C708-0x0887C724 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;

extern void func_08876574(char *);

void func_0887C708(char *arg0) {
    *(s16 *)(arg0 + 0xa4) = 0;
    *(s16 *)(arg0 + 0xa6) = 0;
    *(s16 *)(arg0 + 0xaa) = 0x384;
    *(s16 *)(arg0 + 0xa8) = 0xa;
    func_08876574(arg0);
}
