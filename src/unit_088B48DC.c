/* unit_088B48DC: 0x088B48DC-0x088B4A14 (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088B48DC asm piece, 2 functions
 * between unit_088B48A4 and unit_088B4A14.
 *
 * func_088B48DC: callback queued by func_088B4738, copies the 0x14-byte
 * result arg0 and moves the record D_09A440E4 to state 1 or 2 (as
 * func_088B1C34). func_088B4950 reads the 0x14-byte identifier of the
 * buffer of func_088AFE78 into arg0 (zero when func_088B012C fails).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef float f32;

typedef struct {
    f32 a, b, c;
} F3;

typedef struct {
    f32 a, b;
} F2;

/* Copied one member at a time through float registers: +0xC is a byte,
 * +0x10 a 16-bit error code. */
typedef struct {
    F3 p0;
    F2 p1;
} Result;

typedef struct {
    char unk0[0x20];
    u8 unk20;
    u8 unk21;
    char unk22;
    u8 unk23;
    char unk24[2];
    u16 unk26;
} Record;

typedef struct {
    s8 b[0x14];
} Id;

extern char D_09A440E4[];

extern void func_0880C464(void *, s32, s32);
extern s32 func_088AFE78(void);
extern void func_088AFE90(s32, s32);
extern void func_088AFFD0(s32);
extern s32 func_088B012C(s32);
extern void func_088B01BC(s32, s32);
extern void func_088B4858(Record *);
extern void func_088B48A4(Record *);

void func_088B48DC(Result *arg0) {
    Result res;
    Record *r;

    res.p0 = arg0->p0;
    res.p1 = arg0->p1;
    r = (Record *) D_09A440E4;

    if (*(s8 *) &res.p1.a == 0) {
        r->unk23 = 1;
        func_088B4858(r);
    } else {
        r->unk23 = 2;
        r->unk26 = *(u16 *) &res.p1.b;
        func_088B48A4(r);
    }
}

void func_088B4950(Id *arg0) {
    s32 h;
    Id id;

    h = func_088AFE78();
    func_0880C464(&id, 0, sizeof(id));
    func_088B01BC(0, 0);
    func_088AFE90(h, 0xD);
    func_088AFFD0(h);
    if (func_088B012C(h) == 0) {
        id = *(Id *) (h + 4);
    }
    *arg0 = id;
}
