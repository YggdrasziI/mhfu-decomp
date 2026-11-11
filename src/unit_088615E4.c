/* unit_088615E4: 0x088615E4-0x08861604 (ULES01213)
 *
 * Bounds (hypothesis): one function (stores a table address at offset 0 of an object) between unrelated code.
 */

extern int D_089BAB34[];

void *func_088615E4(void **p) {
    if (p != 0) {
        *p = D_089BAB34;
    }
    return p;
}
