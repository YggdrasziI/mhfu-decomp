/* unit_08856920: 0x08856920-0x088569F8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 */

#pragma optimize_for_size off
/* func_08856920 */

typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u16 unk0;
    s16 unk2;
} Pair;

extern Pair *func_08856884(char *, s32);
extern u8 D_0899D19B[];

s32 func_08856920(char *arg0, s32 arg1) {
    s32 i;
    u8 *max;

    for (i = 0; i < 24; i++) {
        if ((u16)arg1 == func_08856884(arg0, i)->unk0) {
            max = &D_0899D19B[(arg1 & 0xFFFF) * 24];
            if (*max == 0xFF) {
                return 0xFF;
            }
            return *max - func_08856884(arg0, i)->unk2;
        }
    }
    return D_0899D19B[(arg1 & 0xFFFF) * 24];
}
