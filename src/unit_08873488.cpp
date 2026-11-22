/* unit_08873488: 0x08873488-0x08873554 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern "C" {

extern char *D_089CC438;
extern char *D_08A631A0;
extern char *func_08857C38(char *arg0);

s32 func_08873488(char *arg0) {
    s32 flags;
    s32 kind;

    if (func_08857C38(D_089CC438) != 0) {
        if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) == 0) {
            if (!(*(u8 *)(D_089CC438 + 0x480) != 0 ||
                  ((flags = *(s32 *)(arg0 + 0x28)) & 0x10) ||
                  (flags & 0x1000000) ||
                  (kind = *(u8 *)(arg0 + 0x77C)) == 7 || kind == 0x32 ||
                  kind == 0x37 || kind == 0x3A)) {
                return 1;
            }
        }
    }
    return 0;
}

}
