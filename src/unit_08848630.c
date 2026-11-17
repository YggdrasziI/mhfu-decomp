/* unit_08848630: 0x08848630-0x088487B8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function before code still in assembly.
 *
 * Optimized for speed: divisions by a constant are multiplications.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    char unk0[0x10];
    s32 unk10;
    s32 unk14;
} Unk10;

extern s32 D_089CC438;
extern char *D_08A62CB4;
extern char *D_08A62D8C;

extern s32 func_0884FB6C(s32 arg0);
extern s32 func_08883988(char *, s32, s32, s32, s32, s32, s32, s32, u8);

void func_08848630(char *arg0) {
    Unk10 *m;
    s32 prev;
    s32 n;

    *(s32 *)(arg0 + 0x1194) |= 0x33;
    m = (Unk10 *) (D_08A62CB4 + 0x10);
    prev = m->unk10;
    n = (m->unk14 - 1) / 10 + 1;
    if ((u16) func_0884FB6C(D_089CC438) & 0x80) {
        m->unk10--;
        if (m->unk10 < 0) {
            m->unk10 = n - 1;
        }
    } else if ((u16) func_0884FB6C(D_089CC438) & 0x20) {
        m->unk10++;
        if (n - 1 < m->unk10) {
            m->unk10 = 0;
        }
    }
    if (prev != m->unk10) {
        func_08883988(D_08A62D8C, 0, 0x11, 0, 0, 0, 0, 0, 0);
    }
    if ((u16) func_0884FB6C(D_089CC438) & 0x2000) {
        func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        *(s32 *)(*(char **)(arg0 + 0x530) + 0x614) ^= 0x200;
        *(s32 *)(arg0 + 0x1194) &= ~0x33;
    }
}