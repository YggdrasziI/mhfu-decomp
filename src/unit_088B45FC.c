/* unit_088B45FC: 0x088B45FC-0x088B46EC (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088B45FC asm piece, 2 functions
 * between unit_088B45B0 and unit_088B46EC.
 *
 * func_088B45FC: callback copying the 0x14-byte result arg0 and moving the
 * record D_09A440BC to state 1 or 2 (as func_088B1C34). func_088B4670
 * dispatches the phase of the record D_09A440E4 (as func_088B3130).
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

extern char D_09A440BC[];
extern char D_09A440E4[];

extern void func_088B455C(Record *);
extern void func_088B45B0(Record *);
extern void func_088B46EC(Record *);
extern void func_088B4858(Record *);
extern void func_088B48A4(Record *);

void func_088B45FC(Result *arg0) {
    Result res;
    Record *r;

    res.p0 = arg0->p0;
    res.p1 = arg0->p1;
    r = (Record *) D_09A440BC;

    if (*(s8 *) &res.p1.a == 0) {
        r->unk23 = 1;
        func_088B455C(r);
    } else {
        r->unk23 = 2;
        r->unk26 = *(u16 *) &res.p1.b;
        func_088B45B0(r);
    }
}

void func_088B4670(void) {
    Record *p = (Record *) D_09A440E4;

    if (p->unk20 != 0) {
        switch (p->unk21) {
        case 0:
            func_088B46EC(p);
            break;
        case 1:
            func_088B4858(p);
            break;
        case 2:
            func_088B48A4(p);
            break;
        }
    }
}
