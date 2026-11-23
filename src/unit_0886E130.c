/* unit_0886E130: 0x0886E130-0x0886E23C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886E130: flags an entry, plays a sound by kind, sends message 0x14. */

typedef int s32;
typedef short s16;
typedef unsigned char u8;

typedef struct {
    u8 type;
    s16 a;
    s16 b;
    s16 c;
    s16 d;
    s16 e;
} Msg;

typedef struct {
    s32 flags;
    s16 pad4;
    s16 unk6;
} Slot;

typedef struct {
    char pad0[0x24];
    char *unk24;
    char pad28[0x700];
    Slot ent[1];
} Owner;

extern char *D_089CBBEC;
extern s32 D_09A1DAEC;
extern s32 func_0886E08C(Owner *, s32);
extern int func_088966C0(char *, s32);
extern void func_0886E828(Owner *, s32);
extern void func_088AB514(s32, s32, Msg *);

void func_0886E130(Owner *arg0, s32 arg1, s32 arg2) {
    Msg m;
    Slot *s;
    char *p;

    if (func_0886E08C(arg0, arg1) != 0) {
        return;
    }
    arg0->ent[arg1].flags |= 0x20;
    if (arg2 == 0x200) {
        func_088966C0(D_089CBBEC, 0x11);
    }
    if (arg2 == 0x100) {
        func_088966C0(D_089CBBEC, 0x12);
    }
    func_0886E828(arg0, 0);
    s = &arg0->ent[arg1];
    if ((s->flags & 0x11) == 0x11) {
        s->unk6 = 0;
    }
    m.b = (unsigned int)arg2 >> 16;
    m.d = arg1;
    m.a = 0;
    m.c = arg2;
    m.type = 0x14;
    p = arg0->unk24;
    if (p != 0) {
        m.e = *(s16 *)(p + 0x4AC);
    } else {
        m.e = -1;
    }
    func_088AB514(D_09A1DAEC, 6, &m);
}
