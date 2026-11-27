/* unit_088C7CDC: 0x088C7CDC-0x088C8114 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088C7CDC (ULES01213): vtable method of D_089BACDC.
 *
 * C++: virtual calls. Walks the 8-byte entries returned by vfunc_48 and,
 * for each, emits GE commands and dispatches on the entry kind (switch
 * through a jump table, 20 entries).
 *
 * Speed setting, and loop invariants off (otherwise arg0 + 0x70 is hoisted
 * into a saved register).
 */

#pragma optimize_for_size off
#pragma opt_loop_invariants off
typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef struct Ent {
    u8 kind;
    u8 flags;
    u8 unk2;
    u8 unk3;
    s32 unk4;
} Ent;

typedef struct Hdr {
    char pad0[2];
    s16 count;
    char pad4[4];
    Ent *ents;
} Hdr;

typedef struct Obj {
    virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44();
    virtual Hdr *vfunc_48();
    virtual void vfunc_4C(); virtual void vfunc_50();
    virtual void vfunc_54(char *, s32, u8); virtual void vfunc_58(char *, s32, u8); virtual void vfunc_5C(char *, s32, u8); virtual void vfunc_60(char *, s32, u8); virtual void vfunc_64(char *, s32, u8); virtual void vfunc_68(char *, s32, u8); virtual void vfunc_6C(char *, s32, u8); virtual void vfunc_70(char *, s32, u8); virtual void vfunc_74(char *, s32, u8); virtual void vfunc_78(); virtual void vfunc_7C(char *, s32, u8); virtual void vfunc_80(char *, s32, u8); virtual void vfunc_84(char *, s32, u8); virtual void vfunc_88(char *, s32); virtual void vfunc_8C(char *, s32, u8); virtual void vfunc_90(char *, s32, u8); virtual void vfunc_94(); virtual void vfunc_98(char *, s32);
} Obj;

extern "C" {

extern s32 *D_089CC000;
extern char *D_089CC438;
extern s32 func_08862354(char *, char *);
extern s32 func_0886171C(char *, s32, char *, u8);

void func_088C7CDC(Obj *arg0) {
    char *b;
    Ent *e;
    s32 i;

    b = (char *)arg0 + 0x1D0;
    e = arg0->vfunc_48()->ents;
    func_08862354((char *)arg0 + 0x10, b + 0x10);
    for (i = 0; i < arg0->vfunc_48()->count; i++, e++) {
        *D_089CC000 = (e->unk2 << 8) | 0xDBFF0007;
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
        switch (e->kind) {
        case 1: func_0886171C(b, 0, (char *)arg0 + 0x70, e->unk3); break;
        case 2: arg0->vfunc_54(b, e->unk4, e->unk3); break;
        case 3: arg0->vfunc_58(b, e->unk4, e->unk3); break;
        case 4: arg0->vfunc_5C(b, e->unk4, e->unk3); break;
        case 5: arg0->vfunc_60(b, e->unk4, e->unk3); break;
        case 6: arg0->vfunc_64(b, e->unk4, e->unk3); break;
        case 7: arg0->vfunc_68(b, e->unk4, e->unk3); break;
        case 8: arg0->vfunc_6C(b, e->unk4, e->unk3); break;
        case 9: arg0->vfunc_70(b, e->unk4, e->unk3); break;
        case 10: arg0->vfunc_74(b, e->unk4, e->unk3); break;
        case 12: arg0->vfunc_7C(b, e->unk4, e->unk3); break;
        case 13: arg0->vfunc_80(b, e->unk4, e->unk3); break;
        case 14: arg0->vfunc_84(b, e->unk4, e->unk3); break;
        case 15: arg0->vfunc_88(b, e->unk4); break;
        case 16: arg0->vfunc_8C(b, e->unk4, e->unk3); break;
        case 17: arg0->vfunc_90(b, e->unk4, e->unk3); break;
        case 19: arg0->vfunc_98(b, e->unk4); break;
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
