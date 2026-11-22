/* unit_08873CC0: 0x08873CC0-0x08874124 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    u16 id;
    u16 flag;
} Slot;

typedef struct {
    u16 ids[26];
} Row;

typedef struct {
    u8 pad[0x5C];
    u8 b0 : 2;
    u8 b2 : 1;
    u8 b3 : 5;
    u8 pad2[0x1D0 - 0x5D];
} Ent;

typedef struct {
    u8 pad[4];
    u8 flags;
    u8 pad2[0x18 - 5];
} Item;

extern s32 D_09A0B540;
extern char *D_08A62C7C;
extern char *D_089CC438;
extern char *D_08A631A0;
extern u32 D_0893162C[];
extern u32 D_08931644[];
extern Ent D_09BB89B0[];
extern Row D_09CD8FB0[];
extern Item D_0899D198[];

extern u16 *func_08898694(s32, s32, s32);
extern void func_08898748(s32, s32);
extern char *func_08857C38(char *);
extern u16 func_0886D26C(char *, s32);
extern s32 func_088900C4(char *, s32);

void func_08873CC0(char *arg0) {
    u16 *buf;
    s32 v;
    s32 count;
    Slot *dst;
    s32 mode;
    u16 id;
    s32 i;
    s32 k;
    u16 item;
    u32 thr;
    s32 a;
    s32 b;
    u16 tmp;
    u8 rank;

    buf = func_08898694(D_09A0B540, 0x19, 0xB4);
    mode = *(s8 *)(*(char **)(D_08A62C7C + 0x4C) + 0x44);
    if (mode == 1) {
        mode = 0;
    } else if (mode == 2) {
        mode = 1;
    } else if (mode == 5) {
        mode = 2;
    }
    v = *(s16 *)(func_08857C38(D_089CC438) + 0x2A);
    if (v < 1000) {
        rank = 0;
    } else if (v < 2500) {
        rank = 1;
    } else if (v < 4500) {
        rank = 2;
    } else if (v < 6000) {
        rank = 3;
    } else if (v < 7000) {
        rank = 4;
    } else {
        rank = 5;
    }
    count = 0;
    for (i = 0; i < 0x5A; i++) {
        if (i > 0 && *(u8 *)(arg0 + i + 0x7CC) != 0) {
            Row *row = &D_09CD8FB0[i - 1];
            if (i == 2) {
                switch (mode) {
                case 1:
                    id = 0x430;
                    break;
                case 2:
                    id = 0x3EF;
                    break;
                default:
                    id = 0x3EF;
                    break;
                }
            } else if (i == 0x47) {
                switch (mode) {
                case 1:
                    id = 0x432;
                    break;
                case 2:
                    id = 0x3F1;
                    break;
                default:
                    id = 0x417;
                    break;
                }
            } else if (i == 0x24) {
                switch (mode) {
                case 1:
                    id = 0x431;
                    break;
                case 2:
                    id = 0x3F0;
                    break;
                default:
                    id = 0x3F0;
                    break;
                }
            } else {
                id = row->ids[mode];
            }
            if (id != 0xFFFF) {
                item = func_0886D26C(arg0, id & 0x7FFF);
                if (item != 0 && !(D_0899D198[item].flags & 6)) {
                    if (D_09BB89B0[i].b2) {
                        thr = D_0893162C[rank];
                    } else {
                        thr = D_08931644[rank];
                    }
                    if ((u16)func_088900C4(D_08A631A0, 0) % 100 < thr) {
                        buf[count] = item;
                        count++;
                    }
                }
            }
        }
    }
    for (i = 0; i < count; i++) {
        a = (u16)func_088900C4(D_08A631A0, 0) % count;
        b = (u16)func_088900C4(D_08A631A0, 0) % count;
        tmp = buf[a];
        buf[a] = buf[b];
        buf[b] = tmp;
    }
    if (count > 8) {
        count = 8;
    }
    dst = (Slot *)(D_089CC438 + 0x3B0);
    for (k = 0; k < count; k++) {
        dst->id = buf[k];
        dst->flag = 1;
        dst++;
    }
    func_08898748(D_09A0B540, 0x19);
    *(s8 *)(arg0 + 0x680) += (s8)count;
}
