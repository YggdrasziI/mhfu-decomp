/* unit_0889A700: 0x0889A700-0x0889A828 (ULES01213)
 *
 * Bounds (hypothesis): 1 function. func_0889A700: takes a 0x14-byte record
 * by value.
 */
#pragma optimize_for_size off

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    s32 unk0;
    s32 unk4;
    char *unk8;
    s8 unkC;
    u8 padD[3];
    u16 unk10;
} Arg_0889A700;

typedef struct {
    u8 pad[0x5D];
    u8 unk5D;
    u8 pad2[0x64 - 0x5E];
} Buf_0889A700;

extern void func_0889CF34(char *, s32);
extern void func_0889D244(char *, s32);
extern void func_088B3A3C(Buf_0889A700 *);
extern void func_0889D318(char *, Buf_0889A700 *);
extern void func_0889D008(char *, u8);
extern void func_0889D6EC(char *);

void func_0889A700(Arg_0889A700 arg) {
    char *p;
    Buf_0889A700 buf;

    p = arg.unk8;
    *(u32 *)(p + 0x12C0) &= ~0x100;
    *(u8 *)(p + 0x1AF4) = arg.unkC == 0;
    *(s32 *)(p + 0x1AF8) = arg.unk10;
    if (*(s32 *)(p + 0x1AF8) == 0x8006 || *(s32 *)(p + 0x1AF8) == 0x8031) {
        *(s32 *)(p + 0x1AF8) = 0x8014;
    }
    if (*(s32 *)(p + 0x1AF8) == 0x8007) {
        *(s32 *)(p + 0x1AF8) = 0x8001;
    }
    if (*(u8 *)(p + 0x1AF4)) {
        func_0889CF34(p, 3);
        func_0889D244(p, 0);
        func_088B3A3C(&buf);
        func_0889D318(p, &buf);
        func_0889D008(p, buf.unk5D);
        func_0889D6EC(p);
    } else if (*(s32 *)(p + 0x1AF8) == 0x8003) {
        *(u8 *)(p + 0x1AFC) = 1;
    } else if (*(s32 *)(p + 0x1AF8) == 0x8014) {
        *(u32 *)(p + 0x12C4) &= ~0x200;
    }
}
