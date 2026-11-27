/* unit_088607F8: 0x088607F8-0x08860848 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
extern char *D_089CBBE4;

void func_088607F8(char *arg0) {
    s32 i;
    i = 0;
    do {
        char *e = arg0 + i * 0xA0 + 0x10;
        if (i == 1) {
            char *d = e + 0x90;
            char *s = D_089CBBE4 + 0xCA0;
            asm {
                lv.q C000, 0(s)
                sv.q C000, 0(d)
            }
        }
        i++;
    } while (i < 2);
}
