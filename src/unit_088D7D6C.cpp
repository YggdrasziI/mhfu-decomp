/* unit_088D7D6C: 0x088D7D6C-0x088D8000 (ULES01213)
 *
 * Bounds (hypothesis): 3 functions between func_088D7AD8, still in assembly
 * (text_088D7AD8), and unit_088D8000.
 *
 * func_088D7D6C returns a bit mask for an object in state 1 (+0x5F3): the
 * word at D_08960BB4 of its 0x1C-byte record (index at +0x4EA), plus the
 * bits of func_088D7F34 for kind 10 (+0x1E8) or of func_088D7DE8 otherwise.
 * Both build their bits from func_088D6A1C tests (ids 0xC3-0xC7, 0x3A-0x42).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Rec {
    s32 unk0;
    char pad4[0x18];
} Rec;

extern "C" {

extern Rec D_08960BB4[];

extern u8 func_088D6A1C(char *, s32);
s32 func_088D7DE8(char *arg0);
s32 func_088D7F34(char *arg0);

s32 func_088D7D6C(char *arg0) {
    s32 mask;

    if (*(u8 *)(arg0 + 0x5F3) != 1) {
        return 0;
    }
    mask = D_08960BB4[*(u16 *)(arg0 + 0x4EA)].unk0;
    if (*(u8 *)(arg0 + 0x1E8) == 0xA) {
        return mask | func_088D7F34(arg0);
    }
    return mask | func_088D7DE8(arg0);
}

s32 func_088D7DE8(char *arg0) {
    s32 mask = 0;

    if (func_088D6A1C(arg0, 0x3A) == 1) {
        mask |= 7;
    }
    if (func_088D6A1C(arg0, 0x3B) == 1) {
        mask |= 8;
    } else if (func_088D6A1C(arg0, 0x3C) == 1) {
        mask |= 0x38;
    }
    if (func_088D6A1C(arg0, 0x3D) == 1) {
        mask |= 0x40;
    } else if (func_088D6A1C(arg0, 0x3E) == 1) {
        mask |= 0x1C0;
    }
    if (func_088D6A1C(arg0, 0x3F) == 1) {
        mask |= 0x200;
    } else if (func_088D6A1C(arg0, 0x40) == 1) {
        mask |= 0xE00;
    }
    if (func_088D6A1C(arg0, 0x41) == 1) {
        mask |= 0x1000;
    } else if (func_088D6A1C(arg0, 0x42) == 1) {
        mask |= 0x7000;
    }
    return mask;
}

s32 func_088D7F34(char *arg0) {
    s32 mask = 0;

    if (func_088D6A1C(arg0, 0xC3) == 1) {
        mask |= 4;
    }
    if (func_088D6A1C(arg0, 0xC4) == 1) {
        mask |= 8;
    }
    if (func_088D6A1C(arg0, 0xC5) == 1) {
        mask |= 0x10;
    }
    if (func_088D6A1C(arg0, 0xC6) == 1) {
        mask |= 2;
    }
    if (func_088D6A1C(arg0, 0xC7) == 1) {
        mask |= 0x20;
    }
    return mask;
}

}
