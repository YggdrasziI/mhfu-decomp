/* unit_088B1C34: 0x088B1C34-0x088B1CA8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B1C28 and unit_088B1CA8.
 *
 * Callback queued by func_088B1AE0: copies the 0x14-byte result arg0, then
 * moves the record at D_09A4410C to state 1 (func_088B1BF8) when its byte
 * at +0xC is clear, else to state 2 with the error code at +0x10
 * (func_088B1C28).
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
    char unk0[0x23];
    u8 unk23;
    char unk24[2];
    u16 unk26;
} Record;

extern char D_09A4410C[];

extern void func_088B1BF8(Record *);
extern void func_088B1C28(Record *);

void func_088B1C34(Result *arg0) {
    Result res;
    Record *r;

    res.p0 = arg0->p0;
    res.p1 = arg0->p1;
    r = (Record *) D_09A4410C;

    if (*(s8 *) &res.p1.a == 0) {
        r->unk23 = 1;
        func_088B1BF8(r);
    } else {
        r->unk23 = 2;
        r->unk26 = *(u16 *) &res.p1.b;
        func_088B1C28(r);
    }
}
