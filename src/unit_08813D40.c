/* unit_08813D40: 0x08813D40-0x08813D9C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern char *D_089CC438;

extern void func_08813574(void *o, s32 a, s32 b);

void func_08813D40(void *arg0) {
    s32 n;

    switch (*(u16 *)(D_089CC438 + 0x6AF0E)) {
    case 0xC:
        n = 3;
        break;
    case 0x19:
        n = 4;
        break;
    case 0xB0:
        n = 5;
        break;
    default:
        return;
    }
    func_08813574(arg0, n, 0);
}
