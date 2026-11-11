/* unit_088689F4: 0x088689F4-0x088689FC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;

extern void func_088689FC(char *);

void func_088689F4(char *arg0) {
    *(s8 *)(arg0 + 0x74) = 0;
    func_088689FC(arg0);
}
