/* unit_088CC828: 0x088CC828-0x088CD804 (ULES01213)
 *
 * Bounds (hypothesis): 7 functions between unit_088CC604 and unit_088CD804.
 *
 * A queue of four 0x20-byte entries at +4, each pointing at a 0x44-byte
 * record of the table at 0x089B5648; the records are chosen by the id at
 * D_089CC438 + 0x6AF12 and run step by step by func_088CD3FC.
 *
 * C++: the flag tests are bool conversions, and one virtual call.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Rec {
    u16 unk0;
    u16 unk2;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u16 unk8;
} Rec;

typedef struct V38 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual s32 vfunc_38(); } V38;

extern "C" {

extern char *D_089CC438;
extern char *D_089CC01C;
extern V38 *D_089CC434;
extern char *D_089CBBE4;
extern char *D_089CBBEC;
extern char *D_08A62C7C;
extern char *D_08A62D8C;
extern char *D_08A62D90;
extern char *D_08A631A0;
extern char *D_09A4F060;
extern char *D_09A4F06C;
extern char *D_09A4F0D0;
extern u16 D_09CE4808[];
typedef struct Pair { u16 unk0; u16 unk2; } Pair;
extern char D_09CE4848[];
extern u16 D_09CE5008[];
extern u16 D_09CE5220[];
extern Rec D_089B5648;
extern Rec D_089B568C;
extern Rec D_089B56D0;
extern Rec D_089B5714;
extern Rec D_089B5758;
extern Rec D_089B579C;
extern Rec D_089B57E0;
extern Rec D_089B5824;
extern Rec D_089B5868;
extern Rec D_089B58AC;
extern Rec D_089B58F0;
extern Rec D_089B5934;
extern Rec D_089B5978;
extern Rec D_089B59BC;
extern Rec D_089B5A00;
extern Rec D_089B5A44;
extern Rec D_089B5A88;
extern Rec D_089B5ACC;
extern Rec D_089B5B10;
extern Rec D_089B5B54;
extern Rec D_089B5B98;
extern Rec D_089B5BDC;
extern Rec D_089B5C20;
extern Rec D_089B5C64;
extern Rec D_089B5CA8;
extern Rec D_089B5CEC;
extern Rec D_089B5D30;
extern Rec D_089B5D74;
extern Rec D_089B5DB8;
extern Rec D_089B5DFC;
extern Rec D_089B5E40;
extern Rec D_089B5E84;
extern Rec D_089B5EC8;
extern Rec D_089B5F0C;
extern Rec D_089B5F50;
extern Rec D_089B5FDC;
extern Rec D_089B6020;
extern Rec D_089B6064;
extern Rec D_089B60A8;
extern Rec D_089B60EC;
extern Rec D_089B6130;
extern Rec D_089B6174;
extern Rec D_089B61B8;
extern Rec D_089B61FC;
extern Rec D_089B6240;
extern Rec D_089B6284;
extern Rec D_089B62C8;
extern Rec D_089B630C;
extern Rec D_089B6350;
extern Rec D_089B6394;
extern Rec D_089B63D8;
extern Rec D_089B641C;
extern Rec D_089B6460;
extern Rec D_089B64A4;

extern s32 sceKernelPowerTick(s32);
extern void func_08813DAC(char *);
extern s32 func_0884FA5C(char *, s32);
extern s32 func_0884FAFC(char *, s32);
extern s32 func_0884FB38(char *, s32);
extern void func_0884D790(char *, s16, s32);
extern s32 func_0886BF28(char *, u8 *);
extern void func_08882E24(char *, s32, s32, s32);
extern void func_08882F58(char *, s32);
extern void func_08885530(char *, s32);
extern void func_0888571C(char *, s32, s32);
extern void func_08885870(char *, s32, s32);
extern void func_08886074(char *, u16);
extern void func_08895F3C(char *);
extern s32 func_088CD804(char *, char *);
extern void func_088CD964(char *, Rec *);
extern u8 func_088CDA74(char *);
extern void func_088CDDAC(char *);
extern void func_088CDF5C(char *, Rec *);
extern void func_088DDBD8(char *, s32, s32, s32);
extern s32 func_09A648F0(char *);

s32 func_088CCDA4(char *arg0, char *arg1, Rec *arg2);
s32 func_088CCDFC(char *arg0);
s32 func_088CD044(char *arg0);
s32 func_088CD3FC(char *arg0, char *arg1);

#define ADD(off, rec) func_088CCDA4(arg0, arg0 + (off), &(rec))

void func_088CC828(char *arg0) {
    *(u8 *)(D_089CC438 + 0x422) = 0;
    *(u8 *)arg0 = 0;
    *(s32 *)(arg0 + 0x88) = 0;
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 0x24) = 0;
    *(s32 *)(arg0 + 0x44) = 0;
    *(s32 *)(arg0 + 0x64) = 0;
    *(u8 *)(arg0 + 0x98) = 0;
    *(u8 *)(arg0 + 0x99) = 0;
    if ((u16) func_088CCDFC(arg0) != 0) {
        return;
    }
    func_088CD044(arg0);
    switch (*(u16 *)(D_089CC438 + 0x6AF12)) {
    case 0x4E21: ADD(4, D_089B60A8); break;
    case 0x4E23:
        ADD(4, D_089B60EC);
        ADD(0x24, D_089B6130);
        ADD(0x44, D_089B6174);
        ADD(0x64, D_089B61B8);
        break;
    case 0x4E24: ADD(4, D_089B61FC); break;
    case 0x4E25: ADD(4, D_089B6240); break;
    case 0x4E26: ADD(4, D_089B6284); break;
    case 0x2779: ADD(4, D_089B5648); break;
    case 0x277D: ADD(4, D_089B568C); break;
    case 0x2778: ADD(4, D_089B56D0); break;
    case 0x277E: ADD(4, D_089B5714); break;
    case 0x2784: ADD(4, D_089B5758); break;
    case 0x27E5: ADD(4, D_089B579C); break;
    case 0x27E2: ADD(4, D_089B57E0); break;
    case 0x277F: ADD(4, D_089B5824); break;
    case 0x284E: ADD(4, D_089B5868); break;
    case 0x27DB: ADD(4, D_089B58AC); break;
    case 0x283E: ADD(4, D_089B58F0); break;
    case 0x27E3: ADD(4, D_089B5934); break;
    case 0x2849: ADD(4, D_089B5978); break;
    case 0x28A6: ADD(4, D_089B59BC); break;
    case 0x284D: ADD(4, D_089B5A00); break;
    case 0x28AD: ADD(4, D_089B5A44); break;
    case 0x290A: ADD(4, D_089B5A88); break;
    case 0x28AB: ADD(4, D_089B5ACC); break;
    case 0x28AE: ADD(4, D_089B5B10); break;
    case 0x28A2: ADD(4, D_089B5B54); break;
    case 0x2843: ADD(4, D_089B5B98); break;
    case 0x28AF: ADD(4, D_089B5BDC); break;
    case 0x290E: ADD(4, D_089B5C20); break;
    case 0x2840: ADD(4, D_089B5C64); break;
    case 0x2714: ADD(4, D_089B5D74); break;
    case 0x28A1: ADD(4, D_089B5DB8); break;
    case 0xC352: ADD(4, D_089B5FDC); break;
    case 0x2AFD: ADD(4, D_089B6020); break;
    case 0x2BC1: ADD(4, D_089B6064); break;
    }
}

s32 func_088CCDA4(char *arg0, char *arg1, Rec *arg2) {
    if ((u8) func_0884FB38(D_089CC438, arg2->unk0) == 0) {
        *(u8 *)arg1 = 1;
        *(Rec **)(arg1 + 0x1C) = arg2;
        return 0;
    }
    return -1;
}

#define FOUND(kind, msg, rec) \
    case kind: \
        func_0884FAFC(D_089CC438, msg); \
        ADD(4, rec); \
        return kind;

s32 func_088CCDFC(char *arg0) {
    u8 buf[4];
    s32 n;
    s32 i;
    u8 *p;

    *(u8 *)(arg0 + 0x9A) = 1;
    n = func_0886BF28(D_08A62C7C, buf);
    if (n == 0) {
        *(u8 *)(arg0 + 0x9A) = 0;
    }
    i = 0;
    if (n > 0) {
        p = buf;
        do {
        switch (*p) {
        FOUND(7, 0x158, D_089B5CA8)
        FOUND(0x32, 0x159, D_089B5CEC)
        FOUND(2, 0x15D, D_089B5DFC)
        FOUND(0x24, 0x15E, D_089B5E40)
        FOUND(0x47, 0x15F, D_089B5E84)
        FOUND(0x37, 0x15A, D_089B5D30)
        FOUND(0x4C, 0x160, D_089B5EC8)
        FOUND(0x3A, 0x162, D_089B5F0C)
        FOUND(0x58, 0x163, D_089B5F50)
        }
        *(u8 *)(arg0 + 0x9A) = 0;
        i++;
        p++;
        } while (i < n);
    }
    return 0;
}

static inline s32 get_unk45(char *p) {
    if (*(u8 *)(D_089CC438 + 0x480) != 0) {
        return 0;
    }
    return *(s8 *)(*(char **)(p + 0x4C) + 0x45);
}

s32 func_088CD044(char *arg0) {
    s32 flags;
    u8 id;
    s32 v;

    if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) == 1) {
        return 0;
    }
    flags = *(s32 *)(D_089CC438 + 0x6AF14);
    if ((bool) (flags & 0x100) == 1) {
        return 0;
    }
    if ((bool) (flags & 4) == 1) {
        return 0;
    }
    if (get_unk45(D_08A62C7C) != 0) {
        return 0;
    }
    id = *(u8 *)(D_089CC438 + 0x6AF10);
    v = D_09CE4808[id];
    v = (v != 0xFFFF) ? v : id;
    switch ((u16) v) {
    case 2: ADD(0x64, D_089B62C8); break;
    case 3: ADD(0x64, D_089B630C); break;
    case 4: ADD(0x64, D_089B6350); break;
    case 5: ADD(0x64, D_089B6394); break;
    case 6: ADD(0x64, D_089B63D8); break;
    case 0xB: ADD(0x64, D_089B641C); break;
    case 0xE:
    case 0xF: ADD(0x64, D_089B6460); break;
    case 0x1E: ADD(0x64, D_089B64A4); break;
    }
    return 0;
}

void func_088CD230(char *arg0) {
    s32 idx;

    switch (*(u8 *)arg0) {
    case 1:
        if (func_088CD3FC(arg0, arg0 + *(u8 *)(arg0 + 1) * 0x20 + 4) == 0) {
            break;
        }
        *(u8 *)(D_089CC438 + 0x422) = 0;
        *(s32 *)(arg0 + 0x88) = 0;
        *(u8 *)arg0 = 0;
    case 0:
        if (*(s32 *)(arg0 + 0x88) != 0) {
            idx = *(u8 *)(arg0 + 1);
            *(u8 *)arg0 = 1;
            func_088CD3FC(arg0, arg0 + idx * 0x20 + 4);
        } else {
            func_08895F3C(D_089CBBEC);
        }
        break;
    }
}

static inline bool is_plain(u16 id) {
    if (id == 0xFFFF) {
        return true;
    }
    return D_09CE5008[id] == 0;
}

static inline u16 map_id(u16 id) {
    u16 v;

    if (id == 0xFFFF) {
        return id;
    }
    v = D_09CE5220[id];
    return (v != 0xFFFF) ? v : id;
}

static inline u16 base_id(u16 id) {
    if (is_plain(id) == 1) {
        return id;
    }
    return map_id(id);
}

static inline u16 cur_id(char *g) {
    u16 id = *(u16 *)(g + 0x6AF0E);

    if (id == 0xFFFF) {
        return id;
    }
    return base_id(id);
}

s32 func_088CD2D4(char *arg0, char *arg1) {
    u16 id;

    if ((u8) func_0884FA5C(D_089CC438, 0) == 1) {
        return -1;
    }
    if ((u8) func_0884FB38(D_089CC438, (*(Rec **)(arg1 + 0x1C))->unk0) == 1) {
        *(s32 *)arg1 = 0;
        return -1;
    }
    id = cur_id(D_089CC438);
    if (id != (*(Rec **)(arg1 + 0x1C))->unk2) {
        return 0;
    }
    return 1;
}

s32 func_088CD3FC(char *arg0, char *arg1) {
    s32 id;
    s32 vol;
    char *p;
    s32 k;

    switch (*(u8 *)(arg1 + 1)) {
    case 0:
        *(u8 *)(D_089CC438 + 0x422) = 1;
        *(s32 *)(arg0 + 0x88) = 1;
        func_088CD964(arg0, *(Rec **)(arg1 + 0x1C));
        if ((*(Rec **)(arg1 + 0x1C))->unk8 != 0) {
            func_08882E24(D_08A62D8C, 0, (*(Rec **)(arg1 + 0x1C))->unk8, 0x7F);
            func_08886074(D_08A62D90, (*(Rec **)(arg1 + 0x1C))->unk8);
        }
        func_0884D790(D_089CC01C, 1, 1);
        func_088CDF5C(arg0, *(Rec **)(arg1 + 0x1C));
        *(u8 *)(arg0 + 0x9B) = 1;
        (*(u8 *)(arg1 + 1))++;
        break;
    case 1:
        func_0884D790(D_089CC01C, 0x10, 0);
        (*(u8 *)(arg1 + 1))++;
    case 2:
        sceKernelPowerTick(0);
        if (func_088CDA74(arg0) == 1) {
            if (*(u8 *)(arg0 + 0x99) != 0) {
                func_088CD804(arg0, arg1);
                *(u8 *)(D_089CC438 + 0x6AF1B) = 1;
                func_0884D790(D_089CC01C, 1, 1);
                func_08885870(D_08A62D8C, 0x10, 0);
                *(s32 *)(arg0 + 0x9C) = 0x10;
                *(u8 *)(arg1 + 1) = 0xA;
            } else {
                if (func_088CD804(arg0, arg1) != 0) {
                    return 1;
                }
                (*(u8 *)(arg1 + 1))++;
            }
        } else {
            func_088CDF5C(arg0, *(Rec **)(arg1 + 0x1C));
        }
        break;
    case 3:
        func_08813DAC(D_089CBBE4);
        func_0884D790(D_089CC01C, 1, 0);
        *(s32 *)arg1 = 0;
        return 1;
    case 0xA:
        if (--*(s32 *)(arg0 + 0x9C) < 0) {
            func_08885530(D_08A62D8C, 0);
            func_08882F58(D_08A62D8C, 0);
            (*(u8 *)(arg1 + 1))++;
        }
        break;
    case 0xB:
        if (*(u8 *)(D_089CC438 + 0x480) == 0 &&
            ((*(u16 *)(D_09A4F0D0 + 0x1F8) & 2) ? *(s32 *)(D_09A4F0D0 + 0x1FC) : 0) != 0) {
            func_088CDDAC(arg0);
            (*(u8 *)(arg1 + 1))++;
        }
        break;
    case 0xC:
        *(u8 *)(D_089CC438 + 0x6AF1B) = 0;
        func_0884D790(D_089CC01C, 0x10, 0);
        func_0888571C(D_08A62D8C, 0x10, 0);
        id = *(u16 *)(D_08A62D90 + 0x28);
        vol = 0x7F;
        if (id == 0x197D) {
            vol = ((Pair *) D_09CE4848)[*(u16 *)(D_09A4F060 + 0x288)].unk2;
        }
        func_08882E24(D_08A62D8C, 0, id, vol);
        func_08813DAC(D_089CBBE4);
        *(s32 *)arg1 = 0;
        return 1;
    }
    if (*(u8 *)(D_089CC438 + 0x480) == 0 && *(u8 *)(arg0 + 0x9A) != 0 && *(u8 *)(arg0 + 0x9B) != 0 &&
        D_089CC434->vfunc_38() == 0 &&
        (u16) ((*(u16 *)(D_09A4F0D0 + 0x1F8) & 3) ? *(u16 *)(D_09A4F0D0 + 0x1FA) : 0xFFFF) == 0xFFFF) {
        p = *(char **)(D_09A4F06C + 0x20);
        k = p != 0 ? *(u8 *)(p + 4) : 0;
        if (k == 0x3B) {
            func_088DDBD8(D_09A4F0D0, 0x2A, 0x197D, 0);
        } else {
            func_088DDBD8(D_09A4F0D0, 0x2A, func_09A648F0(D_08A62D90), 0);
        }
    }
    return 0;
}

}
