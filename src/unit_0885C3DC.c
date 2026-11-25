/* unit_0885C3DC: 0x0885C3DC-0x0885C498 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

/* func_0885C3DC: 0 when arg1 is 0 or its D_0899D19B record byte is 0xFF;
 * otherwise sums, over the func_08850EC4() slots of D_089CC438 + 0x4A0, the
 * room left (99 - count) in slots holding arg1 plus 99 per empty slot.
 * Speed setting needed (guarded bottom-tested loop). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

extern char *D_089CC438;
extern u8 D_0899D19B[];

extern s16 func_08850EC4(char *arg0);

s32 func_0885C3DC(s32 arg0, u16 arg1) {
    char *p = D_089CC438 + 0x4A0;
    s32 sum;
    s32 n;
    s32 i;

    if (arg1 == 0 || D_0899D19B[arg1 * 24] == 0xFF) {
        return 0;
    }
    n = func_08850EC4(D_089CC438);
    sum = 0;
    for (i = 0; i < n; i++, p += 4) {
        u16 id = *(u16 *)(p + 0x2F88);
        if (id == arg1) {
            sum += 99 - *(s16 *)(p + 0x2F8A);
        } else if (id == 0) {
            sum += 99;
        }
    }
    return sum;
}
