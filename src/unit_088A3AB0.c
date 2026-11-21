/* unit_088A3AB0: 0x088A3AB0-0x088A3ED4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between its neighbours.
 */

/* func_088A3AB0: copies 21 floats from arg0 to globals; an entry equal
 * to 0x00800000 (FLT_MIN bit pattern, hypothesis: "unset" marker) keeps the old value, then clears six words. */

typedef int s32;

extern float D_089B24D8[2];
extern float D_089B24E0[2];
extern float D_089B24E8[2];
extern float D_089B24F0[2];
extern float D_089B24F8[2];
extern float D_089B2500[2];
extern float D_089B2508[2];
extern float D_089B2510[2];
extern float D_089B2518[2];
extern float D_089B2520[2];
extern float D_089B2528[2];
extern s32 D_09A0DAE8;
extern s32 D_09A0DAE4;
extern s32 D_09A0DB08;
extern s32 D_09A0DB04;
extern s32 D_09A0DB24;
extern s32 D_09A0DB28;

#define KEEP 1.17549435e-38f

void func_088A3AB0(float *arg0) {
    D_089B24D8[1] = (arg0[0] != KEEP) ? arg0[0] : D_089B24D8[1];
    D_089B24E0[0] = (arg0[1] != KEEP) ? arg0[1] : D_089B24E0[0];
    D_089B24E0[1] = (arg0[2] != KEEP) ? arg0[2] : D_089B24E0[1];
    D_089B24E8[0] = (arg0[3] != KEEP) ? arg0[3] : D_089B24E8[0];
    D_089B24E8[1] = (arg0[4] != KEEP) ? arg0[4] : D_089B24E8[1];
    D_089B24F0[0] = (arg0[5] != KEEP) ? arg0[5] : D_089B24F0[0];
    D_089B24F0[1] = (arg0[6] != KEEP) ? arg0[6] : D_089B24F0[1];
    D_089B24F8[0] = (arg0[7] != KEEP) ? arg0[7] : D_089B24F8[0];
    D_089B24F8[1] = (arg0[8] != KEEP) ? arg0[8] : D_089B24F8[1];
    D_089B2500[0] = (arg0[9] != KEEP) ? arg0[9] : D_089B2500[0];
    D_089B2500[1] = (arg0[10] != KEEP) ? arg0[10] : D_089B2500[1];
    D_089B2508[0] = (arg0[11] != KEEP) ? arg0[11] : D_089B2508[0];
    D_089B2508[1] = (arg0[12] != KEEP) ? arg0[12] : D_089B2508[1];
    D_089B2510[0] = (arg0[13] != KEEP) ? arg0[13] : D_089B2510[0];
    D_089B2510[1] = (arg0[14] != KEEP) ? arg0[14] : D_089B2510[1];
    D_089B2518[0] = (arg0[15] != KEEP) ? arg0[15] : D_089B2518[0];
    D_089B2518[1] = (arg0[16] != KEEP) ? arg0[16] : D_089B2518[1];
    D_089B2520[0] = (arg0[17] != KEEP) ? arg0[17] : D_089B2520[0];
    D_089B2520[1] = (arg0[18] != KEEP) ? arg0[18] : D_089B2520[1];
    D_089B2528[0] = (arg0[19] != KEEP) ? arg0[19] : D_089B2528[0];
    D_089B2528[1] = (arg0[20] != KEEP) ? arg0[20] : D_089B2528[1];
    D_09A0DAE8 = 0;
    D_09A0DAE4 = 0;
    D_09A0DB08 = 0;
    D_09A0DB04 = 0;
    D_09A0DB24 = 0;
    D_09A0DB28 = 0;
}
