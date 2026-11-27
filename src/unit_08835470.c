/* unit_08835470: 0x08835470-0x08835F7C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
#pragma opt_propagation off


typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 c[4];
} Rgb;

extern char *D_089CC438;
extern char *D_08A631A0;
extern char *D_08A631A8;
extern s32 D_09A4F0C4;
extern u8 *D_09A0B544;
extern char *D_089CBBE4;
extern char *D_089CBBE8;
extern char *D_089CBBEC;
extern u16 D_0893AE68[];
extern s32 D_09B22D70;
extern s32 D_09B23820;
typedef struct {
    s16 a;
    s16 b;
    s16 w;
    s16 h;
} Sz;

extern Sz D_08939838;
extern Sz D_0893982C;
extern Rgb D_0893AF74[];

extern void func_08890E08(char *, s8);
extern void func_08825DA8(char *);
extern void func_08890DE8(char *, s8, u8);
extern void func_08890E38(char *, s8);
extern char *func_088DCEBC(s32, s32);
extern s32 func_0883B498(char *, u16);
extern void func_08814674(char *, float *, float *);
extern s32 func_088167F4(char *, char *);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_088912BC(char *, s16, s16, char *);
extern s32 func_09A7BFA8(s32);
extern char *func_088298E4(char *);
extern s8 func_09A884C8(s32, char *);
extern u8 func_0889E1BC(u8 *, s32);
extern void func_0882B624(char *, s32, s32, u8, u8, u8, s32, s32);

static inline void mtx_identity(float *m) {
    asm {
        vmidt.q E000
        sv.q C000, 0(m)
        sv.q C010, 0x10(m)
        sv.q C020, 0x20(m)
        sv.q C030, 0x30(m)
    }
}

static inline void put_icon(Sz *p, Rgb *c, float *out, s32 h, s32 k) {
    func_0882B624(D_089CBBEC, (u32)(out[0] - (float)(p->w >> 1)), (u32)(out[1] - (float)h),
                  c->c[0], c->c[1], c->c[2], k, 0);
}

void func_08835470(char *arg0, s32 arg1) {
    float mtx[16];
    float in[4];
    float out[4];
    s32 h;
    char *name;
    s32 i;
    char *e;
    u8 kind;
    u8 *rec;
    s16 w;
    Rgb *c;
    u8 k;
    Sz *p;

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
    h = 0x10;
    func_08890DE8(D_08A631A8, h, 0xE);
    i = 0;
    do {
        e = func_088DCEBC(D_09A4F0C4, i);
        if (e == 0) continue;
        if ((s32)((*(s32 *)(e + 4) & 1) != 0) == 0) continue;
        if ((s32)((*(s32 *)(e + 4) & 4) != 0) == 1) continue;
        if ((s32)((*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) == 0) {
            kind = D_089CC438[0x44BC];
            name = D_089CC438 + 0x4A0;
        } else {
            if (func_0883B498(arg0, *(u16 *)(e + 0x1E6)) == -1) continue;
            rec = D_09A0B544 + (u8)func_0883B498(arg0, *(u16 *)(e + 0x1E6)) * 200;
            name = (char *)(s32)(rec + 0x57C) + 8;
            kind = rec[0x604];
        }
        mtx_identity(mtx);
        in[0] = *(float *)(e + 0x200);
        in[1] = *(float *)(e + 0x204) + 190.0f;
        in[2] = *(float *)(e + 0x208);
        in[3] = 1.0f;
        func_08814674(D_089CBBE4, out, in);
        if (out[0] >= 700.0f) continue;
        if (out[0] <= -60.0f) continue;
        if (out[1] >= 500.0f) continue;
        if (out[1] <= -20.0f) continue;
        if (out[3] <= 0.0f) continue;
        w = (func_088167F4(D_089CBBE8, name) << 4) >> 2;
        func_0882A9DC(arg0, (u16)(u32)out[0] - w - 14, (u16)(u32)out[1] - 2,
                      D_0893AE68[*(u8 *)(e + 0x1E8)]);
        func_08890E38(D_08A631A8, 1);
        func_088912BC(D_08A631A8, (u16)(u32)out[0] - w + 1, (u16)(u32)out[1] + 1, name);
        switch (kind) {
        case 0:
            func_08890E38(D_08A631A8, 5);
            break;
        case 1:
            func_08890E38(D_08A631A8, 6);
            break;
        case 2:
        case 3:
            func_08890E38(D_08A631A8, 7);
            break;
        case 4:
        case 5:
            func_08890E38(D_08A631A8, 2);
            break;
        case 6:
        case 7:
            func_08890E38(D_08A631A8, 0x18);
            break;
        case 8:
            func_08890E38(D_08A631A8, 0x17);
            break;
        }
        func_088912BC(D_08A631A8, (u16)(u32)out[0] - w, (u32)out[1], name);
        if ((s32)((*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) == 0) {
            if ((u8)func_09A7BFA8(D_09B22D70) == 1) {
                p = &D_08939838;
                put_icon(p, &D_0893AF74[func_09A884C8(D_09B23820, func_088298E4(arg0))], out, h, 0x8C);
            }
        } else {
            k = D_09A0B544[(u8)func_0883B498(arg0, *(u16 *)(e + 0x1E6)) * 200 + 0x63B];
            if (k == 3) {
                c = &D_0893AF74[func_0889E1BC(D_09A0B544, func_0883B498(arg0, *(u16 *)(e + 0x1E6)))];
                if ((s32)(D_09A0B544[(u8)func_0883B498(arg0, *(u16 *)(e + 0x1E6)) * 200 + 0x63A] != 0) == 1) {
                    p = &D_08939838;
                    put_icon(p, c, out, h, 0x8C);
                } else {
                    p = &D_0893982C;
                    put_icon(p, c, out, h, 0x8B);
                }
            } else if (k == 4) {
                c = &D_0893AF74[func_0889E1BC(D_09A0B544, func_0883B498(arg0, *(u16 *)(e + 0x1E6)))];
                if ((s32)(D_09A0B544[(u8)func_0883B498(arg0, *(u16 *)(e + 0x1E6)) * 200 + 0x63A] != 0) == 1) {
                    p = &D_08939838;
                    put_icon(p, c, out, h, 0x8C);
                } else if (*(s32 *)(D_08A631A0 + 0xF7A554) & 0x10) {
                    p = &D_0893982C;
                    put_icon(p, c, out, h, 0x8B);
                }
            }
        }
    } while (++i < 4);
}
