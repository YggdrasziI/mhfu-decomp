/* unit_088572E8: 0x088572E8-0x088574A4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088572E8: copies a block of fields from 0x6ADD8 to 0x6AF1C. */

typedef int s32;
typedef signed char s8;

typedef struct {
    float x;
    float y;
} Vec2;

void func_088572E8(char *arg0) {

    *(s8 *)(arg0 + 0x6AF1C) = *(s8 *)(arg0 + 0x6ADD8);
    *(s8 *)(arg0 + 0x6AF1D) = *(s8 *)(arg0 + 0x6ADD9);
    *(s8 *)(arg0 + 0x6AF1E) = *(s8 *)(arg0 + 0x6ADDA);
    *(s8 *)(arg0 + 0x6AF1F) = *(s8 *)(arg0 + 0x6ADDB);
    *(s8 *)(arg0 + 0x6AF20) = *(s8 *)(arg0 + 0x6ADDC);
    *(s8 *)(arg0 + 0x6AF21) = *(s8 *)(arg0 + 0x6ADDD);
    *(s8 *)(arg0 + 0x6AF22) = *(s8 *)(arg0 + 0x6ADDE);
    *(s8 *)(arg0 + 0x6AF23) = *(s8 *)(arg0 + 0x6ADDF);
    *(s8 *)(arg0 + 0x6AF24) = *(s8 *)(arg0 + 0x6ADE0);
    *(s8 *)(arg0 + 0x6AF25) = *(s8 *)(arg0 + 0x6ADE1);
    *(s8 *)(arg0 + 0x6AF26) = *(s8 *)(arg0 + 0x6ADE2);
    *(s8 *)(arg0 + 0x6AF27) = *(s8 *)(arg0 + 0x6ADE3);
    *(s8 *)(arg0 + 0x6AF28) = *(s8 *)(arg0 + 0x6ADE4);
    *(s8 *)(arg0 + 0x6AF29) = *(s8 *)(arg0 + 0x6ADE5);
    *(Vec2 *)(arg0 + 0x6AF2C) = *(Vec2 *)(arg0 + 0x6ADE8);
    *(Vec2 *)(arg0 + 0x6AF34) = *(Vec2 *)(arg0 + 0x6ADF0);
    *(s32 *)(arg0 + 0x6AF3C) = *(s32 *)(arg0 + 0x6ADF8);
}
