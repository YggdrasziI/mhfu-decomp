/* unit_088902A8: 0x088902A8-0x088903BC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly and
 * unit_088903BC. Its jump table (0x08931A84-0x08931AA0) is linked from this
 * unit.
 */

typedef int s32;

extern s32 sceImposeSetLanguageMode(s32 lang, s32 button);

s32 func_088902A8(char *arg0) {
    s32 lang;

    switch (*(s32 *)(arg0 + 0xF7A574)) {
    case 0:
    default:
        lang = 0;
        *(s32 *)(arg0 + 0xF7A578) = 0;
        break;
    case 1:
        lang = 1;
        *(s32 *)(arg0 + 0xF7A578) = 1;
        break;
    case 2:
        lang = 4;
        *(s32 *)(arg0 + 0xF7A578) = 1;
        break;
    case 3:
        lang = 2;
        *(s32 *)(arg0 + 0xF7A578) = 1;
        break;
    case 4:
        lang = 3;
        *(s32 *)(arg0 + 0xF7A578) = 1;
        break;
    case 5:
        lang = 5;
        *(s32 *)(arg0 + 0xF7A578) = 1;
        break;
    case 6:
        lang = 9;
        *(s32 *)(arg0 + 0xF7A578) = 0;
        break;
    }
    return sceImposeSetLanguageMode(lang, *(s32 *)(arg0 + 0xF7A578));
}
