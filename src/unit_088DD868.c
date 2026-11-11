/* unit_088DD868: 0x088DD868-0x088DD8A8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern int func_088AD064(char *, s32);
extern char func_088DE560;
extern char func_088DE6A0;

void func_088DD868(s32 arg0) {
    func_088AD064(&func_088DE560, arg0);
    func_088AD064(&func_088DE6A0, arg0);
}
