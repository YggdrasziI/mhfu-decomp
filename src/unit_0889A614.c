/* unit_0889A614: 0x0889A614-0x0889A700 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;

typedef struct {
    s32 unk0;
    s32 unk4;
    char *unk8;
    s8 unkC;
    s8 padD[3];
    u16 unk10;
    u16 pad12;
} Arg_0889A614;

extern void func_0889CF34(char *, s32);
extern void func_0889D244(char *, s32);
extern void func_088B3A3C(void *);
extern void func_0889D318(char *, void *);
extern void func_0889CA88(char *, void *);
extern void func_0889D008(char *, u8);
extern void func_0889D6EC(char *);

void func_0889A614(Arg_0889A614 *arg0) {
    Arg_0889A614 a;
    char buf78[0x64];
    char buf14[0x64];
    char *p;

    a = *arg0;
    p = a.unk8;
    *(s32 *)(p + 0x12C0) &= ~0x80;
    *(u8 *)(p + 0x1AF4) = (a.unkC == 0);
    *(s32 *)(p + 0x1AF8) = a.unk10;
    if (*(u8 *)(p + 0x1AF4) != 0) {
        func_0889CF34(p, 3);
        func_0889D244(p, 1);
        func_088B3A3C(buf78);
        func_0889D318(p, buf78);
        func_088B3A3C(buf14);
        func_0889CA88(p, buf14);
        func_0889D008(p, *(u8 *)(buf14 + 0x5D));
        func_0889D6EC(p);
    } else if (*(s32 *)(p + 0x1AF8) == 0x8003) {
        *(u8 *)(p + 0x1AFC) = 1;
    }
}
