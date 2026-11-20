/* unit_088D81FC: 0x088D81FC-0x088D852C (ULES01213)
 *
 * Bounds (hypothesis): 2 functions between unit_088D81F0 and func_088D852C,
 * which is still in assembly (text_088D852C).
 *
 * func_088D81FC steps the pair index `arg1` forwards (`arg2` 0) or
 * backwards through the 24 pairs of func_08856884 to the next one whose
 * record (D_0899D198) has bit 0 of byte 1 set; 0 when there is none.
 * func_088D839C empties the pair `arg1` and, for record kinds 2 and 3,
 * moves or clears the object's selection (+0x686) that pointed to it.
 *
 * C++: bool conversion, an inline test of the object id against the global
 * one.
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
    char pad2[0x16];
} Info;

extern "C" {

extern char *D_089CC438;
extern Info D_0899D198[];

extern Pair *func_08856884(char *, s32);
extern u16 func_088D7AD8(char *, u16, u8);
extern void func_088D8000(char *);
extern void func_088D81F0(char *);

static inline bool is_own(char *obj) {
    return *(u16 *)(obj + 0x1E6) == *(u8 *)(D_089CC438 + 0x28);
}

u16 func_088D81FC(char *arg0, u16 arg1, u8 arg2) {
    s16 found;
    s16 n;
    s16 i;
    u16 id;

    if (is_own(arg0) == 0) {
        return 0;
    }
    if (arg1 >= 0x18) {
        return arg1;
    }
    found = 0;
    if (arg2 == 0) {
        n = 0;
        i = arg1;
        do {
            i++;
            if (i >= 0x18) {
                i = 0;
            }
            id = func_08856884(D_089CC438, i)->unk0;
            if (id != 0 && (D_0899D198[id].unk1 & 1)) {
                arg1 = i;
                found = 1;
                break;
            }
            n++;
        } while (n < 0x18);
    } else {
        n = 0;
        i = arg1;
        do {
            if (i == 0) {
                i = 0x17;
            } else {
                i--;
            }
            id = func_08856884(D_089CC438, i)->unk0;
            if (id != 0 && (D_0899D198[id].unk1 & 1)) {
                arg1 = i;
                found = 1;
                break;
            }
            n++;
        } while (n < 0x18);
    }
    if (found == 0) {
        arg1 = 0;
    }
    return arg1;
}

s32 func_088D839C(char *arg0, s16 arg1) {
    u16 id;
    u8 kind;

    if (is_own(arg0) == 0) {
        return 2;
    }
    if (arg1 >= 0x18) {
        return 2;
    }
    id = func_08856884(D_089CC438, arg1)->unk0;
    func_08856884(D_089CC438, arg1)->unk2 = 0;
    if (func_08856884(D_089CC438, arg1)->unk0 == 0) {
        return 0;
    }
    func_08856884(D_089CC438, arg1)->unk0 = 0;
    kind = D_0899D198[id].unk0;
    if (kind == 2) {
        if ((u8) func_088D7AD8(arg0, *(u16 *)(arg0 + 0x686), 1) == 0xFF) {
            if (*(u8 *)(arg0 + 0x1E8) != 9 && *(u8 *)(arg0 + 0x1E8) != 0xA) {
                *(u16 *)(arg0 + 0x686) = 0xFF;
                *(s16 *)(arg0 + 0x646) = 0;
                *(u8 *)(arg0 + 0x67D) = 0;
                *(u8 *)(arg0 + 0x67C) = 0;
            }
        } else if (arg1 == *(u16 *)(arg0 + 0x686)) {
            *(s16 *)(arg0 + 0x646) = 0;
            *(u8 *)(arg0 + 0x67D) = 0;
            *(u8 *)(arg0 + 0x67C) = 0;
        }
    } else if (kind == 3) {
        if (arg1 == *(u16 *)(arg0 + 0x686)) {
            func_088D81F0(arg0);
            *(u16 *)(arg0 + 0x686) = func_088D7AD8(arg0, 0x18, 2);
            func_088D8000(arg0);
        }
    }
    return 1;
}

}
