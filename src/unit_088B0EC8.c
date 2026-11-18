/* unit_088B0EC8: 0x088B0EC8-0x088B0EFC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B0E2C and unit_088B0EFC.
 *
 * Copies the 0xC8-byte record D_09A28AD0 to arg0. Returns 0.
 */

typedef int s32;

typedef struct {
    s32 unk0;
    char unk4[0xC4];
} Rec;

extern Rec D_09A28AD0;

s32 func_088B0EC8(Rec *arg0) {
    *arg0 = D_09A28AD0;
    return 0;
}
