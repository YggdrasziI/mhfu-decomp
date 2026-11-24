/* unit_08852C20: 0x08852C20-0x08852DF8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef signed char s8;

extern s8 D_0899BE20;
extern s8 D_0899BE21;
extern s8 D_0899BE22;
extern s8 D_0899BE23;
extern s8 D_0899BE24;
extern s8 D_0899BE25;
extern s8 D_0899BE26;
extern s8 D_0899BE27;
extern s8 D_0899BE28;
extern s8 D_0899BE29;
extern s8 D_0899BE2A;
extern s8 D_0899BE2B;
extern s8 D_0899BE2C;
extern s8 D_0899BE2D;
extern char *D_08A631A0;
extern s32 D_09A1DB50;
extern s32 D_08A62D8C;

extern s32 func_088902A8(char *);
extern void func_08880760(s32, s32);
extern void func_08880864(s32, s32);
extern void func_08880874(s32, s32);

void func_08852C20(char *arg0, s32 arg1) {
    s8 old;
    s32 v;

    old = *(s8 *)(arg0 + 0x6ADD8);
    *(s8 *)(arg0 + 0x6ADD8) = D_0899BE20;
    *(s8 *)(arg0 + 0x6ADD9) = D_0899BE21;
    *(s8 *)(arg0 + 0x6ADDA) = D_0899BE22;
    *(s8 *)(arg0 + 0x6ADDB) = D_0899BE23;
    *(s8 *)(arg0 + 0x6ADDC) = D_0899BE24;
    *(s8 *)(arg0 + 0x6ADDD) = D_0899BE25;
    *(s8 *)(arg0 + 0x6ADDE) = D_0899BE26;
    *(s8 *)(arg0 + 0x6ADDF) = D_0899BE27;
    *(s8 *)(arg0 + 0x6ADE0) = D_0899BE28;
    *(s8 *)(arg0 + 0x6ADE1) = D_0899BE29;
    *(s8 *)(arg0 + 0x6ADE2) = D_0899BE2A;
    *(s8 *)(arg0 + 0x6ADE3) = D_0899BE2B;
    *(s8 *)(arg0 + 0x6ADE4) = D_0899BE2C;
    *(s8 *)(arg0 + 0x6ADE5) = D_0899BE2D;
    if ((arg1 & 0xFF) == 1) {
        char *p;
        v = *(s8 *)(arg0 + 0x6ADD8);
        p = D_08A631A0;
        *(s32 *)(p + 0xF7A574) = v;
        D_09A1DB50 = v;
        func_088902A8(p);
    } else {
        *(s8 *)(arg0 + 0x6ADD8) = old;
    }
    func_08880760(D_08A62D8C, *(s8 *)(arg0 + 0x6ADD9));
    func_08880864(D_08A62D8C, *(s8 *)(arg0 + 0x6ADDB));
    func_08880874(D_08A62D8C, *(s8 *)(arg0 + 0x6ADDA));
}
