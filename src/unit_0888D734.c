/* unit_0888D734: 0x0888D734-0x0888D888 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;

typedef struct {
    u8 pad0[0x35];
    u8 unk35;
    s16 unk36;
} Sub0xA0;

extern char *D_089CBBE4;
extern char *D_09D1A060;
extern float func_09C3DA00(char *, u8 *);

s32 func_0888D734(char *arg0) {
    u8 *p;
    Sub0xA0 *b;
    u8 flags;
    float r;

    b = (Sub0xA0 *)(arg0 + 0xA0);
    p = *(u8 **)(D_089CBBE4 + 0xA84);
    if (p[0x298] == 2) {
        b->unk35 = 0;
        return 0;
    }
    flags = 0;
    if (p[0x280] == 2) {
        flags = 1;
        if (*(float *)(p + 0x204) < *(float *)(p + 0x214) - 10.0f) {
            flags = 2;
            r = func_09C3DA00(D_09D1A060, p + 0x200);
            if (*(float *)(p + 0x204) > 300.0f + r) {
                flags = 3;
            }
        }
    }
    switch (b->unk35) {
    case 0:
        if (flags < 3) {
            b->unk36 = 4;
            break;
        }
        if (--b->unk36 > 0) {
            break;
        }
        b->unk35++;
    case 1:
        if (flags & 1) {
            b->unk36 = 15;
            return 1;
        }
        if (--b->unk36 > 0) {
            return 1;
        }
        b->unk35 = 0;
    }
    return 0;
}
