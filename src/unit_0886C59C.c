/* unit_0886C59C: 0x0886C59C-0x0886C768 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886C59C: adds or updates a (id, value) entry in a 4-entry table at
 * 0x542 of arg1 after measuring a margin with func_0886E578 / func_0886E6F4.
 * Speed setting (`#pragma optimize_for_size off`) needed. The "found" value of
 * the first search loop reuses the call-result local r (a separate local gets
 * other registers).
 */
#pragma optimize_for_size off
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u16 id;
    s16 val;
} Ent;

typedef struct {
    char pad[0x542];
    Ent ent[4];
} Rec;

extern char *D_08A62C7C;
extern s16 func_0886E578(char *, s32, u16);
extern s16 func_0886E6F4(char *, s32);

s32 func_0886C59C(char *arg0, Rec *arg1, s32 arg2, s32 arg3) {
    s16 i;
    s16 max;
    s16 r;
    s16 d;

    s32 res;

    max = 0;
    for (i = 0; i < 2; i++) {
        r = func_0886E578(D_08A62C7C, arg2, i);
        if (r >= 0) {
            d = r - func_0886E6F4(D_08A62C7C, arg2);
            if (max < d) {
                max = d;
            }
        }
    }
    if (max <= 0) {
        return 0;
    }
    r = 0;
    for (i = 0; i < 4; i++) {
        if (arg1->ent[i].id == (u16)arg2) {
            r = arg1->ent[i].val;
        }
    }
    if (r == 0) {
        res = 0;
        for (i = 0; i < 4; i++) {
            if (arg1->ent[i].id == 0) {
                arg1->ent[i].id = arg2;
                if ((s16)arg3 >= max) {
                    res = 2;
                }
                arg1->ent[i].val = (s8)arg3;
                return res;
            }
        }
    } else {
        res = 1;
        for (i = 0; i < 4; i++) {
            if (arg1->ent[i].id == (u16)arg2) {
                if ((s16)arg3 >= max) {
                    res = 2;
                }
                arg1->ent[i].val = (s8)arg3;
                return res;
            }
        }
    }
    return res;
}
