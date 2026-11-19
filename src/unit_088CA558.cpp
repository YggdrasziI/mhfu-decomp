/* unit_088CA558: 0x088CA558-0x088CA908 (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088CA558 asm piece, 1 function
 * between unit_088CA508 and unit_088CA908.
 *
 * C++: virtual calls. Looks for the first 0x18-byte entry of kind 0x17 of a
 * store, then registers each 0x20-byte record of the list (as
 * func_088CA39C).
 *
 * NonMatching: the image keeps the original code.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Rec {
    u32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    char unk10[0x10];
} Rec;

typedef struct List {
    virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual char *vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54(); virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74(); virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84(); virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual void vfunc_94(); virtual void vfunc_98(); virtual void vfunc_9C(); virtual void vfunc_A0(); virtual void vfunc_A4(); virtual void vfunc_A8();
    virtual s32 vfunc_AC();
    virtual Rec *vfunc_B0();
} List;

typedef struct Info {
    char pad0[0x10];
    char *unk10;
    char pad14[0x2A];
    s8 count;
} Info;

typedef struct Store {
    virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24();
    virtual Info *vfunc_28();
} Store;

typedef struct Mgr {
    Store *store;
} Mgr;

extern "C" {

extern char *D_089CC438;
extern s32 D_08A62D8C;
extern Mgr *D_09A4F060;
extern s32 D_09A4F06C;
extern s32 func_0884FA5C(char *, s32);
extern s32 func_088CDEDC(s32, s32, s32);
extern s32 func_088855C4(s32, s32, s32, s32);
extern void func_08885494(s32, s32, s32, s32, s32);
extern void func_08884748(s32, s32, s32, s32, s32, char *, s32, s32, s32);
extern s32 func_088C6BCC(Mgr *, s32, s32, s32, s32, s32, char *, s32);
extern s32 func_08883B54(s32, s32, s32, s32, s32, s32, char *, s32, s32, s32, s32);

/* NonMatching, 99.32 %: `found = 0` is set at each pass of the entry loop in
 * the original (delay slot of the kind test); ours sets it once before the
 * loop (only the exits set it to 1). Tried: the store inside the `if`, a
 * block-scoped or `bool` / `u8` flag, a comma expression, a `continue` form,
 * the first part as an inline helper, every declaration order. */
void func_088CA558(List *arg0) {
    s32 j;
    char *p;
    s32 found;
    Rec *rec;
    s32 i;

    if ((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 1) != 1) {
        p = D_09A4F060->store->vfunc_28()->unk10;
        j = 0;
        if (D_09A4F060->store->vfunc_28()->count > 0) {
            do {
                found = 0;
                if (*(u16 *)(p + 2) == 0x17 && *(u16 *)(p + 0x16) == 0) {
                    p = arg0->vfunc_44();
                    if (p == 0) {
                        break;
                    }
                    if ((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 1) == 0) {
                        switch (*(u8 *)(D_089CC438 + 0x2E)) {
                        case 6:
                        case 5:
                        case 7:
                        case 8:
                            if (func_088855C4(D_08A62D8C, 6, 0xC0, 0) != 0) {
                                func_08885494(D_08A62D8C, 6, 0xC0, 0, 0);
                            }
                            found = 1;
                            break;
                        }
                    }
                    if (found == 0) {
                        func_088C6BCC(D_09A4F060, 6, 0x11, 0, 0xC0, 0, p, 9);
                    }
                    break;
                }
                j++;
                p += 0x18;
            } while (j < D_09A4F060->store->vfunc_28()->count);
        }
    }

    rec = arg0->vfunc_B0();
    i = 0;
    if (arg0->vfunc_AC() > 0) {
        do {
            if ((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 1) == 0 && (u8) func_0884FA5C(D_089CC438, 0) == 1) {
                j = i + 1;
                if (func_088855C4(D_08A62D8C, rec->unk4, 0xC0, j) != 0) {
                    func_08885494(D_08A62D8C, rec->unk4, 0xC0, j, 0);
                }
            } else if ((u8) func_088CDEDC(D_09A4F06C, rec->unk8, 1) == 0) {
                if (rec->unk0 == 0) {
                    func_088C6BCC(D_09A4F060, rec->unk4, rec->unk8, 0, 0xC0, i + 1, rec->unk10, rec->unkC);
                } else if (*(u16 *)(D_089CC438 + 0x1C) % rec->unk0 == 0) {
                    func_08883B54(D_08A62D8C, rec->unk4, rec->unk8, 0, 0xC0, i + 1, rec->unk10, rec->unkC, 0, 0, 0);
                }
                if (rec->unk0 != 0 && rec->unk8 != 0x50) {
                    func_08884748(D_08A62D8C, rec->unk4, 0, 0xC0, i + 1, rec->unk10, rec->unkC, 0, 0);
                }
            }
            i++;
            rec++;
        } while (i < arg0->vfunc_AC());
    }
}

}
