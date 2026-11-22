/* unit_0888E350: 0x0888E350-0x0888E3DC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;

extern char *D_089CBBE4;

extern void func_0888E324(char *, s32);

void func_0888E350(char *arg0, char *arg1) {
    char *g = D_089CBBE4;
    s32 v;
    u8 *p;
    u8 key;
    s32 i;

    if (*(u8 *)(g + 0xA8B) == 0) {
        return;
    }
    v = 0xF;
    if (arg1 != 0) {
        p = *(u8 **)(arg1 + 0x1C);
        if (p != 0) {
            key = *(u8 *)(g + 0xA94);
            i = 0x10;
            do {
                if (p[0] == key) {
                    v = p[1];
                    break;
                }
                p += 2;
            } while (--i != 0);
        }
    }
    switch (v) {
    default:
        func_0888E324(arg0, v);
        break;
    case 0:
    case 1:
        arg0[0x9C] = 0;
        break;
    }
}
