/* unit_088A2F88: 0x088A2F88-0x088A3244 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between its neighbours.
 */

/* func_088A2F88: copies 21 floats into arg1+0x150, keeping the old value
 * where the source holds the 0x00800000 marker, then clears six words. */

typedef int s32;

typedef struct {
    char unk0[0x150];
    float unk150[21];
    s32 unk1A4;
    s32 unk1A8;
    char unk1AC[0x18];
    s32 unk1C4;
    s32 unk1C8;
    char unk1CC[0x18];
    s32 unk1E4;
    s32 unk1E8;
} T;

/* Bit pattern 0x00800000 (lui 0x80 + mtc1). */
#define MARK 1.17549435e-38f

#define COPY(i) dst->unk150[i] = (src[i] != MARK) ? src[i] : dst->unk150[i]

void func_088A2F88(float *src, T *dst) {
    COPY(0); COPY(1); COPY(2); COPY(3); COPY(4); COPY(5); COPY(6);
    COPY(7); COPY(8); COPY(9); COPY(10); COPY(11); COPY(12); COPY(13);
    COPY(14); COPY(15); COPY(16); COPY(17); COPY(18); COPY(19); COPY(20);
    dst->unk1A8 = 0;
    dst->unk1A4 = 0;
    dst->unk1C8 = 0;
    dst->unk1C4 = 0;
    dst->unk1E4 = 0;
    dst->unk1E8 = 0;
}
