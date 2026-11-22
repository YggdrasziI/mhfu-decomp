/* unit_0889B1A4: 0x0889B1A4-0x0889BCB4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Dispatches a received packet (0x324-byte buffer, message at +0x20) on its
 * type through a 19-entry switch. The six-byte id comparison and the peer
 * lookup are inline helpers.
 *
 * C++: the flag tests keep their `sltu` (bool). Optimized for speed: the
 * six-byte compare loops are tested at the bottom with no entry jump.
 * The compare in cases 7 and 17 reads the id as a member (`q->id[(unsigned
 * int) i]`, offset 0x5CE folded into the load); the peer lookup indexes its
 * table (`tbl + i * 8 + 0x50`). func_088D72A4 takes (char *, u16, s16, s32)
 * here (the `seh` before the `jal`); func_08858840's third parameter is s32
 * (the byte argument is read before the global).
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

extern "C" {

typedef struct { f32 v[3]; } F3;
typedef struct { f32 v[2]; } F2;
typedef struct { F3 a; F2 b; } Rec;

extern char *D_089CC438;
extern s32 D_09A5242C;
extern char *D_09A0B544;
extern s32 D_09A4F0C4;
extern s32 D_09A0FDC4;
extern char *D_08A631A0;
extern char *D_089CBBEC;
extern s32 D_09CFBBC8;
extern s32 D_09B22D70;
extern u16 D_09B05D0A;
extern u16 D_09B05300[];
extern char D_08A5C440[];
extern char D_089B16DC[];

extern void func_088B09A4(char *);
extern char *func_0889C518(char *);
extern s32 func_0880BFF0(void *, void *, s32);
extern s32 func_088FC810(char *, char *, char *, char *, s32, s32, s32, s32);
extern void func_0889D8A8(char *, char *, s32, s32 *);
extern void func_088FC724(char *, char *, s32);
extern s32 func_088900C4(char *, s32);
extern char *func_088DCEBC(s32, s32);
extern void func_09AAEE70(char *, s32, s32, s32);
extern s32 func_088568AC(char *, u16);
extern s32 func_088D72A4(char *, u16, s16, s32);
extern void func_088D8900(char *);
extern u8 func_08830728(char *, s8, s16, s16);
extern void func_09AB0928(char *, char *);
extern void func_09AB0B10(char *, char *);
extern void func_09AB0E60(char *, char *, char *);
extern void func_09AB0EF8(char *, char *);
extern void func_09AB0FD0(char *, char *, char *);
extern void func_09AB1278(char *, char *, s32);
extern void func_09AB1190(char *, char *);
extern void func_0889BCB4(char *, char *);
extern void func_09C267D0(s32, char *);
extern int func_09C26678(s32);
extern void func_08858840(char *, s32, s32);
extern char *func_09A7B790(s32, u16);
extern int func_0880E8F0(char *, char *, ...);
extern void func_08830850(char *, char *);
extern void func_09C27B30(s32, char *, char *);
extern void func_0889D608(char *);
extern void func_0889D6EC(char *);
extern void memcpy(void *, void *, s32);
extern void memset(void *, s32, s32);

}

static inline s32 cmp_id(u8 *a, u8 *b) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (a[i] < b[i]) {
            return -1;
        }
        if (b[i] < a[i]) {
            return 1;
        }
    }
    return 0;
}

typedef struct {
    char pad0[0x5CE];
    u8 id[6];
} Self;

static inline s32 cmp_self(Self *q, u8 *b) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (q->id[(unsigned int) i] < b[i]) {
            return -1;
        }
        if (b[i] < q->id[(unsigned int) i]) {
            return 1;
        }
    }
    return 0;
}

typedef struct {
    u8 kind;
    u8 unk1;
    char pad2[0xE];
    s16 unk10;
    char pad12[0x5E];
} Quest;

static inline char *find_peer(u8 *id) {
    char *tbl = (char *) D_09A0FDC4;
    s32 i;

    if (id != 0) {
        for (i = 0; i < 4; i++) {
            if (cmp_id(id, (u8 *) (tbl + i * 8 + 0x50)) == 0) {
                return func_088DCEBC(D_09A4F0C4, i);
            }
        }
    }
    return 0;
}

extern "C" void func_0889B1A4(Rec *arg0) {
    Rec t;
    char buf[0x324];
    s32 v0[3];
    s32 v1[2];
    s32 v2[3];
    s32 v2b[2];
    s32 v3[2];
    s32 v4[3];
    s32 v7;
    s32 v17;
    char str[0x80];
    char *p;
    char *m;
    char *q;
    char *obj;
    s32 flags;
    s32 idx;
    s32 off;
    char *fmt;
    u8 mode;
    s16 neg;

    t.a = arg0->a;
    t.b = arg0->b;
    flags = *(s32 *) (D_089CC438 + 0x6AF14);
    if ((bool) (flags & 1) == 0 && (bool) (flags & 0x80) == 0) {
        return;
    }
    p = *(char **) &t.a.v[2];
    func_088B09A4(buf);
    m = buf + 0x20;
    if (func_0880BFF0(m + 4, func_0889C518(p), 6) != 0 &&
        func_0880BFF0(m + 4, D_089B16DC, 6) != 0) {
        return;
    }
    switch (*(s32 *) m) {
    case 0:
        if (*(u8 *) D_09A5242C != 0) {
            break;
        }
        mode = *(u8 *) (p + 0x12D5);
        if (mode == 4) {
            break;
        }
        if (mode == 5) {
            break;
        }
        v0[0] = func_088FC810((char *) D_09A5242C, buf, m + 0xC, m + 0x14,
                              *(s32 *) (m + 0x2F8), *(s32 *) (m + 0x2F4), 0, 0);
        v0[2] = *(s32 *) (m + 0x2F8);
        v0[1] = *(s32 *) (m + 0x2F4);
        func_0889D8A8(p, buf, 1, v0);
        break;
    case 1:
        if (*(s32 *) (m + 0x14) != 5) {
            v1[0] = *(s32 *) (m + 0x14) + 1;
            v1[1] = *(s32 *) (m + 0x10);
            func_0889D8A8(D_09A0B544, buf, 0, v1);
        } else {
            func_088FC724((char *) D_09A5242C, buf, *(s32 *) (m + 0xC));
        }
        break;
    case 2:
    case 16:
        if (*(u8 *) D_09A5242C != 0) {
            break;
        }
        mode = *(u8 *) (p + 0x12D5);
        if (mode == 4) {
            break;
        }
        if (mode == 5) {
            break;
        }
        v2[0] = func_088FC810((char *) D_09A5242C, buf, m + 0xC, m + 0x14,
                              *(s32 *) (m + 0x2F8), *(s32 *) (m + 0x2F4), 1,
                              *(s32 *) m == 16);
        v2[2] = *(s32 *) (m + 0x2F8);
        v2[1] = *(s32 *) (m + 0x2F4);
        func_0889D8A8(p, buf, 3, v2);
        if (*(s32 *) m != 2) {
            break;
        }
        if (*(s32 *) (m + 0x2F8) != 0) {
            break;
        }
        v2b[0] = 0;
        v2b[1] = (u16) func_088900C4(D_08A631A0, 1);
        func_0889D8A8(D_09A0B544, buf, 0x10, v2b);
        break;
    case 3:
        if (*(s32 *) (m + 0x14) != 5) {
            v3[0] = *(s32 *) (m + 0x14) + 1;
            v3[1] = *(s32 *) (m + 0x10);
            func_0889D8A8(p, buf, 2, v3);
        } else {
            func_088FC724((char *) D_09A5242C, buf, *(s32 *) (m + 0xC));
        }
        break;
    case 4:
        v4[0] = *(s32 *) (m + 0xC);
        v4[1] = (s32) (D_08A5C440 + v4[0] * 0x2E0);
        if (v4[0] < 0x24) {
            v4[2] = 0x2E0;
        } else {
            v4[2] = 0x80;
        }
        func_0889D8A8(p, buf, 5, v4);
        break;
    case 5:
        if (*(u8 *) (p + 0x1B0C) == 0) {
            break;
        }
        if (*(u8 *) (p + 0x1B00) == 0) {
            break;
        }
        memcpy(*(char **) (p + 0x1B04) + *(s8 *) (m + 0xC) * 0x2E0, m + 0x1C,
               *(s32 *) (m + 0x10));
        *(u8 *) (p + 0x1B0C) = 0;
        break;
    case 6:
        q = func_088DCEBC(D_09A4F0C4, 0);
        *(u16 *) (q + 0x5CA) = *(u16 *) (m + 0xC);
        *(s16 *) (q + 0x5CC) = *(s16 *) (m + 0xE);
        func_09AAEE70(q, 0, 5, 0x10);
        break;
    case 7:
        q = func_088DCEBC(D_09A4F0C4, 0);
        if (cmp_self((Self *) q, (u8 *) buf) == 0 &&
            *(u16 *) (q + 0x5CA) == *(u16 *) (m + 0xC) &&
            *(s16 *) (q + 0x5CC) == *(s16 *) (m + 0xE) &&
            func_088568AC(D_089CC438, *(u16 *) (m + 0xC)) >= *(s16 *) (m + 0xE) &&
            *(u8 *) (q + 0x5C8) == 0) {
            func_088D72A4(q, *(u16 *) (q + 0x5CA), -*(s16 *) (q + 0x5CC), 0);
            func_088D8900(q);
            v7 = 0;
            func_0889D8A8(p, buf, 8, &v7);
            *(u8 *) (q + 0x5C8) = 0xFF;
        } else {
            v7 = 1;
            func_0889D8A8(p, buf, 8, &v7);
        }
        memset(q + 0x5CE, 0, 8);
        *(u16 *) (q + 0x5CA) = 0;
        *(s16 *) (q + 0x5CC) = 0;
        func_0889D608(D_09A0B544);
        func_0889D6EC(D_09A0B544);
        break;
    case 8:
        q = func_088DCEBC(D_09A4F0C4, 0);
        if (*(s32 *) (m + 0x10) == 0) {
            *(u8 *) (q + 0x5C8) = 1;
            func_088D72A4(q, *(u16 *) (m + 0xC), *(s16 *) (m + 0xE), 0);
            func_088D8900(q);
            func_08830728(D_089CBBEC, 1, 0xD, *(s16 *) (m + 0xC));
        } else {
            *(u8 *) (q + 0x5C8) = 2;
        }
        break;
    case 9:
        q = find_peer((u8 *) buf);
        if (q != 0) {
            func_09AB0928(q, m);
        }
        break;
    case 10:
        q = find_peer((u8 *) buf);
        if (q != 0) {
            func_09AB0B10(q, m);
        }
        break;
    case 11:
        q = func_088DCEBC(D_09A4F0C4, 0);
        if (q != 0) {
            func_09AB0E60(q, buf, m);
        }
        break;
    case 12:
        q = func_088DCEBC(D_09A4F0C4, 0);
        if (q != 0) {
            func_09AB0EF8(q, m);
        }
        break;
    case 13:
        q = func_088DCEBC(D_09A4F0C4, 0);
        if (q != 0) {
            func_09AB0FD0(q, buf, m);
        }
        break;
    case 14:
        q = func_088DCEBC(D_09A4F0C4, 0);
        if (q != 0) {
            func_09AB1278(q, buf, 1);
        }
        break;
    case 15:
        q = find_peer((u8 *) buf);
        if (q != 0) {
            func_09AB1190(q, m);
        }
        break;
    case 17:
        q = func_088DCEBC(D_09A4F0C4, 0);
        if (cmp_self((Self *) q, (u8 *) buf) == 0 &&
            func_0880BFF0(q + 0x5DC, m + 0xC, 0x10) == 0 &&
            *(u8 *) (q + 0x5C8) == 0) {
            v17 = 0;
            func_0889D8A8(p, buf, 0x12, &v17);
            *(u8 *) (q + 0x5C8) = 0xFF;
        } else {
            v17 = 1;
            func_0889D8A8(p, buf, 0x12, &v17);
        }
        memset(q + 0x5CE, 0, 8);
        *(u16 *) (q + 0x5CA) = 0;
        *(s16 *) (q + 0x5CC) = 0;
        func_0889D608(D_09A0B544);
        func_0889D6EC(D_09A0B544);
        break;
    case 18:
        q = func_088DCEBC(D_09A4F0C4, 0);
        if (*(s32 *) (m + 0x90) == 0) {
            *(u8 *) (q + 0x5C8) = 1;
            idx = *(u8 *) (q + 0x5D8);
            obj = (char *) D_09CFBBC8;
            if (idx < 0xD) {
                off = idx * 0x70;
                func_0889BCB4(D_089CC438 + off + 0x69BEC, m + 0xC);
                if (idx < 3) {
                    ((Quest *) (D_089CC438 + 0x69BEC))[idx].kind = 8;
                } else {
                    ((Quest *) (D_089CC438 + 0x69BEC))[idx].kind = 4;
                }
                ((Quest *) (D_089CC438 + 0x69BEC))[idx].unk10 = 0;
                (D_089CC438 + 0x6A19D)[idx] = 0;
                func_09C267D0((s32) obj, m + 0xC);
                func_09C26678((s32) obj);
            }
            func_08858840(D_089CC438, 3, *(u8 *) (m + 0xD));
            fmt = func_09A7B790(D_09B22D70, D_09B05D0A);
            func_0880E8F0(str, fmt,
                          func_09A7B790(D_09B22D70, D_09B05300[*(u8 *) (D_089CC438 + *(s32 *) (q + 0x5D8) * 0x70 + 0x69BED)]));
            func_08830850(D_089CBBEC, str);
            func_09C27B30(D_09CFBBC8, m + 0xC, m + 0x7C);
        } else {
            *(u8 *) (q + 0x5C8) = 2;
        }
        break;
    }
}
