/* unit_08826FCC: 0x08826FCC-0x08827194 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

typedef struct Vec {
    s16 x;
    s16 y;
    s16 z;
} Vec;

typedef struct Ent {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 pad4[0xE];
} Ent;

extern u8 func_08827194(char *p, char *q, Ent *e, s32 d);
extern void func_088275B0(char *p, char *q, u8 i, char *r);

void func_08826FCC(char *p, char *q, char *r) {
    Ent *e;
    s32 n;
    s8 i;

    *(u8 *)(p + 0xE1C) = *(u8 *)(q + 0x4E8);
    *(u8 *)(p + 0xE1D) = *(u8 *)(q + 0x4E9);
    *(u16 *)(p + 0xE1E) = *(u16 *)(q + 0x4EA);
    *(u16 *)(p + 0xE20) = *(u16 *)(q + 0x4EC);
    *(Vec *)(p + 0xE22) = *(Vec *)(q + 0x4EE);
    if (r != 0) {
        e = (Ent *)(p + 0xA50);
        n = 0x36;
        for (i = 1; i < 100; i++) {
            if (i != 1) {
                e->unk3 = i;
                if (func_08827194(p, r, e, 0) == 1) {
                    n--;
                    e++;
                    if (n <= 0) {
                        break;
                    }
                }
            }
        }
        while (n > 0) {
            e->unk2 = 0;
            n--;
            e++;
        }
        if (*(u16 *)(p + 0xE1E) == 0) {
            *(u8 *)(p + 0xE1C) = *(u8 *)(r + 0x4E8);
            *(u8 *)(p + 0xE1D) = *(u8 *)(r + 0x4E9);
            *(u16 *)(p + 0xE1E) = *(u16 *)(r + 0x4EA);
            *(u16 *)(p + 0xE20) = *(u16 *)(r + 0x4EC);
            *(Vec *)(p + 0xE22) = *(Vec *)(r + 0x4EE);
        }
    }
    {
        Ent *f = (Ent *)(p + 0x684);
        s32 k;
        for (k = 0x36; k > 0; k--) {
            f->unk2 = 0;
            f++;
        }
    }
    for (i = 1; i < 100; i++) {
        func_088275B0(p, q, i, r);
    }
}
