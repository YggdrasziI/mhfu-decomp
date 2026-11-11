/* unit_088662B8: 0x088662B8-0x088664A8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern char *D_08A62C5C;
extern int func_0880C464(char *, s32, s32);
extern int func_08859AE4(char *, char *, s32);

char *func_088662B8(char *arg0) {
    s32 var_a0;
    char *var_v1;

    D_08A62C5C = arg0;
    func_08859AE4(arg0 + 0x80000, arg0, 0x80000);
    var_a0 = 0;
    var_v1 = arg0;
    do {
        *(s32 *)(var_v1 + 0x80028) = 0;
        *(s32 *)(var_v1 + 0x80064) = 0;
        *(s32 *)(var_v1 + 0x8002C) = 0;
        *(s32 *)(var_v1 + 0x80068) = 0;
        *(s32 *)(var_v1 + 0x80030) = 0;
        *(s32 *)(var_v1 + 0x8006C) = 0;
        *(s32 *)(var_v1 + 0x80034) = 0;
        *(s32 *)(var_v1 + 0x80070) = 0;
        *(s32 *)(var_v1 + 0x80038) = 0;
        *(s32 *)(var_v1 + 0x80074) = 0;
        var_a0 += 5;
        var_v1 += 0x14;
    } while (var_a0 < 0xF);
    *(s32 *)(arg0 + 0x800A0) = 0;
    func_0880C464(arg0 + 0x80258, 0, 0xC0);
    func_0880C464(arg0 + 0x80318, 0, 0xC0);
    func_0880C464(arg0 + 0x803D8, 0, 0x30);
    func_0880C464(arg0 + 0x80408, 0xFF, 0x60);
    *(s8 *)(arg0 + 0x800A4) = 0;
    func_0880C464(arg0 + 0x800A8, 0, 0x180);
    *(s32 *)(arg0 + 0x80228) = 0;
    *(s32 *)(arg0 + 0x8022C) = 0;
    *(s32 *)(arg0 + 0x80230) = 0;
    *(s32 *)(arg0 + 0x80234) = 0;
    *(s32 *)(arg0 + 0x80238) = 0;
    *(s32 *)(arg0 + 0x8023C) = 0;
    *(s32 *)(arg0 + 0x80240) = 0;
    *(s32 *)(arg0 + 0x80244) = 0;
    *(s32 *)(arg0 + 0x80248) = 0;
    *(s32 *)(arg0 + 0x8024C) = 0;
    *(s32 *)(arg0 + 0x80250) = 0;
    *(s32 *)(arg0 + 0x80254) = 0;
    return arg0;
}
