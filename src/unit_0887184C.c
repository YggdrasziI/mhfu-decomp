/* unit_0887184C: 0x0887184C-0x088718F4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;

extern char *func_088697D4(char *, u16, s32, s8);

s32 func_0887184C(char *arg0, s32 arg1) {
    u8 id;
    s32 *p;

    id = arg1;
    if (id == 0x12 || id == 0x0A || id == 0x4A) {
        return 1;
    }
    p = (s32 *) func_088697D4(arg0, *(u16 *) (D_089CC438 + 0x70000 - 0x50F2), 0, *(s8 *) (arg0 + 0x82));
    if (p != 0) {
        while (*p != -1) {
            if ((u8) *p == id) {
                return 1;
            }
            p++;
        }
    }
    return 0;
}
