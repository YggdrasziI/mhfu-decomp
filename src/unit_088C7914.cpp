/* unit_088C7914: 0x088C7914-0x088C7CDC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088C7914: virtual method of the class whose vtable is D_089BACDC. */

#pragma optimize_for_size off
#pragma opt_loop_invariants off
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

typedef struct Ent {
    u8 type;
    u8 flags;
    u8 b2;
    u8 b3;
    s32 arg;
} Ent;

typedef struct Hdr {
    s16 count;
    s16 pad;
    Ent *ent;
} Hdr;

struct V {
    virtual void vfunc_08();
    virtual void vfunc_0C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual Hdr *vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54(char *, s32, u8);
    virtual void vfunc_58(char *, s32, u8);
    virtual void vfunc_5C(char *, s32, u8);
    virtual void vfunc_60();
    virtual void vfunc_64(char *, s32, u8);
    virtual void vfunc_68(char *, s32, u8);
    virtual void vfunc_6C(char *, s32, u8);
    virtual void vfunc_70(char *, s32, u8);
    virtual void vfunc_74();
    virtual void vfunc_78(char *, s32, u8);
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88(char *, s32);
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94(char *, s32, u8);
    virtual void vfunc_98(char *, s32);
};

extern "C" {

extern u32 *D_089CC000;
extern char *D_089CC438;
extern s32 func_08862354(s32, s32);
extern s32 func_0886171C(char *, s32, char *, u8);

void func_088C7914(V *self) {
    char *s;
    Ent *e;
    s32 i;

    s = (char *)self + 0x50;
    e = self->vfunc_48()->ent;
    func_08862354((s32)((char *)self + 0x10), (s32)(s + 0x10));
    for (i = 0; i < self->vfunc_48()->count; i++, e++) {
        *D_089CC000 = (e->b2 << 8) | 0xDBFF0007;
        D_089CC000++;
        if ((e->flags & 1) && ((u8 *)D_089CC438)[0x422] != 0) {
            continue;
        }
        if (e->flags & 4) {
            *D_089CC000 = 0xDE000001;
            D_089CC000++;
        }
        if (e->flags & 2) {
            *D_089CC000 = 0xE7000001;
            D_089CC000++;
        }
        switch (e->type) {
        case 0:
            break;
        case 1:
            func_0886171C(s, 0, (char *)self + 0x70, e->b3);
            break;
        case 2:
            self->vfunc_54(s, e->arg, e->b3);
            break;
        case 3:
            self->vfunc_58(s, e->arg, e->b3);
            break;
        case 4:
            self->vfunc_5C(s, e->arg, e->b3);
            break;
        case 6:
            self->vfunc_64(s, e->arg, e->b3);
            break;
        case 7:
            self->vfunc_68(s, e->arg, e->b3);
            break;
        case 8:
            self->vfunc_6C(s, e->arg, e->b3);
            break;
        case 9:
            self->vfunc_70(s, e->arg, e->b3);
            break;
        case 0xB:
            self->vfunc_78(s, e->arg, e->b3);
            break;
        case 0xF:
            self->vfunc_88(s, e->arg);
            break;
        case 0x12:
            self->vfunc_94(s, e->arg, e->b3);
        case 0x13:
            self->vfunc_98(s, e->arg);
            break;
        }
        if (e->flags & 4) {
            *D_089CC000 = 0xDE000005;
            D_089CC000++;
        }
        if (e->flags & 2) {
            *D_089CC000 = 0xE7000000;
            D_089CC000++;
        }
    }
}

}
