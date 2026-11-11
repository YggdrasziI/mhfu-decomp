# asm-differ settings (https://github.com/simonlindholm/asm-differ): compare one
# function of the build with the original, live.
#
#   python <asm-differ>/diff.py -mwo func_088A6024       # rebuild with ninja, watch sources
#   DECOMP_VERSION=ULUS10391 python <asm-differ>/diff.py func_...
#
# The version comes from DECOMP_VERSION (default: the first of decomp.toml), and must
# be the one tools/configure.py was last run for.

import os
import sys


def apply(config, args):
    version = os.environ.get("DECOMP_VERSION", "ULES01213")
    config["baseimg"] = f"orig/{version}/BOOT.BIN"
    config["myimg"] = f"build/{version}/BOOT.BIN"
    config["mapfile"] = f"build/{version}/boot.map"
    config["map_format"] = "gnu"
    config["source_directories"] = ["src", "include", f"asm/{version}"]
    config["arch"] = "mipsel"
    config["build_dir"] = f"build/{version}"
    config["make_command"] = ["ninja"]
    exe = ".exe" if sys.platform == "win32" else ""
    # absolute: Windows does not find a relative program path written with "/"
    config["objdump_executable"] = os.path.abspath(f"tools/binutils/mips-ps2-decompals-objdump{exe}")
