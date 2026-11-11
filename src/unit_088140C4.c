/* unit_088140C4: 0x088140C4-0x08814104 (ULES01213)
 *
 * Bounds (hypothesis): two copies of a vector field (w cleared), between unrelated code.
 */

void func_088140C4(char *o, float *v) {
    v[0] = *(float *)(o + 0xB40);
    v[1] = *(float *)(o + 0xB44);
    v[2] = *(float *)(o + 0xB48);
    v[3] = 0.0f;
}

void func_088140E4(char *o, float *v) {
    v[0] = *(float *)(o + 0xB50);
    v[1] = *(float *)(o + 0xB54);
    v[2] = *(float *)(o + 0xB58);
    v[3] = 0.0f;
}
