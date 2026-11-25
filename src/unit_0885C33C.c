/* unit_0885C33C: 0x0885C33C-0x0885C3DC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern char *D_089CC438;
extern u8 D_0899D198[][24];
extern s16 func_08850EC4(char *arg0);

s32 func_0885C33C(char *arg0, u16 id) {
    char *p;
    s32 n;
    s32 sum;
    s32 i;

    p = D_089CC438 + 0x4A0;
    n = func_08850EC4(D_089CC438);
    sum = 0;
    for (i = 0; i < n; i++, p += 4) {
        if (*(u16 *)(p + 0x2F88) == id) {
            if (D_0899D198[id][3] == 0xFF) {
                return 999;
            }
            sum += *(s16 *)(p + 0x2F8A);
        }
    }
    return sum;
}
