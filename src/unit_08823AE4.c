/* unit_08823AE4: 0x08823AE4-0x08823B58 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 * Searches a ring of 20 records (stride 0x24 at 0xE28) for a byte value.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef struct { u8 pad[0x1B]; u8 f; u8 pad2[0x8]; } Ent;
typedef struct { u8 pad[0xE28]; Ent ent[20]; s8 n; s8 start; } Obj;

s32 func_08823AE4(Obj *arg0, u8 arg1) {
    s32 n;
    s16 i;

    n = arg0->n;
    if (n == 0) {
        return 0;
    }
    for (i = 0; i < n; i++) {
        if (arg0->ent[(s16)((arg0->start + i) % 20)].f == arg1) {
            return 1;
        }
    }
    return 0;
}
