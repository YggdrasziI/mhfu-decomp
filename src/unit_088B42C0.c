/* unit_088B42C0: 0x088B42C0-0x088B4528 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B4274 and unit_088B4528.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 b[6];
} B6;

typedef struct {
    s8 b[0x42];
} B42;

typedef struct {
    s8 b[0x12];
} B12;

typedef struct {
    s8 b[8];
} B8;

typedef struct {
    B6 unk0;
    u8 unk6;
    u8 unk7;
    B42 unk8;
    u16 unk4A;
    u8 unk4C;
    u8 unk4D;
    s32 unk50;
    u8 unk54;
    u8 unk55;
    u8 unk56;
    u8 unk57;
    u16 unk58;
    u8 unk5A;
    u8 unk5B;
    B8 unk5C;
} Rec64;

typedef struct {
    B12 unk0;
    u16 unk12;
    u8 unk14;
    u8 unk15;
} Rec16;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 pad[0x11];
} Res14;

typedef struct {
    s16 unk0[0x18C];
} Blk318;

extern u8 D_09A28876;
extern Rec64 D_09A28B98;
extern Rec16 D_09A291BC;

extern char *func_088AFE78(void);
extern s32 func_088B6BC4(void);
extern void func_088B4E54(Res14 *, Rec64 *, Rec16 *, u16);
extern void func_088B7A50(s32);
extern char *func_088B6BFC(Res14 *, void (*)(s32), s32);
extern void func_088B45FC(s32);

static inline void copy_rec(Rec64 *d, Rec64 *s) {
    *(B6 *) d = *(B6 *) s;
    d->unk6 = s->unk6;
    d->unk7 = s->unk7;
    d->unk8 = s->unk8;
    d->unk4A = s->unk4A;
    d->unk4C = s->unk4C;
    d->unk4D = s->unk4D;
    d->unk50 = s->unk50;
    d->unk54 = s->unk54;
    d->unk55 = s->unk55;
    d->unk56 = s->unk56;
    d->unk57 = s->unk57;
    d->unk58 = s->unk58;
    d->unk5A = s->unk5A;
    d->unk5B = s->unk5B;
    d->unk5C = s->unk5C;
}

static inline void copy_key(Rec16 *d, Rec16 *s) {
    *(B12 *) d = *(B12 *) s;
    d->unk12 = s->unk12;
    *((u8 *) d + 0x14) = *((u8 *) s + 0x14);
    *((u8 *) d + 0x15) = *((u8 *) s + 0x15);
}

void func_088B42C0(u8 *arg0) {
    Res14 res;
    Rec64 rec;
    Rec16 key;
    char *src;
    char *dst;

    src = func_088AFE78();
    arg0[0x22]++;
    copy_rec(&rec, &D_09A28B98);
    copy_key(&key, &D_09A291BC);
    if (func_088B6BC4() != 0) {
        func_088B4E54(&res, &rec, &key, rec.unk58);
        if (res.unk2 != 0) {
            D_09A28876 = 0;
            func_088B7A50(1);
            dst = func_088B6BFC(&res, func_088B45FC, 0);
            dst[1] = 1;
            *(Blk318 *) (dst + 0x24) = *(Blk318 *) src;
        } else {
            *(u16 *) (arg0 + 0x26) = 0x8003;
            arg0[0x21] = 2;
            arg0[0x22] = 0;
        }
    } else {
        *(u16 *) (arg0 + 0x26) = 0x8002;
        arg0[0x21] = 2;
        arg0[0x22] = 0;
    }
}
