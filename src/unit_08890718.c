/* unit_08890718: 0x08890718-0x088907D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between neighbouring units.
 */

typedef unsigned char u8;
typedef int s32;

extern s32 sceUtilityGetSystemParamInt(s32 id, s32 *value);
extern s32 D_09A1DB50;
extern u8 D_0899BE20;
extern s32 func_088902A8(char *);

void func_08890718(char *arg0) {
    s32 value;
    s32 lang;

    if (sceUtilityGetSystemParamInt(8, &value) != 0) {
        lang = 1;
    } else {
        switch (value) {
        case 1:
            lang = 1;
            break;
        case 2:
            lang = 3;
            break;
        case 4:
            lang = 2;
            break;
        case 3:
            lang = 4;
            break;
        case 5:
            lang = 5;
            break;
        default:
            lang = 1;
            break;
        }
    }
    *(s32 *)(arg0 + 0xF7A574) = lang;
    D_09A1DB50 = lang;
    func_088902A8(arg0);
    D_0899BE20 = lang;
}
