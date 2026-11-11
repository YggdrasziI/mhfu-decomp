/* unit_088DD838: 0x088DD838-0x088DD868 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;

extern void func_088DD8A8(char *);

void func_088DD838(char *arg0) {
    func_088DD8A8(arg0);
    *(s8 *)(arg0 + 0x216) = 0;
    *(s8 *)(arg0 + 0x215) = 1;
}
