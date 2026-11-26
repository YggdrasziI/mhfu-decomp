/* unit_08828784: 0x08828784-0x08828884 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;

typedef struct Pair {
    s16 unk0;
    s16 unk2;
} Pair;

extern char *D_089CC438;
extern char *D_08A62C50;
extern Pair *func_08856884(char *, s32);
extern char *func_0885B5B8(char *, s32, s32, s32, s32, s32);
extern s32 func_0885B718(char *, char *, s32, s32);

s32 func_08828784(char *arg0, u8 arg1, u8 arg2) {
    s32 id;
    char *r;

    if (arg1 == 0xFF) {
        return 0;
    }
    if (arg2 == arg1) {
        return 0;
    }
    if (func_08856884(D_089CC438, arg1)->unk2 == 0) {
        return 0;
    }
    id = func_08856884(D_089CC438, arg2)->unk0;
    r = func_0885B5B8(D_08A62C50, id, func_08856884(D_089CC438, arg1)->unk0, 0, 0, 0);
    *(char **)(arg0 + 0x5A8) = r;
    if (r == 0) {
        return 0;
    }
    if (func_0885B718(D_08A62C50, r, 0, 0) != 0) {
        *(s16 *)(arg0 + 0x5B4) = (*(Pair **)(arg0 + 0x5A8))->unk2;
    } else {
        *(s16 *)(arg0 + 0x5B4) = -1;
    }
    return 1;
}
