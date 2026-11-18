/* unit_088C0E58: 0x088C0E58-0x088C1178 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088C0BBC and code still in
 * assembly (text_088C1178).
 *
 * C++: virtual calls. A state machine on the word at +0x998: two loading
 * steps, then one step per slot that copies a record into the table at
 * D_089CC438 + 0x30 and sets up the slot's object.
 *
 * Optimized for speed: the copy loop walks four pointers. The copy goes
 * through an Info pointer (the loop's destination base is d + 0x10), and the
 * slot address is written as char arithmetic (the index is computed before
 * the D_089CC438 load). The slot index is an s32 holding (s16) (state - 2),
 * copied into an s16 for the calls (the original extends it again).
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct { s16 v[3]; } S3;

typedef struct {
    u8 a;
    u8 b;
    u16 c;
    u16 d;
    S3 pos;
} Ent;

typedef struct {
    u8 name[5];
    u8 extra[5][4];
    u8 pad19[3];
    s32 v1C;
    u8 v20;
    u8 v21;
    u16 v22;
    u16 v24;
    S3 pos;
    Ent ent[5];
} Info;

typedef struct {
    u8 used;
    u8 pad1[0xF];
    Info info;
    u8 pad78[0x14];
} Slot;

typedef struct {
    u8 pad0[0x12];
    u8 flag;
    u8 name[5];
    u8 pad18[4];
    s32 v1C;
    u8 v20;
    u8 v21;
    u16 v22;
    u16 v24;
    S3 pos;
    Ent ent[5];
    u8 pad68[0x6A79E - 0x68];
    u8 extra[5][4];
} Src;

struct VObj {
    virtual void vfunc_08();
    virtual void vfunc_0C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual s32 vfunc_20(s32);
    virtual void vfunc_24(s32, s32, s32);
};

extern "C" {

extern char *D_09A4F0D0;
extern char *D_09A4F0C4;
extern char *D_089CC438;

extern void func_088DDBD8(char *, s32, s32, s32);
extern s32 func_088DDF10(char *, s32);
extern s32 func_088DBBBC(char *, s16);
extern VObj *func_088DB608(char *, s16);
extern s32 func_0885187C(char *, s16, s32);
extern void func_088D2C14(VObj *);

s32 func_088C0E58(char *arg0) {
    VObj *obj;
    s16 n;
    char *rec;
    Src *s;
    Slot *d;
    Info *di;
    s32 j;
    s32 k;
    s32 id;

    if (*(s32 *)(arg0 + 0x998) == 0) {
        func_088DDBD8(D_09A4F0D0, 7, 0x151C, 0);
        (*(s32 *)(arg0 + 0x998))++;
    } else if (*(s32 *)(arg0 + 0x998) == 1) {
        if (func_088DDF10(D_09A4F0D0, 7) != 0) {
            return 0;
        }
        *(s32 *)(D_09A4F0C4 + 0x40) = (*(u16 *)(D_09A4F0D0 + 0x54) & 2) ? *(s32 *)(D_09A4F0D0 + 0x58) : 0;
        (*(s32 *)(arg0 + 0x998))++;
    } else {
        k = (s16) (*(s32 *)(arg0 + 0x998) - 2);
        rec = *(char **)(arg0 + 0x94C) + k * 0x6B100;
        s = (Src *)(rec + 0x1000);
        if (*(u8 *)(rec + 0x1012) == 1) {
            d = (Slot *)(D_089CC438 + k * 0x8C + 0x30);
            d->used = 1;
            di = &d->info;
            di->name[0] = s->name[0];
            di->name[1] = s->name[1];
            di->name[2] = s->name[2];
            di->name[3] = s->name[3];
            di->name[4] = s->name[4];
            di->v1C = s->v1C;
            di->v20 = s->v20;
            di->v21 = s->v21;
            di->v22 = s->v22;
            di->v24 = s->v24;
            di->pos = s->pos;
            for (j = 0; j < 5; j++) {
                di->ent[j].a = s->ent[j].a;
                di->ent[j].b = s->ent[j].b;
                di->ent[j].c = s->ent[j].c;
                di->ent[j].d = s->ent[j].d;
                di->ent[j].pos = s->ent[j].pos;
                di->extra[j][0] = s->extra[j][0];
                di->extra[j][1] = s->extra[j][1];
                di->extra[j][2] = s->extra[j][2];
                di->extra[j][3] = s->extra[j][3];
            }
            n = k;
            if ((u8) func_088DBBBC(D_09A4F0C4, n) == 1) {
                obj = func_088DB608(D_09A4F0C4, n);
                if (*(u8 *)((char *) obj + 0x4E0) == 0) {
                    id = 1;
                } else {
                    id = 0x32B;
                }
                obj->vfunc_24(id, obj->vfunc_20(id), -1);
                *(s32 *)((char *) obj + 4) |= 4;
                *(s16 *)((char *) obj + 0x53A) = func_0885187C(D_089CC438, n, 2);
                func_088D2C14(obj);
                (*(s32 *)(arg0 + 0x998))++;
            }
        } else {
            ((Slot *)(D_089CC438 + k * 0x8C + 0x30))->used = 0;
            (*(s32 *)(arg0 + 0x998))++;
        }
    }
    return *(s32 *)(arg0 + 0x998) == 5;
}

}
