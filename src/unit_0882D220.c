/* unit_0882D220: 0x0882D220-0x0882D470 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off


typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct { f32 x, y; } V2;
/* Corner offsets {-0.5,-0.5} {-0.5,0.5} {0.5,-0.5} {0.5,0.5}; one 0x20-byte table. */
extern V2 D_08938718[4];

extern void func_0882CF58(char *arg0, s16 *pts, u8 r, u8 g, u8 b, u8 a, s32 idx);

static inline f32 sin_vfpu(f32 x) {
    f32 r;
    f32 *pr = &r;
    f32 *px = &x;
    asm {
        lv.s S000, 0(px)
        vcst.s S001, VFPU_2_PI
        vmul.s S000, S000, S001
        vsin.s S010, S000
        sv.s S010, 0(pr)
    }
    return r;
}

static inline f32 cos_vfpu(f32 x) {
    f32 r;
    f32 *pr = &r;
    f32 *px = &x;
    asm {
        lv.s S000, 0(px)
        vcst.s S001, VFPU_2_PI
        vmul.s S000, S000, S001
        vcos.s S010, S000
        sv.s S010, 0(pr)
    }
    return r;
}

void func_0882D220(char *arg0, u16 x, u16 y, u32 w, u32 h, s32 ang, u8 a, s32 idx) {
    s16 pts[8];
    f32 t;
    f32 s;
    f32 c;
    f32 fw;
    f32 fh;
    f32 vx, vy;
    s32 i;

    t = 9.58738e-5f * -(f32)ang;
    s = sin_vfpu(t);
    c = cos_vfpu(t);
    fw = (f32)w;
    fh = (f32)h;
    for (i = 0; i < 4; i++) {
        vx = fw * D_08938718[i].x;
        vy = fh * D_08938718[i].y;
        pts[i * 2] = x + (s16)(c * vx + s * vy);
        pts[i * 2 + 1] = y + (s16)(-s * vx + c * vy);
    }
    func_0882CF58(arg0, pts, 0xFF, 0xFF, 0xFF, a, idx);
}
