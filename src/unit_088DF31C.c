/* unit_088DF31C: 0x088DF31C-0x088DF324 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern void func_088DF2C4(char *);

void func_088DF31C(char *arg0) {
    *(s32 *)(arg0 + 0x80) = 0;
    func_088DF2C4(arg0);
}
