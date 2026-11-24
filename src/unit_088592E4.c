/* unit_088592E4: 0x088592E4-0x08859480 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
typedef int s32;
typedef unsigned int u32;

extern u32 D_0899D108[];

typedef struct {
    char pad[0x148];
    u32 *tbl[20];
} Obj;

void func_088592E4(Obj *arg0) {
    u32 *p = (u32 *)((char *)arg0 + *(s32 *)((char *)arg0 + 4) * 0xA0 + 8);
    s32 i;

    for (i = 0; i < 19; i++) {
        p[0] = (((u32)(p + 2) & 0xFF000000) >> 8) | 0x10000000;
        p[1] = ((u32)(p + 2) & 0xFFFFFF) | 0x08000000;
        arg0->tbl[i] = p;
        p += 2;
    }
    p[0] = (((u32)D_0899D108 & 0xFF000000) >> 8) | 0x10000000;
    p[1] = ((u32)D_0899D108 & 0xFFFFFF) | 0x08000000;
    arg0->tbl[i] = p;
}
