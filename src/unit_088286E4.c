/* unit_088286E4: 0x088286E4-0x08828784 (ULES01213)
 *
 * Bounds (hypothesis): 1 function, neighbours still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u16 a;
    s16 b;
} Pair;

extern char *D_089CC438;
extern char *D_08A62C50;
extern Pair *func_08856884(char *, s32);
extern u8 func_0885B3A0(char *, s16, s32, s32);

s32 func_088286E4(s32 arg0, u8 idx, u16 id) {
    if (idx == 0xFF) {
        return 0;
    }
    if (func_08856884(D_089CC438, idx)->b == 0) {
        return 0;
    }
    if (id != func_08856884(D_089CC438, idx)->a) {
        return 0;
    }
    return func_0885B3A0(D_08A62C50, (s16)id, 0, 0) != 0;
}
