/* unit_0882AC18: 0x0882AC18-0x0882AD70 (ULES01213)
 *
 * Bounds (hypothesis): 1 function building a GE command list for a sprite.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Sprite {
    char pad[0xC];
} Sprite;

extern Sprite D_089391A8[];
extern s32 D_08A62C40;
extern void func_0883185C(char *, Sprite *);
extern u32 *func_088597FC(s32);
extern int func_088596C8(s32, u32 *, s32, u8);
extern int func_0885980C(s32, u32 *);

void func_0882AC18(char *arg0, u16 x, u16 y, u16 w, u16 h, s32 idx) {
    u32 *p;
    u32 a;

    func_0883185C(arg0, &D_089391A8[idx]);
    p = func_088597FC(D_08A62C40);
    p[0] = 0;
    p[1] = (x << 16) | 0xFFFF;
    p[2] = y;
    p[3] = (h << 16) | w;
    p[4] = ((x + w) << 16) | 0xFFFF;
    p[5] = (u16)(y + h);
    a = (u32)p;
    p[6] = ((a & 0xFF000000) >> 8) | 0x10000000;
    p[7] = ((a << 8) >> 8) | 0x01000000;
    p[8] = 0x1E000001;
    p[9] = 0x50000001;
    p[10] = 0x12800116;
    p[11] = 0x04060002;
    p[12] = 0x10000000;
    p[13] = 0x08000000;
    func_088596C8(D_08A62C40, p + 6, 8, *(u8 *)(arg0 + 0x534));
    func_0885980C(D_08A62C40, p + 14);
}
