/* unit_0889A828: 0x0889A828-0x0889A918 (ULES01213)
 *
 * The 0x14-byte argument record is copied to the stack as three then two
 * floats: a structure of an F3 and an F2, copied member by member.
 */

typedef int s32;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;

typedef struct { float v[3]; } F3;
typedef struct { float v[2]; } F2;
typedef struct { F3 a; F2 b; } Rec;

extern void memset(void *, s32, s32);
extern void func_088B3F60(char *, char *);
extern void func_0889C7B4(char *);

void func_0889A828(Rec *arg0) {
    Rec t;
    char *p;
    s8 c;

    t.a = arg0->a;
    t.b = arg0->b;
    p = *(char **) &t.a.v[2];
    c = *(s8 *) &t.b.v[0];
    *(s32 *) (p + 0x12C0) &= ~0x200;
    *(u8 *) (p + 0x1AF4) = c == 0;
    *(s32 *) (p + 0x1AF8) = *(u16 *) &t.b.v[1];
    if (*(s32 *) (p + 0x1AF8) == 0x8006 || *(s32 *) (p + 0x1AF8) == 0x8000) {
        *(s32 *) (p + 0x1AF8) = 0x8014;
    }
    if (*(s32 *) (p + 0x1AF8) == 0x8007) {
        *(s32 *) (p + 0x1AF8) = 0x8001;
    }
    if (*(u8 *) (p + 0x1AF4) != 0) {
        memset(p + 0x25C, 0, 0x320);
        func_088B3F60(p + 0xEE1, p + 0x25C);
        func_0889C7B4(p);
    } else if (*(s32 *) (p + 0x1AF8) == 0x8003) {
        *(u8 *) (p + 0x1AFC) = 1;
    }
}
