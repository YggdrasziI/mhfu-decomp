/* unit_08835F7C: 0x08835F7C-0x088375C8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 *
 * .rodata: the jump tables of the two switches (jtbl_08931018, 36 entries;
 * jtbl_089310A8, 6 entries).
 */

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern char *D_08A631A0;
extern s32 D_09A4F0C4;
extern char *D_08A631A8;
extern char *D_09A0B544;
extern s32 D_09B22D70;
extern s32 D_09CFB798;
extern s32 D_09CFB898;
extern s32 D_09CFBBF0;
extern s32 D_09B0FF88;
extern u16 D_09B04DE0;
extern u16 D_09B04E08[];
extern u16 D_09B05238;
extern u16 D_09B0523A;
extern u16 D_09B0523C;
extern u16 D_09B0523E;
extern u16 D_09B05240;
extern u16 D_09B05242;
extern u16 D_09B05244;
extern u16 D_09B05246;
extern u16 D_09B05248;
extern u16 D_09B0524A;
extern u16 D_09B0524C;
extern u16 D_09B0524E;
extern u16 D_09B05250;
extern u16 D_09B05252;
extern u16 D_09B05254;
extern u16 D_09B05256;
extern u16 D_09B05258;
extern u16 D_09B0525A;
extern u16 D_09B0525C;
extern u16 D_09B0525E;
extern u16 D_09B05260;
extern u16 D_09B05262;
extern u16 D_09B05264;
extern u16 D_09B05266;
extern u16 D_09B05268;
extern u16 D_09B0526A;
extern u16 D_09B0526C;
extern u16 D_09B0526E;
extern u16 D_09B05270;
extern u16 D_09B05272;
extern u16 D_09B05274;
extern u16 D_09B05276;
extern u16 D_09B05278;
extern u16 D_09B05284;
extern char D_0893B224[];
extern char D_0893B22C[];

typedef struct {
    u16 id;
    u8 pad2;
    u8 c;
} Ent;

typedef struct {
    char pad0[0x298];
    u8 a;
    u8 b;
    char pad29A[0x554 - 0x29A];
    char *ent;
} Rec;

extern Rec *func_088DCEBC(s32, u8);
extern s32 func_08838AB4(char *, u8, u8);
extern s32 func_0882A864(char *, s32);
extern int func_08890E08(char *, s32);
extern void func_08825DA8(char *);
extern void func_08890E38(char *, s8);
extern void func_08890DE8(char *, s8, u8);
extern void func_08890DFC(char *, s16, s16);
extern char *func_09A7B790(s32, u16);
extern char *func_09A7B7D0(s32, u16);
extern int func_0889134C(char *, char *, ...);
extern void func_08891474(char *, s16, s16, char *, ...);
extern s32 func_08890E48(char *, char *);
extern void func_08838B08(char *, s32, s16, s16, s32, u32, s32);
extern void func_08838E0C(char *, s32, u16, s32, s32, s32);
extern s32 func_09C19580(s32, s32);
extern s32 func_09C1B868(s32);
extern s32 func_09C1B888(s32);
extern s32 func_09A62E58(s32, u8);
extern s32 func_09A7BFA8(s32);
extern s32 func_0885057C(char *);
extern s32 func_09C294B8(s32);
extern s32 func_09C294F8(s32, u16);
extern s32 func_09C29548(s32, u16);
extern s32 func_09C29598(s32);
extern s32 func_09C295E0(s32);
extern s32 func_09C29630(s32, u16);
extern s32 func_09C29688(s32);

#define TXT(id) func_09A7B790(D_09B22D70, id)
#define FLAG() ((s32)((*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0))
#define MSG(id)                                                                          \
    func_08891474(D_08A631A8, 0x24, 0x12, D_0893B224, TXT(D_09B04DE0), TXT(id)); \
    s = TXT(id)
#define MSG2(id)                                                              \
    func_0889134C(D_08A631A8, D_0893B224, TXT(D_09B04DE0), TXT(id)); \
    s = TXT(id)

void func_08835F7C(char *arg0, u32 arg1) {
    s16 n;
    Rec *p;
    char *q;
    Ent *r;
    s16 w;
    char *s;
    s16 w2;
    s16 y;
    s32 t;

    p = func_088DCEBC(D_09A4F0C4, D_089CC438[0x28]);
    if ((p->b != 0x10 && (u8)func_08838AB4(arg0, p->a, p->b) == 1) ||
        p->a != 0 || (u8)func_0882A864(arg0, 0) == 0 ||
        (p->a == 0 && (p->b == 13 || p->b == 14))) {
        arg0[0x535] = 0x28;
        return;
    }
    switch (arg1) {
    case 0:
        arg0[0x534] = 9;
        break;
    case 1:
        arg0[0x534] = 10;
        break;
    case 2:
        arg0[0x534] = 11;
        break;
    case 3:
        arg0[0x534] = 12;
        break;
    case 4:
        arg0[0x534] = 13;
        break;
    case 5:
        arg0[0x534] = 14;
        break;
    }
    func_08890E08(D_08A631A8, (s8)arg1);
    func_08825DA8(arg0);
    func_08890E38(D_08A631A8, 0);
    func_08890DE8(D_08A631A8, 14, 14);
    w = 0x78;
    s = 0;
    if (p->ent != 0) {
        if (--*(s8 *)(arg0 + 0x535) <= 0) {
            arg0[0x535] = 0x28;
        }
        func_08890DFC(D_08A631A8, 0x24, 0x12);
        q = p->ent;
        switch (*(u16 *)(q + 2)) {
        case 1:
            n = 0;
            r = (Ent *)func_09A7B7D0(D_09B22D70, *(u16 *)(q + 0x16));
            switch (r->id) {
            case 0x42:
                if (*(u16 *)(D_089CC438 + 0x6AF0E) == 0xD) {
                    MSG2(D_09B05258);
                } else {
                    MSG2(D_09B0524A);
                }
                break;
            case 0x8B:
                if (*(u16 *)(D_089CC438 + 0x6AF0E) == 0x2E) {
                    MSG2(D_09B05254);
                } else {
                    MSG2(D_09B0524C);
                }
                break;
            case 0x55:
                if ((u8)func_09C19580(D_09CFB798, 7) == 0) {
                    return;
                }
                func_0889134C(D_08A631A8, D_0893B224, TXT(D_09B04DE0), TXT(D_09B0524E));
                w2 = (func_08890E48(D_08A631A8, TXT(D_09B0524E)) + 4) * 7 + 0x24;
                func_08890DFC(D_08A631A8, 0x24, 0x22);
                func_0889134C(D_08A631A8, D_0893B224, TXT(D_09B04DE0), TXT(D_09B05250));
                y = (func_08890E48(D_08A631A8, TXT(D_09B05250)) + 4) * 7 + 0x24;
                if (w2 >= y) {
                    w = w2;
                } else {
                    w = y;
                }
                break;
            case 0x2E:
                if ((u8)func_09C19580(D_09CFB798, 5) == 0) {
                    return;
                }
                if (*(u16 *)(D_089CC438 + 0x6AF0E) == 0x11) {
                    MSG2(D_09B0525C);
                } else {
                    MSG2(D_09B05252);
                }
                break;
            case 0xD:
                if ((u8)func_09C1B868(D_09CFB898) == 0) {
                    return;
                }
                MSG2(D_09B05256);
                break;
            case 0x11:
                MSG2(D_09B0525A);
                break;
            }
            if (s != 0) {
                w = (func_08890E48(D_08A631A8, s) + 4) * 7 + 0x24;
            }
            if ((u8)func_09A62E58(D_09B0FF88, r->c) == 1) {
                y = (func_08890E48(D_08A631A8, TXT(D_09B05278)) + 4) * 7 + 0x24;
                if (w < y) {
                    w = y;
                }
            }
            func_08838B08(arg0, 0, 0x10, w, 0x10, 0x801D3905, 0);
            func_08838E0C(arg0, 0x10, 0x10, 0x35, *(s8 *)(arg0 + 0x535), 0x14);
            if (r->id == 0x55) {
                n++;
                t = n * 16 + 0x10;
                func_08838B08(arg0, 0, t, w, 0x10, 0x801D3905, 0);
                func_08838E0C(arg0, 0x10, t, 0x32, *(s8 *)(arg0 + 0x535), 0x14);
            }
            if ((u8)func_09A62E58(D_09B0FF88, r->c) == 1) {
                n++;
                func_08890DFC(D_08A631A8, 0x24, n * 16 + 0x12);
                func_0889134C(D_08A631A8, D_0893B224, TXT(D_09B04DE0), TXT(D_09B05278));
                t = n * 16 + 0x10;
                func_08838B08(arg0, 0, t, w, 0x10, 0x801D3905, 0);
                func_08838E0C(arg0, 0x10, t, 0x34, *(s8 *)(arg0 + 0x535), 0x14);
            }
            return;
        case 2:
            if (FLAG() == 0) {
                if ((u8)func_09A7BFA8(D_09B22D70) == 0) {
                    return;
                }
            } else {
                if ((u8)func_09A7BFA8(D_09B22D70) == 0) {
                    return;
                }
            }
            if (FLAG() == 1 && *(u8 *)(D_09A0B544 + 0x12D6) == 0) {
                MSG(D_09B05246);
            } else {
                MSG(D_09B0523C);
            }
            break;
        case 3:
            if ((u8)func_0885057C(D_089CC438) == 0) {
                return;
            }
            MSG(D_09B05262);
            break;
        case 5:
            MSG(D_09B05240);
            break;
        case 6:
            MSG(D_09B05242);
            break;
        case 7:
            MSG(D_09B05244);
            break;
        case 8:
            if ((u8)func_08838AB4(arg0, p->a, p->b) == 1) {
                MSG(D_09B0523A);
            } else {
                MSG(D_09B05238);
            }
            break;
        case 9:
            if (FLAG() != 1) {
                return;
            }
            MSG(D_09B0523E);
            break;
        case 10:
            MSG(D_09B05260);
            break;
        case 11:
            w += 0x28;
            MSG(D_09B0525E);
            break;
        case 12:
            w += 0x28;
            MSG(D_09B05284);
            break;
        case 13:
            if ((u8)func_09C1B888(D_09CFB898) != 0) {
                return;
            }
            MSG(D_09B05248);
            break;
        case 14:
            if (*(u16 *)q > func_09C294B8(D_09CFBBF0)) {
                return;
            }
            if (*(u16 *)(q + 0x16) % 2 == 0) {
                MSG(D_09B05274);
            } else {
                MSG(D_09B05276);
            }
            break;
        case 15:
            if ((u8)func_09C294F8(D_09CFBBF0, *(u16 *)(q + 0x16)) == 0) {
                return;
            }
            MSG(D_09B0526C);
            break;
        case 16:
            if ((u8)func_09C29548(D_09CFBBF0, *(u16 *)(q + 0x16)) == 0) {
                return;
            }
            MSG(D_09B0526E);
            break;
        case 17:
            if ((u8)func_09C29598(D_09CFBBF0) == 0) {
                return;
            }
            MSG(D_09B05270);
            break;
        case 18:
            if ((u8)func_09C295E0(D_09CFBBF0) == 0) {
                return;
            }
            MSG(D_09B05272);
            break;
        case 19:
            if ((u8)func_09C29688(D_09CFBBF0) == 0) {
                return;
            }
            func_08891474(D_08A631A8, 0x24, 0x12, D_0893B224, TXT(D_09B04DE0), TXT(D_09B05266));
            w2 = (func_08890E48(D_08A631A8, TXT(D_09B05266)) + 6) * 7 + 0x24;
            func_08838B08(arg0, 0, 0x10, w2, 0x10, 0x801D3905, 0);
            func_08838E0C(arg0, 0x10, 0x10, 0x35, *(s8 *)(arg0 + 0x535), 0x14);
            func_08891474(D_08A631A8, 8, 0x22, D_0893B22C, TXT(D_09B05268),
                          TXT(D_09B04E08[(u8)D_089CC438[0x6A23F]]), TXT(D_09B0526A));
            func_08838B08(arg0, 0, 0x20, w2, 0x10, 0x801D3905, 0);
            return;
        case 20:
            if ((u8)func_09C29630(D_09CFBBF0, *(u16 *)(q + 0x16)) == 0) {
                return;
            }
            MSG(D_09B05264);
            break;
        case 21:
            return;
        case 29:
            MSG(D_09B05248);
            break;
        case 0:
        case 4:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
            break;
        }
        if (s != 0) {
            w = (func_08890E48(D_08A631A8, s) + 4) * 7 + 0x24;
        }
        func_08838B08(arg0, 0, 0x10, w, 0x10, 0x801D3905, 0);
        func_08838E0C(arg0, 0x10, 0x10, 0x35, *(s8 *)(arg0 + 0x535), 0x14);
    } else {
        arg0[0x535] = 0x28;
    }
}
