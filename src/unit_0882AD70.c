/* unit_0882AD70: 0x0882AD70-0x0882AF70 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Sets up a sprite texture (func_0883185C on entry idx of
 * D_089391A8), then emits a two-vertex GE sprite list (uv, colour, x/y)
 * through func_088597FC / func_088596C8 / func_0885980C. The last
 * func_088596C8 parameter is s32: as u8 the first call loads the global
 * before the byte argument.
 */

typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    u16 flags;
    u16 id;
} Sprite;

extern s32 D_08A62C40;
extern Sprite D_089391A8[];
extern void func_0883185C(char *, Sprite *);
extern u32 *func_088597FC(s32);
extern int func_088596C8(s32, char *, s32, s32);
extern int func_0885980C(s32, u32 *);

void func_0882AD70(char *arg0, u16 x, u16 y, u16 w, u16 h, u8 r, u8 g, u8 b,
                   u8 a, s32 idx) {
    u32 *p;
    u32 col;

    func_0883185C(arg0, &D_089391A8[idx]);
    p = func_088597FC(D_08A62C40);
    p[0] = 0x10000000;
    p[1] = 0x08000000;
    func_088596C8(D_08A62C40, (char *)p, 2, *(u8 *)(arg0 + 0x534));
    func_0885980C(D_08A62C40, p + 2);
    p = func_088597FC(D_08A62C40);
    col = (a << 24) | ((b << 16) | (r | (g << 8)));
    p[0] = 0;
    p[1] = col;
    p[2] = (y << 16) | x;
    p[3] = 0;
    p[4] = (h << 16) | w;
    p[5] = col;
    p[6] = ((y + h) << 16) | (u16)(x + w);
    p[7] = 0;
    p[8] = (((u32)p & 0xFF000000) >> 8) | 0x10000000;
    p[9] = (((u32)p << 8) >> 8) | 0x01000000;
    p[10] = 0x1E000001;
    p[11] = 0x50000001;
    p[12] = 0x1280011E;
    p[13] = 0x04060002;
    p[14] = 0x10000000;
    p[15] = 0x08000000;
    func_088596C8(D_08A62C40, (char *)(p + 8), 8, *(u8 *)(arg0 + 0x534));
    func_0885980C(D_08A62C40, p + 16);
}
