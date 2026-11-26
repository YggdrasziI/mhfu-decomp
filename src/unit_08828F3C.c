/* unit_08828F3C: 0x08828F3C-0x0882900C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u16 id;
    s16 num;
} Item;

extern s32 D_08A62C50;
extern u8 D_0899D19B[][24];

extern u8 func_0885B718(s32, char *, s32, s32);
extern u8 func_0885C124(s32, char *);

s32 func_08828F3C(char *arg0, Item *arg1) {
    char *e = *(char **)(arg0 + 0x5A8);
    s32 n;

    if (e != 0) {
        if (arg1->id != *(s16 *)(e + 2)) {
            return -1;
        }
        if (func_0885B718(D_08A62C50, e, 0, 0) == 0) {
            return -1;
        }
        n = D_0899D19B[arg1->id][0] - arg1->num;
        if (n <= 0) {
            return 0;
        }
        if (n < func_0885C124(D_08A62C50, *(char **)(arg0 + 0x5A8))) {
            return 1;
        }
        return 2;
    }
    return -1;
}
