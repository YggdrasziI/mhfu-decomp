/* unit_088A1E70: 0x088A1E70-0x088A2068 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

extern char D_09A0D25C;
extern int func_088A177C(char *);
extern int func_088A178C(char *);
extern int sceAtracSetDataAndGetID(void *, s32);
extern int sceAtracGetRemainFrame(s32, s32 *);
extern int sceAtracGetSoundSample(s32, s32 *, s32 *, s32 *);
extern int sceAtracGetBitrate(s32, s32 *);

s32 func_088A1E70(char *arg0, void *arg1, s32 arg2) {
    s32 temp;
    s32 half;

    *(void **)(arg0 + 0xA0) = arg1;
    *(s32 *)(arg0 + 0x90) = arg2;
    func_088A177C(&D_09A0D25C);
    *(s32 *)(arg0 + 0x8) = sceAtracSetDataAndGetID(*(void **)(arg0 + 0xA0), *(s32 *)(arg0 + 0x90));
    *(s32 *)(arg0 + 0x54) = 1;
    func_088A178C(&D_09A0D25C);
    if (*(s32 *)(arg0 + 0x8) < 0) {
        return -1;
    }
    sceAtracGetRemainFrame(*(s32 *)(arg0 + 0x8), (s32 *)(arg0 + 0x14));
    temp = *(s32 *)(arg0 + 0x14);
    switch (temp) {
    default:
        half = temp / 2;
        *(s32 *)(arg0 + 0x130) = half;
        if (half <= 0) {
            *(s32 *)(arg0 + 0x130) = 1;
        }
        break;
    case -3:
    case -2:
    case -1:
        *(s32 *)(arg0 + 0x130) = 0;
        break;
    }
    *(s32 *)(arg0 + 0x134) = 0;
    *(s32 *)(arg0 + 0x138) = 0;
    *(s32 *)(arg0 + 0x13C) = 0;
    sceAtracGetSoundSample(*(s32 *)(arg0 + 0x8), (s32 *)(arg0 + 0x30), (s32 *)(arg0 + 0x34),
                           (s32 *)(arg0 + 0x38));
    sceAtracGetBitrate(*(s32 *)(arg0 + 0x8), (s32 *)(arg0 + 0x50));
    switch (*(s32 *)(arg0 + 0x50)) {
    case 0x34:
    case 0x42:
    case 0x69:
    case 0x84:
        *(s32 *)(arg0 + 0x1C) = 0;
        break;
    case 0x20:
    case 0x30:
    case 0x40:
    case 0x60:
    case 0x80:
    case 0xA0:
    case 0xC0:
    case 0x100:
    case 0x140:
    case 0x160:
        *(s32 *)(arg0 + 0x1C) = 1;
        break;
    }
    *(s32 *)(arg0 + 0x44) = !(*(s32 *)(arg0 + 0x34) == -1 && *(s32 *)(arg0 + 0x38) == -1);
    *(s32 *)(arg0 + 0x48) = 0;
    *(s32 *)(arg0 + 0x3C) = 0;
    *(s32 *)(arg0 + 0x40) = 0;
    *(s32 *)(arg0 + 0x54) = 2;
    return 0;
}
