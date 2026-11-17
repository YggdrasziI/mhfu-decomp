/* unit_088415D0: 0x088415D0-0x08841908 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly
 * (unit_08841520 and text_08841908).
 *
 * Optimized for speed: the divisions by 7 are multiplications.
 *
 * NonMatching: func_088415D0 89.7 %. The instructions match but the saved
 * registers do not: the original keeps arg0 in $s0 (then x, x + off, the
 * table pointer and i in $s1-$s4), ours in $s4; a few temporaries
 * follow (colour pointer in $t3). Tried: local copy of arg0 (first or last),
 * u8 *, C++, per-loop counters, declaration orders (pairwise search).
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern s16 D_0893ACD0[];
extern u8 D_0893ACE0[][4];

extern s32 func_0882AF70(char *, u16, u16, u16, u16, s32);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_0882C11C(char *, u16, u16, s32, s32, u8, u8, u8, s32, s32);
extern void func_0882BE60(char *, u16, u16, u16, u16, u8, u8, u8, s32);

void func_088415D0(char *arg0) {
    s32 i;
    s32 off;
    s16 x;
    s32 n;
    s32 m;
    u8 id;
    u8 *col;
    float f;
    u16 w;
    u16 h;
    s16 y;
    s32 alpha;

    func_0882AF70(arg0, 0x76, 0x1E, 0x80, 0x10, 0x178);
    func_0882A9DC(arg0, 0x78, 0x1E, 0x179);
    x = 0x96;
    n = *(u8 *)(arg0 + 0x11A5);
    if (n > 0) {
        off = (s16) ((n * -24) / 7) + 0x96;
        for (i = 1; i < 5; i++) {
            id = *(u8 *)(arg0 + 0x11A6 + i);
            if (id == 0) {
                break;
            }
            x += 0x18;
            off += 0x18;
            m = *(u8 *)(arg0 + 0x11A5);
            y = D_0893ACD0[i] + (m * (D_0893ACD0[i - 1] - D_0893ACD0[i])) / 7;
            col = D_0893ACE0[id];
            if (i == 4) {
                alpha = (u8) ((m * 255) / 7);
            } else {
                alpha = 0xFF;
            }
            func_0882C11C(arg0, off, y, 0xC, 0x10, col[0], col[1], col[2], alpha, 0x177);
        }
        n = *(u8 *)(arg0 + 0x11A5);
        if (n > 3) {
            f = 1.0f + 0.3125f * (n - 3);
        } else {
            f = 1.0f;
        }
        w = 12.0f * f;
        h = 16.0f * f;
        x = 0x9C - ((u32) w >> 1);
        y = D_0893ACD0[0] + 8 - ((u32) h >> 1);
        col = D_0893ACE0[*(u8 *)(arg0 + 0x11A6)];
        func_0882BE60(arg0, x, y, w, h, col[0], col[1], col[2], 0x177);
        return;
    }
    for (i = 0; i < 4; i++) {
        id = *(u8 *)(arg0 + 0x11A6 + i);
        if (id == 0) {
            break;
        }
        col = D_0893ACE0[id];
        func_0882BE60(arg0, x, D_0893ACD0[i], 0xC, 0x10, col[0], col[1], col[2], 0x177);
        x += 0x18;
    }
}