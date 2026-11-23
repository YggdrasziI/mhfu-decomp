/* unit_08862E64: 0x08862E64-0x08862FE0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08862E64: writes GE commands for a flag word. */

typedef unsigned int u32;

extern u32 *D_089CC000;

void func_08862E64(u32 *arg0) {
    if (arg0[0] & 0x80000000) {
        if (arg0[0] & 1) {
            *D_089CC000 = 0x17000001;
            D_089CC000++;
        } else {
            *D_089CC000 = 0x17000000;
            D_089CC000++;
        }
        if (arg0[0] & 2) {
            *D_089CC000 = 0x1F000001;
            D_089CC000++;
        } else {
            *D_089CC000 = 0x1F000000;
            D_089CC000++;
        }
        if (arg0[0] & 4) {
            *D_089CC000 = 0x21000001;
            D_089CC000++;
            *D_089CC000 = arg0[1];
            D_089CC000++;
            if (arg0[1] == 0xDF0000A2) {
                *D_089CC000 = 0x27000001;
                D_089CC000++;
                *D_089CC000 = 0xD8000003;
                D_089CC000++;
                *D_089CC000 = 0xD9000000;
                D_089CC000++;
            }
        }
    }
}
