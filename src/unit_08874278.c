/* unit_08874278: 0x08874278-0x08874454 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef unsigned short u16;
typedef signed char s8;
typedef int s32;

typedef struct {
    u16 id;
    u16 key;
    u16 unk4;
} Entry;

extern char *D_089CC438;
extern s32 D_08A62C7C;
extern Entry D_089A8624[];
extern Entry D_089A857C[];

extern s32 func_0886A30C(s32, s32);
extern int func_0884FAC4(char *, s32);
extern s32 func_08857294(char *arg0, s8 arg1);
extern s32 func_08850618(char *, s32);
extern s32 func_0884FB38(char *, s32);
extern s32 func_0884FE80(char *, u16);

s32 func_08874278(s32 arg0, s32 arg1) {
    Entry *e;
    s32 i;
    s32 idx;

    if (*(u16 *)(D_089CC438 + 0x6AF12) == 0xC22 && func_0886A30C(D_08A62C7C, 1) == 1) {
        func_0884FAC4(D_089CC438, 0x164);
    }
    idx = func_08857294(D_089CC438, arg1);
    if (idx < 0 || func_08850618(D_089CC438, idx)) {
        return 0;
    }
    if (idx >= 0x2C && idx < 0x33) {
        if (func_0884FB38(D_089CC438, idx + 0xB8)) {
            return 1;
        }
    } else if (idx == 0x33) {
        if (func_0884FB38(D_089CC438, 0xED)) {
            return 1;
        }
    } else if (idx >= 0xB && idx < 0x39) {
        e = D_089A8624;
        for (i = 0; i < 0x26; i++, e++) {
            if (idx == e->key && func_0884FB38(D_089CC438, e->id)) {
                return 1;
            }
        }
    } else if (idx >= 0 && idx < 0xB) {
        e = D_089A857C;
        for (i = 0; i < 0x1C; i++, e++) {
            if (idx == e->key && func_0884FE80(D_089CC438, e->id)) {
                return 1;
            }
        }
    }
    return 0;
}
