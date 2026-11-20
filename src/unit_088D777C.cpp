/* unit_088D777C: 0x088D777C-0x088D7AD8 (ULES01213)
 *
 * Bounds (hypothesis): 2 functions between unit_088D773C and func_088D7AD8,
 * which is still in assembly (text_088D7AD8).
 *
 * func_088D777C removes `-arg2` of the id `arg1` from the object's own 24
 * pairs (+0x568), limited by what the pairs of func_088568AC hold beyond
 * them; it returns 1, 4 when the pair is emptied, 5 or 0xFF when nothing
 * is done. func_088D7904 moves up to `arg2` of the id `arg1` to one of the
 * four pairs at +0x542 (free one or the one holding the id), bounded by the
 * room found with func_0886E578 / func_0886E6F4, takes it out with
 * func_088D72A4 and returns the amount.
 *
 * C++: bool conversion, an inline test of the object id against the global
 * one. The id is an `int` masked where it is used, as in unit_088D773C.
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

extern "C" {

extern char *D_089CC438;
extern char *D_08A62C7C;
extern u8 D_0899D19B[];

extern s16 func_088568AC(char *, s32);
extern s16 func_0886C768(char *, s32, s32);
extern s16 func_0886E578(char *, s32, u16);
extern s16 func_0886E6F4(char *, s32);
extern s16 func_088D72A4(char *, s32, s16, u8);
extern s16 func_088D773C(char *, s32);

#define OWN(o) ((Pair *)((o) + 0x568))

static inline u8 get_max(u16 id) {
    return D_0899D19B[id * 0x18];
}

static inline bool is_own(char *obj) {
    return *(u16 *)(obj + 0x1E6) == *(u8 *)(D_089CC438 + 0x28);
}

s32 func_088D777C(char *arg0, s32 arg1, s16 arg2) {
    s32 ret;
    s32 i;
    u16 own;
    u16 all;
    s16 d;
    char *p;
    s16 *cnt;

    if (is_own(arg0) == 0) {
        return 0xFF;
    }
    if (arg2 > 0) {
        return 0xFF;
    }
    if (get_max(arg1) == 0xFF) {
        return 0xFF;
    }
    own = func_088D773C(arg0, arg1);
    all = func_088568AC(D_089CC438, arg1);
    if (own == 0 && all == 0) {
        return 0xFF;
    }
    if (own < all) {
        d = all - own;
        if (d >= -arg2) {
            return 5;
        }
        arg2 += d;
    }
    i = 0;
    p = arg0;
    do {
        if (*(u16 *)(p + 0x568) == (arg1 & 0xFFFF)) {
            cnt = (s16 *) &((Pair *)(arg0 + 0x56A))[i];
            *cnt += arg2;
            if (*cnt <= 0) {
                OWN(arg0)[i].unk0 = 0;
                *cnt = 0;
                ret = 4;
            } else {
                ret = 1;
            }
            break;
        }
        i++;
        p += 4;
    } while (i < 0x18);
    return ret;
}

u16 func_088D7904(char *arg0, s32 arg1, s16 arg2) {
    s16 best;
    s32 j;
    s32 i;
    s16 a;
    s16 d;
    char *p;

    best = 0;
    for (i = 0; i < 2; i++) {
        a = func_0886E578(D_08A62C7C, arg1, i);
        if (a >= 0) {
            d = a - func_0886E6F4(D_08A62C7C, arg1);
            if (best < d) {
                best = d;
            }
        }
    }
    if (best <= 0) {
        return 0;
    }
    if (func_0886C768(D_08A62C7C, arg1, 1) == 0) {
        j = 0;
        p = arg0;
        do {
            if (*(u16 *)(p + 0x542) == 0) {
                ((Pair *)(arg0 + 0x542))[j].unk0 = arg1;
                if (arg2 >= best) {
                    arg2 = best;
                }
                *(s16 *) &((Pair *)(arg0 + 0x544))[j] = (s8) arg2;
                func_088D72A4(arg0, arg1, -arg2, 0);
                return arg2;
            }
            j++;
            p += 4;
        } while (j < 4);
    } else {
        i = 0;
        p = arg0;
        do {
            if (*(u16 *)(p + 0x542) == (arg1 & 0xFFFF)) {
                if (arg2 >= best) {
                    arg2 = best;
                }
                ((Pair *)(arg0 + 0x542))[i].unk2 += (s8) arg2;
                func_088D72A4(arg0, arg1, -arg2, 0);
                return arg2;
            }
            i++;
            p += 4;
        } while (i < 4);
    }
    return arg2;
}

}
