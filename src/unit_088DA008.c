/* unit_088DA008: 0x088DA008-0x088DA150 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef float f32;

void func_088DA008(char *arg0) {
    if (*(f32 *)(arg0 + 0x39C) < -100.0f) {
        *(f32 *)(arg0 + 0x39C) = -100.0f;
    }
    if (*(f32 *)(arg0 + 0x3A0) < -100.0f) {
        *(f32 *)(arg0 + 0x3A0) = -100.0f;
    }
    if (*(f32 *)(arg0 + 0x3A4) < -100.0f) {
        *(f32 *)(arg0 + 0x3A4) = -100.0f;
    }
    if (*(f32 *)(arg0 + 0x3A8) < -100.0f) {
        *(f32 *)(arg0 + 0x3A8) = -100.0f;
    }
    if (*(f32 *)(arg0 + 0x3AC) < -100.0f) {
        *(f32 *)(arg0 + 0x3AC) = -100.0f;
    }
    if (*(f32 *)(arg0 + 0x39C) > 100.0f) {
        *(f32 *)(arg0 + 0x39C) = 100.0f;
    }
    if (*(f32 *)(arg0 + 0x3A0) > 100.0f) {
        *(f32 *)(arg0 + 0x3A0) = 100.0f;
    }
    if (*(f32 *)(arg0 + 0x3A4) > 100.0f) {
        *(f32 *)(arg0 + 0x3A4) = 100.0f;
    }
    if (*(f32 *)(arg0 + 0x3A8) > 100.0f) {
        *(f32 *)(arg0 + 0x3A8) = 100.0f;
    }
    if (*(f32 *)(arg0 + 0x3AC) > 100.0f) {
        *(f32 *)(arg0 + 0x3AC) = 100.0f;
    }
}
