/* unit_088507F4: 0x088507F4-0x08850868 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 b0;
    u8 b1;
    u16 h2;
    u16 h4;
    u16 h6;
    u16 h8;
    u16 hA;
} Entry;

extern u8 func_08850C9C(char *, u16);

s32 func_088507F4(char *arg0, s32 arg1) {
    char *base = arg0 + 0x4A0;
    Entry *e;

    if (func_08850C9C(arg0, arg1) == 0) {
        e = (Entry *)(base + 0xA8) + (u16)arg1;
        e->b0 = 0;
        e->b1 = 0;
        e->h2 = 0;
        e->h4 = 0;
        e->h6 = 0;
        e->h8 = 0;
        e->hA = 0;
        return 1;
    }
    return 0;
}
