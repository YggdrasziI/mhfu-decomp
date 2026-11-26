/* unit_0884E478: 0x0884E478-0x0884E5B4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884E478: 0x0884E478-0x0884E5B4 (ULES01213) */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

typedef struct {
    f32 f[8];
} Msg;

typedef struct {
    u16 used;
    u8 pad2[0x1E];
} Slot;

typedef struct {
    char *vt;
    Slot ent[0x80];
    s32 head;
    s32 cur;
} Obj;

typedef struct V34 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(u16, s32, s32, u8, s32, s32); } V34;

extern "C" {

void func_0884E478(Obj *p, Msg *m) {
    Msg c;
    s32 n;
    s32 i;

    n = (*(s32 *)&m->f[4] + 0x1FFFF) / 0x20000 - 1;
    c = *m;
    *(u16 *)m = 0;
    p->head -= n;
    p->head &= 0x7F;
    p->cur = p->head;
    ((V34 *)p)->vfunc_34(*(u16 *)((char *)&c + 2), *(s32 *)&c.f[1],
                         *(s32 *)&c.f[4], *(u8 *)&c.f[6], *(s32 *)&c.f[5], 0);
    i = 0;
    while (p->ent[p->cur].used != 0) {
        i++;
        p->cur++;
        p->cur &= 0x7F;
        if (i >= 0x7F) {
            p->cur = p->head - 1;
            p->cur &= 0x7F;
            break;
        }
    }
}

}
