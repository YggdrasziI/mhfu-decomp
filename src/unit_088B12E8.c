/* unit_088B12E8: 0x088B12E8-0x088B1350 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B1204 and unit_088B1350.
 *
 * When func_088B04B4 accepts the 0xC8-byte record arg0, copies it to
 * D_09A28AD0 and calls func_088B6A80 with 5 and 7.
 */

typedef int s32;

typedef struct {
    s32 unk0;
    char unk4[0xC4];
} Rec;

extern Rec D_09A28AD0;

extern s32 func_088B04B4(Rec *);
extern s32 func_088B6A80(s32);

void func_088B12E8(Rec *arg0) {
    if (func_088B04B4(arg0)) {
        D_09A28AD0 = *arg0;
        func_088B6A80(5);
        func_088B6A80(7);
    }
}
