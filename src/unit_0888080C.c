/* unit_0888080C: 0x0888080C-0x08880864 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern u8 D_089AA224[][4];
extern u8 D_089AA250[];

s32 func_0888080C(s32 arg0, u16 arg1, s32 arg2) {
    s32 ret = 0;
    u8 *entry = D_089AA224[D_089AA250[arg1]];

    switch (arg2) {
    case 0:
        ret = entry[1];
        break;
    case 1:
        ret = entry[2];
        break;
    case 2:
        ret = entry[3];
        break;
    }
    return ret;
}
