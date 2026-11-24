/* unit_088569F8: 0x088569F8-0x08856B24 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u16 id;
    s16 num;
} Slot;

typedef struct {
    u8 max;
    u8 pad[23];
} Info;

extern char D_0899D19B[];
extern char *D_089CC438;
extern Slot *func_08856884(char *, s32);

s16 func_088569F8(char *arg0, u16 arg1) {
    s16 i;
    s16 j;
    s16 cnt;

    cnt = 0;
    i = 0;
    do {
        j = i;
        if (func_08856884(arg0, j)->id == arg1) {
            if (((Info *)D_0899D19B)[arg1].max == 0xFF) {
                return 0xFF;
            }
            return (s16)(((Info *)D_0899D19B)[arg1].max - func_08856884(arg0, j)->num);
        }
        if (func_08856884(D_089CC438, j)->id == 0) {
            cnt++;
        }
        i++;
    } while (i < 24);
    if (cnt == 0) {
        return -1;
    }
    return ((Info *)D_0899D19B)[arg1].max;
}
