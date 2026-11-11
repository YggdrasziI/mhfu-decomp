/* unit_08888B84: 0x08888B84-0x08888B98 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern void func_08888B98(char *);

void func_08888B84(char *arg0) {
    *(s32 *)(arg0 + 0x80) = 0;
    *(s32 *)(arg0 + 0x88) = 0x3f75be0b;
    func_08888B98(arg0);
}
