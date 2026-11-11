/* unit_0889F744: 0x0889F744-0x0889F764 (ULES01213)
 *
 * Bounds (hypothesis): one function between unrelated code.
 */

typedef struct {
    char data[72];
} Entry;

extern Entry D_09A0C838[];

Entry *func_0889F744(unsigned int i) {
    return &D_09A0C838[i & 0x1F];
}
