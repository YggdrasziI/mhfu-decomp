/* unit_08821828: 0x08821828-0x08821890 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

typedef struct {
    u8 id;
    s8 val;
} Pair;

s32 func_08821828(s32 arg0, Pair *key, Pair *tbl) {
    s32 i;
    s32 r;

    i = 9;
    do {
        if (tbl->id == 0) {
            break;
        }
        if (key->id == tbl->id) {
            if (key->val > tbl->val) {
                r = 1;
            } else {
                r = -(key->val < tbl->val);
            }
            goto end;
        }
        i--;
        tbl++;
    } while (i > 0);
    if (key->val > 0) {
        r = 1;
    } else {
        r = -(key->val < 0);
    }
end:
    return r;
}
