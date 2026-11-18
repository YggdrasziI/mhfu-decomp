/* unit_088AB980: 0x088AB980-0x088ABE58 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly and
 * unit_088ABE58. Its jump table is at 0x089320D0-0x089320F4.
 *
 * Handles a lobby message of type 7 (called from func_088AB35C): its
 * sub-type, read by func_088AB500, selects the update (member slots,
 * member objects) and the reply sent back through func_088AB6D0.
 *
 * NonMatching (96.96 %): only sub-type 1 differs. The original computes the
 * bit mask (`n % 32`) before the word index and keeps an `andi 0xFF` before
 * the `srl` of the index; ours hoists the index above the mask, without the
 * `andi` (`sra` or `srl`). Index forms, inline bitset helpers (C and C++)
 * and direct field reads do not change it. The jump table stays in the
 * assembly data while the function is not linked from this unit.
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    char unk0[4];
    u8 unk4;
    u8 unk5;
    char unk6[2];
    s32 unk8;
    s32 unkC;
} Msg;

typedef struct {
    u8 unk0;
    u8 unk1;
    char unk2[2];
    s32 unk4;
    s32 unk8;
} Slots;

extern char *D_089CC438;
extern char *D_089CBBEC;
extern char *D_08A62C7C;
extern s32 D_09A4F0C4;

extern void func_088AB500(u8 *, u8 *, char *);
extern void func_088AB6D0(s32, s32, void *);
extern char *func_088DCEBC(s32, s32);
extern s32 func_088D72A4(char *, s32, s32, s32);
extern void func_0884853C(char *, s32, s32);
extern s32 func_0884FA5C(char *, s32);
extern s32 func_08865CB8(char *, s32, s32);
extern s32 func_08872E2C(char *, s32);
extern void func_08872DF4(char *, s32, s32);
extern u8 func_08872E84(char *, s32);
extern void func_08872E48(char *, s32);
extern void func_08872EA0(char *, char *);
extern void func_09A6FE20(char *, s32);
extern void func_09A70068(char *);

void func_088AB980(s32 arg0, s32 arg1, Msg *msg) {
    u8 type;
    u8 sub;
    Slots slots;
    u8 b38[8];
    u8 b30[8];
    u8 b28[8];
    u8 b20[8];
    char *g;
    char *p;
    u32 *w;
    s32 mask;
    s32 n;
    s32 i;
    u8 *q;

    func_088AB500(&sub, &type, (char *) msg);
    switch (type) {
    case 0:
        break;
    case 1:
        g = D_089CC438;
        if (*(u8 *) (g + 0x420) == *(u8 *) (g + 0x28)) {
            slots.unk0 = arg1;
            n = msg->unk5;
            mask = 1 << (n % 32);
            w = (u32 *) (g + 0x410) + ((u8) n >> 5);
            if (*w & mask) {
                slots.unk1 = 0xFF;
            } else {
                slots.unk1 = n;
                *w |= mask;
            }
            slots.unk4 = *(s32 *) (D_089CC438 + 0x410);
            slots.unk8 = *(s32 *) (D_089CC438 + 0x414);
            func_088AB6D0(arg0, 2, &slots);
        }
        break;
    case 2:
        n = msg->unk5;
        if (n != 0xFF && *(u8 *) (D_089CC438 + 0x28) == msg->unk4) {
            p = func_088DCEBC(D_09A4F0C4, msg->unk4);
            *(s32 *) (p + 0x614) &= ~0x10000;
            arg0 = ((u16 *) (D_089CC438 + 0x390))[(u8) n * 2];
            func_088D72A4(p, arg0, ((s16 *) (D_089CC438 + 0x392))[(u8) n * 2], 0);
            func_0884853C(D_089CBBEC, arg0, n);
        } else {
            p = func_088DCEBC(D_09A4F0C4, msg->unk4);
            *(s16 *) (p + 0x5EC) = 1;
        }
        *(s32 *) (D_089CC438 + 0x410) = msg->unk8;
        *(s32 *) (D_089CC438 + 0x414) = msg->unkC;
        break;
    case 3:
        if (*(u8 *) (D_089CC438 + 0x420) == *(u8 *) (D_089CC438 + 0x28)) {
            b38[0] = arg1;
            n = msg->unk5;
            if ((u8) func_08872E2C(D_08A62C7C, n) == 1) {
                b38[1] = 0xFF;
            } else {
                b38[1] = n;
                func_08872DF4(D_08A62C7C, n, arg1);
            }
            i = 0;
            q = b38;
            do {
                q[2] = func_08872E84(D_08A62C7C, i);
                i++;
                q++;
            } while (i < 6);
            func_088AB6D0(arg0, 4, b38);
        }
        break;
    case 4:
        n = msg->unk5;
        if (n != 0xFF && *(u8 *) (D_089CC438 + 0x28) == msg->unk4) {
            p = func_088DCEBC(D_09A4F0C4, msg->unk4);
            if ((u8) func_08865CB8(p, 0, 0x7F) == 1) {
                func_09A6FE20(p, n);
            } else {
                b30[1] = n;
                func_088AB6D0(arg0, 5, b30);
                *(s16 *) (p + 0x5EC) = 0;
            }
        } else {
            *(s16 *) (func_088DCEBC(D_09A4F0C4, msg->unk4) + 0x5EC) = 0;
        }
        func_08872EA0(D_08A62C7C, (char *) msg + 6);
        break;
    case 5:
        if (*(u8 *) (D_089CC438 + 0x420) == *(u8 *) (D_089CC438 + 0x28)) {
            func_08872E48(D_08A62C7C, msg->unk5);
            i = 0;
            q = b28;
            do {
                q[2] = func_08872E84(D_08A62C7C, i);
                i++;
                q++;
            } while (i < 6);
            func_088AB6D0(arg0, 6, b28);
        }
        break;
    case 6:
        func_08872EA0(D_08A62C7C, (char *) msg + 6);
        break;
    case 7:
        if (*(u8 *) (D_089CC438 + 0x420) == *(u8 *) (D_089CC438 + 0x28)) {
            b20[0] = arg1;
            if ((u8) func_08872E2C(D_08A62C7C, 0) == 1) {
                b20[1] = 0xFF;
            } else if ((u8) func_0884FA5C(D_089CC438, 1) == 0) {
                b20[1] = 0;
                func_08872DF4(D_08A62C7C, 0, 0x7F);
            }
            i = 0;
            q = b20;
            do {
                q[2] = func_08872E84(D_08A62C7C, i);
                i++;
                q++;
            } while (i < 6);
            func_088AB6D0(arg0, 8, b20);
        }
        break;
    case 8:
        if (msg->unk5 != 0xFF && *(u8 *) (D_089CC438 + 0x28) == msg->unk4) {
            func_09A70068(func_088DCEBC(D_09A4F0C4, msg->unk4));
        }
        *(s16 *) (func_088DCEBC(D_09A4F0C4, msg->unk4) + 0x5EC) = 0;
        func_08872EA0(D_08A62C7C, (char *) msg + 6);
        break;
    }
}
