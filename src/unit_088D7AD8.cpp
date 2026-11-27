/* unit_088D7AD8: 0x088D7AD8-0x088D7D6C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088D777C and unit_088D7D6C.
 *
 * Steps the pair index `arg1` (mode `arg2`: 0 next, 1 previous, 2 next after
 * the test, 3 previous after the test) through the 24 or 25 pairs until one
 * holds an id whose record (D_0899D198) fits the object's kind and the mask
 * of func_088D7D6C; returns the index or 0xFF.
 *
 * Speed setting; the `idx` local also takes the copy of `arg1` for the
 * range test, and the search loop is a plain `for`: together they give the
 * saved registers of the index, mode and count (none alone does).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Pair {
    u16 unk0;
    s16 unk2;
} Pair;

typedef struct Info {
    u8 unk0;
    u8 unk1;
    char pad2[6];
    s16 unk8;
    char padA[0xE];
} Info;

#pragma optimize_for_size off
extern "C" {

extern char *D_089CC438;
extern Info D_0899D198[];

extern Pair *func_08856884(char *, s32);
extern s32 func_088D7D6C(char *);

static inline bool is_own(char *obj) {
    return *(u16 *)(obj + 0x1E6) == *(u8 *)(D_089CC438 + 0x28);
}

u16 func_088D7AD8(char *arg0, u16 arg1, u8 arg2) {
    s16 n;
    s16 i;
    s32 idx;
    s32 mask;
    s32 flag;
    s32 id;
    Info *info;

    if (is_own(arg0) == 0) {
        return 0xFF;
    }
    if (*(u8 *)(arg0 + 0x5F3) != 1) {
        return 0xFF;
    }
    if (*(u8 *)(arg0 + 0x4E9) != 6) {
        return 0xFF;
    }
    if (*(u8 *)(arg0 + 0x1E8) == 0xA) {
        n = 0x19;
    } else {
        n = 0x18;
    }
    idx = arg1;
    if (idx >= n) {
        arg1 = 0;
    }
    switch (arg2) {
    case 0:
        arg1 = (arg1 + 1) % n;
        break;
    case 1:
        if (arg1 == 0) {
            arg1 = n - 1;
        } else {
            arg1--;
        }
        break;
    case 2:
    case 3:
        break;
    }
    mask = func_088D7D6C(arg0);
    if (*(u8 *)(arg0 + 0x1E8) == 0xA) {
        flag = 4;
    } else {
        flag = 2;
    }
    for (i = 0; i < n; i++) {
        idx = arg1;
        if (func_08856884(D_089CC438, idx)->unk0 != 0 && func_08856884(D_089CC438, idx)->unk2 > 0) {
            id = func_08856884(D_089CC438, idx)->unk0;
            info = &D_0899D198[id];
            if (flag & info->unk1) {
                if (flag == 4 && id == 0x80) {
                    return arg1;
                }
                if (mask & (1 << info->unk8)) {
                    return arg1;
                }
            }
        }
        switch (arg2) {
        case 0:
        case 2:
            arg1 = (idx + 1) % n;
            break;
        case 1:
        case 3:
            if (idx == 0) {
                arg1 = n - 1;
            } else {
                arg1--;
            }
            break;
        }
    }
    return 0xFF;
}

}
