/* unit_0889A290: 0x0889A290-0x0889A32C (ULES01213)
 *
 * Callback taking a 0x14-byte result arg0 (copied member by member through
 * float registers): +0x8 is the object, +0xC a byte flag, +0x10 a 16-bit
 * value.
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

typedef struct {
    F3 p0;
    F2 p1;
} Result;

extern void func_0889CF34(char *arg0, s32 arg1);
extern void func_0889D6EC(char *arg0);

void func_0889A290(Result *arg0) {
    Result res;
    char *obj;

    res.p0 = arg0->p0;
    res.p1 = arg0->p1;
    obj = *(char **) &res.p0.c;

    *(s32 *) (obj + 0x12C0) &= ~8;
    *(u8 *) (obj + 0x1AF4) = *(s8 *) &res.p1.a == 0;
    *(s32 *) (obj + 0x1AF8) = *(u16 *) &res.p1.b;
    if (*(u8 *) (obj + 0x1AF4) != 0) {
        func_0889CF34(obj, 2);
        func_0889D6EC(obj);
    } else {
        *(u8 *) (obj + 0x1AFC) = 1;
    }
}
