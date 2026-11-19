/* unit_088CF210: 0x088CF210-0x088CF2C8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088CF1B0 and the asm piece
 * text_088CF2C8.
 *
 * Optimized for speed: the loop test is duplicated before the loop.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct Hdr {
    char pad[0x1C];
    u16 unk1C;
} Hdr;

extern void func_088CF2C8(char *, u8, u8);
extern void func_088D08D4(char *, u8, s32, u8);

void func_088CF210(char *arg0, u8 arg1) {
    u8 flag;
    Hdr **p;
    s32 i;

    flag = 0x10;
    switch (arg1) {
    case 0:
        flag |= 1;
        break;
    default:
        flag |= 2;
        break;
    }
    func_088CF2C8(arg0, arg1, flag);
    p = (Hdr **)(arg0 + 0xF60);
    for (i = 0; i < (*p)->unk1C; i++) {
        func_088D08D4(arg0, arg1, i, flag);
    }
}
