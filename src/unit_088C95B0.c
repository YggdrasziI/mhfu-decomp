/* unit_088C95B0: 0x088C95B0-0x088C96F8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between other units.
 */

/* func_088C95B0: VFPU identity matrix (asm block) with a translation. */

typedef unsigned char u8;
typedef int s32;

typedef struct Box {
    float pos[4];
    float min[4];
    float max[4];
} Box;

typedef struct Ent {
    char pad0[0x200];
    float pos[3];
} Ent;

extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern Ent *func_088DCEBC(s32, u8);
extern s32 func_08862354(char *, char *);
extern s32 func_0886171C(char *, s32, char *, s32);

static inline void mtx_identity(float *m) {
    asm {
        vmidt.q E000
        sv.q C000, 0(m)
        sv.q C010, 0x10(m)
        sv.q C020, 0x20(m)
        sv.q C030, 0x30(m)
    }
}

void func_088C95B0(char *arg0, char *arg1, Box *arg2, s32 arg3) {
    float m[16];
    Ent *c;
    float x, y, z;

    c = func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
    if (c != 0) {
        if (c->pos[0] < arg2->min[0] || arg2->max[0] < c->pos[0] ||
            c->pos[1] < arg2->min[1] || arg2->max[1] < c->pos[1] ||
            c->pos[2] < arg2->min[2] || arg2->max[2] < c->pos[2]) {
            return;
        }
    }
    z = arg2->pos[2];
    y = arg2->pos[1];
    x = arg2->pos[0];
    mtx_identity(m);
    m[12] = x;
    m[13] = y;
    m[14] = z;
    func_08862354((char *)m, arg1 + 0x10);
    func_0886171C(arg1, 0, arg0 + 0x70, arg3);
    func_08862354(arg0 + 0x10, arg1 + 0x10);
}
