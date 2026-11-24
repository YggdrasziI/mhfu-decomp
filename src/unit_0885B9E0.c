/* unit_0885B9E0: 0x0885B9E0-0x0885BB00 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885B9E0 */
#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u16 id;
    s16 num;
} Item;

typedef struct {
    char pad[0x2F88];
    Item ent[1];
} Box;

extern char *D_089CC438;
extern u8 D_0899D19B[];
extern s16 func_08850EC4(char *arg0);

s16 func_0885B9E0(char *arg0, u16 arg1, s16 arg2) {
    Box *p = (Box *)(D_089CC438 + 0x4A0);
    s16 n;
    s16 i;
    s16 rem;

    if (arg2 < 0) {
        return 0;
    }
    if (arg1 == 0 || D_0899D19B[arg1 * 24] == 0xFF) {
        return 0;
    }
    n = func_08850EC4(D_089CC438);
    rem = arg2;
    for (i = 0; i < n; i++) {
        if (p->ent[i].id == arg1) {
            if (p->ent[i].num >= rem) {
                p->ent[i].num -= rem;
                rem = 0;
            } else {
                rem -= p->ent[i].num;
                p->ent[i].num = 0;
            }
            if (p->ent[i].num <= 0) {
                p->ent[i].id = 0;
            }
            if (rem <= 0) {
                return 0;
            }
        }
    }
    return rem;
}
