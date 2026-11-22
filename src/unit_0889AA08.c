/* unit_0889AA08: 0x0889AA08-0x0889AACC (ULES01213) */

typedef int s32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed char s8;

typedef struct {
    s32 unk0;
    s32 unk4;
    char *unk8;
} ArgA;

typedef struct {
    s32 unk0;
    s32 unk4;
} ArgB;

typedef struct {
    ArgA a;
    ArgB b;
} Arg;

extern void func_0889CF34(char *arg0, s32 arg1);
extern void func_0889D6EC(char *arg0);

void func_0889AA08(Arg *arg0) {
    Arg loc;
    char *obj;

    loc.a = arg0->a;
    loc.b = arg0->b;
    obj = loc.a.unk8;
    *(s32 *) (obj + 0x12C0) &= ~0x800;
    *(u8 *) (obj + 0x1AF4) = (s8) loc.b.unk0 == 0;
    *(s32 *) (obj + 0x1AF8) = (u16) loc.b.unk4;
    if (*(u8 *) (obj + 0x1AF4)) {
        func_0889CF34(obj, 4);
        func_0889D6EC(obj);
    } else {
        s32 v = *(s32 *) (obj + 0x1AF8);

        if (v == 0x8003 || v == 0x8007 || v == 0x8001) {
            *(u8 *) (obj + 0x1AFC) = 1;
        }
    }
}
