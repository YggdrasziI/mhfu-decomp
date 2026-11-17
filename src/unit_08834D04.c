/* unit_08834D04: 0x08834D04-0x08834D3C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly
 * (text_08834B0C and text_08834D3C).
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern s32 func_0884FB6C(s32 arg0);

s32 func_08834D04(char *arg0) {
    u8 *p = (u8 *)(arg0 + 0x1118);

    if (p[5] == 0) {
        return func_0884FB6C((s32) D_089CC438);
    }
    return *(u16 *)(p + 6);
}
