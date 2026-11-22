/* unit_0889D8A8: 0x0889D8A8-0x0889DF10 (ULES01213) */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

typedef struct {
    s8 a[18];
} A18;

typedef struct {
    s8 a[16];
} A16;

typedef struct {
    u8 a;
    u8 b;
    u8 c;
} B3;

typedef struct {
    s16 a;
    s16 b;
} S2;

typedef struct {
    f32 a;
    f32 b;
} F2;

typedef struct {
    s8 m00;
    u8 m01;
    s8 m02;
    s8 m03;
    s16 m04;
    s8 m06;
    B3 m07;
    B3 m0A;
    s8 m0D;
    s8 m0E;
    u8 m0F;
    u16 m10;
    S2 m12;
    u8 m16;
    f32 m18;
    f32 m1C;
    u16 m20;
    u16 m22;
    u8 m24;
    u8 m25;
    u16 m26;
    u8 m28;
    s8 m29;
    s16 m2A;
    u8 m2C;
    s32 m30;
    F2 m34;
    F2 m3C;
    B3 m44;
    B3 m47;
    u8 m4A;
    u8 m4B;
    u8 m4C;
    u8 m4D;
    A18 m4E;
    A16 m60;
} Elem;

typedef struct {
    f32 f0;
    f32 f4;
    u16 h8;
    u8 bA;
    u8 bB;
    u8 bC;
    u8 bD;
} RecH;

typedef struct {
    u8 hdr[8];
    u8 body[0x2E0];
    s32 b;
    s32 a;
} DataA;

typedef struct {
    Elem e;
    u8 x[0x12];
    s32 v;
} DataL;

typedef union {
    s32 w[0x2F4 / 4];
    u16 h[0x2F4 / 2];
    u8 b[0x2F4];
    RecH r;
    DataA da;
    DataL dl;
} Data;

typedef struct {
    u8 x[0x2E0];
} Row;

typedef struct {
    s32 type;
    u8 id[6];
    Data data;
    u16 size;
} Msg;

extern char *D_08A631A0;
extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern s32 D_09CFBBC8;
extern void memcpy(void *, void *, s32);
extern char *func_088DCEBC(s32, s32);
extern void func_088511B4(char *, char *);
extern void func_09C278F0(s32, void *, char *);
extern void func_088B099C(Msg *);
extern s32 func_088B09D0(u8 *, Msg *, s32, s32);

void func_0889D8A8(char *arg0, u8 *id, s32 type, s32 *p) {
    Msg m;
    Msg *mp;
    u16 size;
    char *r;
    s32 a;
    s32 b;
    u8 k;
    s32 i;
    s32 j;
    s32 c;
    u8 *ent;
    char *found;
    Elem *e;
    s32 *w;
    Elem *d;

    if ((u8)((*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) == 0) {
        return;
    }
    k = *(u8 *)(arg0 + 0x12D5);
    if (k == 0 || k == 1 || k == 5) {
        return;
    }
    mp = &m;
    switch (type) {
    case 0:
    case 2:
    case 16:
        a = p[0];
        b = p[1];
        size = 0x2FC;
        memcpy(mp->data.da.hdr, D_089CC438 + 0x679A0, 8);
        memcpy(mp->data.da.body, &((Row *)(D_089CC438 + 0x67758))[a], a != 5 ? 0x2E0 : 0x218);
        m.data.da.a = a;
        m.data.da.b = b;
        break;
    case 1:
    case 3:
        size = 0x18;
        m.data.w[0] = p[0];
        m.data.w[2] = p[2];
        m.data.w[1] = p[1];
        break;
    case 4:
        size = 0x10;
        m.data.w[0] = p[0];
        break;
    case 5:
        w = m.data.w;
        w[0] = p[0];
        w[1] = p[2];
        size = 0x2FC;
        memcpy(&mp->data.w[4], (void *)p[1], p[2]);
        break;
    case 6:
        r = func_088DCEBC(D_09A4F0C4, 0);
        size = 0x10;
        m.data.h[0] = *(u16 *)(r + 0x5CA);
        m.data.h[1] = *(s16 *)(r + 0x5CC);
        break;
    case 7:
        r = func_088DCEBC(D_09A4F0C4, 0);
        size = 0x10;
        m.data.h[0] = *(u16 *)(r + 0x5CA);
        m.data.h[1] = *(s16 *)(r + 0x5CC);
        break;
    case 8:
        r = func_088DCEBC(D_09A4F0C4, 0);
        size = 0x14;
        m.data.h[0] = *(u16 *)(r + 0x5CA);
        m.data.h[1] = *(s16 *)(r + 0x5CC);
        m.data.w[1] = p[0];
        break;
    case 9:
    case 10:
    case 15:
        size = 0x1C;
        m.data.r.f0 = ((RecH *)p)->f0;
        m.data.r.f4 = ((RecH *)p)->f4;
        m.data.r.h8 = ((RecH *)p)->h8;
        m.data.r.bA = ((RecH *)p)->bA;
        m.data.r.bB = ((RecH *)p)->bB;
        m.data.r.bC = ((RecH *)p)->bC;
        m.data.r.bD = ((RecH *)p)->bD;
        break;
    case 11:
    case 12:
    case 13:
        size = 0xE;
        m.data.b[0] = ((u8 *)p)[0];
        m.data.b[1] = ((u8 *)p)[1];
        break;
    case 14:
        size = 0xD;
        break;
    case 17:
        r = func_088DCEBC(D_09A4F0C4, 0);
        size = 0x1C;
        memcpy(mp->data.b, r + 0x5DC, 0x10);
        break;
    case 18:
        r = func_088DCEBC(D_09A4F0C4, 0);
        size = 0x94;
        e = (Elem *)(D_089CC438 + *(s32 *)(r + 0x5D8) * 0x70 + 0x69BEC);
        d = &m.data.dl.e;
        d->m00 = e->m00;
        d->m01 = e->m01;
        d->m02 = e->m02;
        d->m03 = e->m03;
        d->m04 = e->m04;
        d->m06 = e->m06;
        d->m07 = e->m07;
        d->m0A = e->m0A;
        d->m0D = e->m0D;
        d->m0E = e->m0E;
        d->m0F = e->m0F;
        d->m10 = e->m10;
        d->m12 = e->m12;
        d->m16 = e->m16;
        d->m18 = e->m18;
        d->m1C = e->m1C;
        d->m20 = e->m20;
        d->m22 = e->m22;
        d->m24 = e->m24;
        d->m25 = e->m25;
        d->m26 = e->m26;
        d->m28 = e->m28;
        d->m29 = e->m29;
        d->m2A = e->m2A;
        d->m2C = e->m2C;
        d->m30 = e->m30;
        d->m34 = e->m34;
        d->m3C = e->m3C;
        d->m44 = e->m44;
        d->m47 = e->m47;
        d->m4A = e->m4A;
        d->m4B = e->m4B;
        d->m4C = e->m4C;
        d->m4D = e->m4D;
        mp->data.dl.e.m4E = e->m4E;
        mp->data.dl.e.m60 = e->m60;
        d->m22 = 0;
        d->m22 = 0;
        d->m2A = 0;
        d->m00 = 0;
        d->m12.a = 0;
        d->m12.b = 0;
        d->m20 &= 0xFF55;
        d->m20 |= 0x55;
        d->m24 = 0;
        d->m25 = 0;
        d->m4A = 0;
        memcpy(mp->data.dl.x, D_089CC438 + 0x4A0, 0x12);
        if ((m.data.dl.v = p[0]) == 0) {
            func_088511B4(D_089CC438, D_089CC438 + *(s32 *)(r + 0x5D8) * 0x70 + 0x69BEC);
            for (i = 0; i < *(s8 *)(arg0 + 0xEE3); i++) {
                ent = (u8 *)(arg0 + i * 200 + 0x57C);
                for (j = 0; j < 6; j++) {
                    if ((u8)r[0x5CE + j] < ent[j]) {
                        c = -1;
                        goto done;
                    }
                    if (ent[j] < (u8)r[0x5CE + j]) {
                        c = 1;
                        goto done;
                    }
                }
                c = 0;
            done:
                if (c == 0) {
                    found = arg0 + i * 200 + 0x57C;
                    goto end;
                }
            }
            found = 0;
        end:
            func_09C278F0(D_09CFBBC8, mp->data.b, found + 8);
        }
        break;
    }
    m.type = type;
    if (id == 0) {
        m.id[0] = 0xFF;
        m.id[1] = 0xFF;
        m.id[2] = 0xFF;
        m.id[3] = 0xFF;
        m.id[4] = 0xFF;
        m.id[5] = 0xFF;
        m.size = size;
        func_088B099C(&m);
    } else {
        memcpy(mp->id, id, 6);
        m.size = size;
        func_088B09D0(id, &m, 0, 0);
    }
}
