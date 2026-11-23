/* unit_08860B24: 0x08860B24-0x08860C54 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08860B24 */

typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    float x, y, z;
} Vec3;

typedef struct {
    char pad0[0x10];
    Vec3 v;
    char pad1[0x30 - 0x1C];
} Entry;

extern Vec4 D_089A5C14[];
extern void func_08860848(char *, Vec3 *, s16, s32);

void func_08860B24(char *arg0, char *arg1) {
    s32 i;
    Entry *e;
    Vec4 *src;
    s32 off;
    char *q;
    Vec3 *dst;

    e = (Entry *)(arg0 + 0xB0);
    i = 0;
    src = D_089A5C14;
    off = 0;
    for (; i < 3; i++, e++, src++, off += 0x10) {
        dst = &e->v;
        switch (*(u16 *)(arg0 + 0x15C)) {
        case 0xC:
        case 0xE:
        case 0x1C:
        case 0x1E:
            if ((s32) ((*(s32 *)(arg1 + 0x614) & 0x4000) != 0) == 1) {
                dst->x = src->x;
                dst->y = src->y;
                dst->z = src->z;
                continue;
            }
            break;
        }
        q = *(char **)(arg1 + 0x1DC);
        if (q == 0 || i == 2) {
            func_08860848(arg0, dst, i, 1);
        } else {
            dst->x = ((Vec4 *)(q + off))->x;
            dst->y = ((Vec4 *)(q + off))->y;
            dst->z = ((Vec4 *)(q + off))->z;
        }
    }
}
