/* unit_088C8E5C: 0x088C8E5C-0x088C9060 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between other units.
 */

/* func_088C8E5C (ULES01213) */

typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct Anim {
    u16 flags;
    u16 u;
    u16 v;
    u16 pad;
    s32 pad2[2];
    f32 x;
    f32 y;
    f32 z;
} Anim;

extern s32 *D_089CC000;
extern void func_0886171C(char *, s32, char *, s32);
extern s32 func_08862354(char *, char *);

void func_088C8E5C(char *arg0, char *arg1, Anim *arg2, s32 arg3) {
    f32 su;
    f32 sv;
    f32 m[4][4] __attribute__((aligned(16)));
    f32 *p;
    f32 x, y, z;

    if (arg2->u != 0) {
        su = (f32)(*(u16 *)(arg0 + 0x1C0) % arg2->u) / (f32)(u32)arg2->u;
        if (arg2->flags & 8) {
            su = 1.0f - su;
        }
        *D_089CC000 = (*(u32 *)&su >> 8) | 0x4A000000;
        D_089CC000++;
    }
    if (arg2->v != 0) {
        sv = (f32)(*(u16 *)(arg0 + 0x1C0) % arg2->v) / (f32)(u32)arg2->v;
        if (arg2->flags & 8) {
            sv = 1.0f - sv;
        }
        *D_089CC000 = (*(u32 *)&sv >> 8) | 0x4B000000;
        D_089CC000++;
    }
    z = arg2->z;
    y = arg2->y;
    x = arg2->x;
    p = m[0];
    asm {
        vmidt.q E000
        sv.q C000, 0(p)
        sv.q C010, 0x10(p)
        sv.q C020, 0x20(p)
        sv.q C030, 0x30(p)
    }
    m[3][0] = x;
    m[3][1] = y;
    m[3][2] = z;
    func_08862354((char *)m, arg1 + 0x10);
    func_0886171C(arg1, 0, arg0 + 0x70, arg3);
    func_08862354(arg0 + 0x10, arg1 + 0x10);
    *D_089CC000 = 0x4A000000;
    D_089CC000++;
    *D_089CC000 = 0x4B000000;
    D_089CC000++;
}
