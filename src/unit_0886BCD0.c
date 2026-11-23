/* unit_0886BCD0: 0x0886BCD0-0x0886BD84 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886BCD0 */

typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s32 state;
    u16 id;
    s8 need;
    s8 level;
} Entry;

extern char *D_089CC438;
extern s32 func_088568AC(char *, u16);
extern void func_0886BBE4(char *);

void func_0886BCD0(char *arg0) {
    Entry *e;
    s32 i;

    e = (Entry *)(arg0 + 0x74C);
    for (i = 0; i < 2; i++, e++) {
        switch (e->state) {
        case 0:
            break;
        case 1:
            break;
        case 2:
            if (func_088568AC(D_089CC438, e->id) >= e->need) {
                if (*(s8 *)(arg0 + 0x20) < e->level) {
                    *(s8 *)(arg0 + 0x20) = e->level;
                    func_0886BBE4(arg0);
                }
                e->state = 0;
            }
            break;
        }
    }
}
