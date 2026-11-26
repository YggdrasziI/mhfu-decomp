/* unit_0882675C: 0x0882675C-0x088268E0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

typedef struct Pair {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
} Pair;

extern char *D_089CC438;
extern s32 D_08A62D8C;
extern Pair *func_08856884(char *, s32);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_0882675C(char *arg0, u16 arg1) {
    Pair *tbl;
    u8 max;
    u8 cur;
    s16 r;

    tbl = func_08856884(D_089CC438, 0);
    max = tbl[*(u8 *)(arg0 + 0x586)].unk2;
    *(u8 *)(arg0 + 0x58B) = 0;
    cur = *(u8 *)(arg0 + 0x58A);
    r = cur;
    if (arg1 & 0x80) {
        if (cur < 2) {
            r = -1;
        }
        *(u8 *)(arg0 + 0x58A) = 1;
    } else if (arg1 & 0x20) {
        if (cur >= max) {
            r = -1;
        }
        *(u8 *)(arg0 + 0x58A) = max;
    } else if (arg1 & 0x10) {
        if (cur >= max) {
            *(u8 *)(arg0 + 0x58A) = max;
            r = -1;
        } else {
            *(u8 *)(arg0 + 0x58A) = cur + 1;
        }
    } else if (arg1 & 0x40) {
        if (cur > 1) {
            *(u8 *)(arg0 + 0x58A) = cur - 1;
        } else {
            r = -1;
        }
    }
    if (r < 0) {
        func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
    } else if (r != *(u8 *)(arg0 + 0x58A)) {
        func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
    }
    if (*(u8 *)(arg0 + 0x58A) >= max) {
        *(u8 *)(arg0 + 0x58B) = 1;
    }
}
