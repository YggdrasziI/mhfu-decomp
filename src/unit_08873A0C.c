/* unit_08873A0C: 0x08873A0C-0x08873CC0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u16 id;
    u16 flag;
} Entry;

extern s32 D_09A0B540;
extern s32 D_08A631A0;
extern char *D_089CC438;
extern u8 D_0899D198[][24];
extern s32 func_08898694(s32, s32, s32);
extern void func_08898748(s32, s32);
extern u16 func_088900C4(s32, s32);
extern s32 func_08870AC4(char *, s32);

void func_08873A0C(char *arg0) {
    u16 *buf;
    s32 count;
    s32 i;
    s32 j;
    char *q;
    u16 *p;
    char *r;
    s32 a;
    s32 b;
    u16 t;
    u16 id;
    char *obj;
    Entry *out;
    s32 k;

    if (*(s32 *)(arg0 + 0x8A0) == 0) {
        return;
    }
    buf = (u16 *)func_08898694(D_09A0B540, 0x19, *(s32 *)(arg0 + 0x8A0) * 2);
    count = 0;
    i = 0;
    q = arg0;
    p = buf;
    r = arg0;
    while ((obj = *(char **)(q + 0x828)) != 0 && i < 20) {
        id = func_08870AC4(arg0, *(u16 *)(obj + 0x10) & 0x7FFF);
        if (id != 0 && !(D_0899D198[id][4] & 6)) {
            *p++ = id;
            count++;
        }
        if (*(u16 *)(r + 0x878) > 0) {
            (*(u16 *)(r + 0x878))--;
        }
        if (*(u16 *)(r + 0x878) == 0) {
            q += 4;
            r += 2;
            i++;
        }
    }
    for (j = 0; j < count; j++) {
        a = func_088900C4(D_08A631A0, 0) % count;
        b = func_088900C4(D_08A631A0, 0) % count;
        t = buf[a];
        buf[a] = buf[b];
        buf[b] = t;
    }
    if (count > 8) {
        count = 8;
    }
    out = (Entry *)(D_089CC438 + 0x390);
    for (k = 0; k < count; k++) {
        out->id = buf[k];
        out->flag = 1;
        out++;
    }
    func_08898748(D_09A0B540, 0x19);
    *(s8 *)(arg0 + 0x680) += (s8)count;
}
