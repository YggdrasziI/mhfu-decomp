/* unit_08872DC4: 0x08872DC4-0x08872DF4 (ULES01213)
 *
 * Bounds (hypothesis): 3 small functions between code still in assembly.
 */

typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef struct { char b[8]; } E8;

u16 func_08872DC4(s32 arg0, s32 arg1) {
    return *(u16 *)((E8 *)((char *)arg0 + 0x73C))[arg1].b;
}

s16 func_08872DD4(s32 arg0, s32 arg1) {
    return *(s16 *)((E8 *)((char *)arg0 + 0x73E))[arg1].b;
}

s16 func_08872DE4(s32 arg0, s32 arg1) {
    return *(s16 *)((E8 *)((char *)arg0 + 0x72E))[arg1].b;
}
