/* unit_088AEC3C: 0x088AEC3C-0x088AED80 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AEB80 and unit_088AED80.
 *
 * When D_09A202C8 is set, reads the current list of 18 8-byte entries
 * (func_088B0604, with its count) and, when it differs from the stored one
 * at D_09A1FE08 (func_088AED80), handles each stored entry that
 * func_088AEDA0 finds in none of the new entries (func_088AF7E0,
 * func_088AF978, func_088B7350; reading of the callees, hypothesis). Then
 * the new list and its count (D_09A1FE04) replace the stored ones.
 */

typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

extern s32 D_09A202C8;
extern s32 D_09A1FE04;
extern char D_09A1FE08[];
extern u8 D_09A1FDE0;

extern void memset(void *, s32, s32);
extern void func_0880C084(void *, void *, s32);
extern void func_088B0604(char *, u32 *);
extern s32 func_088AED80(char *, char *);
extern s32 func_088B04B4(char *);
extern s32 func_088AEDA0(char *, char *);
extern s32 func_088AF7E0(char *);
extern s32 func_088AF978(char *);
extern void func_088B7350(char *);

void func_088AEC3C(void) {
    u32 count;
    char list[0x90];
    s32 found;
    s32 i;
    char *e;

    if (D_09A202C8 == 0) {
        return;
    }
    memset(list, 0, sizeof(list));
    count = 0;
    func_088B0604(list, &count);
    if (func_088AED80(D_09A1FE08, list) == 0) {
        return;
    }
    e = D_09A1FE08;
    if (D_09A1FE04 != 0) {
        i = 0;
        do {
            if (func_088B04B4(e)) {
                found = 0;
                if (!func_088AEDA0(e, list)) {
                    found = 1;
                }
                if (!found && !func_088AF7E0(e)) {
                    func_088AF978(e);
                    if (D_09A1FDE0 != 2) {
                        func_088B7350(e);
                    }
                }
            }
            i++;
            e += 8;
        } while (i < 0x12);
    }
    D_09A1FE04 = count;
    if (count != 0) {
        func_0880C084(D_09A1FE08, list, sizeof(list));
    } else {
        memset(D_09A1FE08, 0, sizeof(list));
    }
}
