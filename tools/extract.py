#!/usr/bin/env python3
"""Extract the target executables from the game ISO and check their SHA-1.

The ISO is read with 7-Zip (`7z` in PATH or the default install folder) and the
files go to orig/<version>/, which is git-ignored.
"""

import argparse
import hashlib
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

# Inputs per version; iso_sha1 None: version not supported yet
VERSIONS = {
    "ULES01213": {
        "iso_sha1": "b67f57e2ea0d5a31d3c58eb0c7e54c4ef47ea838",
        "files": ["PSP_GAME/SYSDIR/BOOT.BIN"],
    },
    "ULUS10391": {
        "iso_sha1": "f5cb0eaebbf5008bd8d486832229ae97a16bbee6",
        "files": ["PSP_GAME/SYSDIR/BOOT.BIN"],
    },
    "ULJM05500": {
        "iso_sha1": "951d1a360eec83af294a7a51ec4bba08f8633a6e",
        "files": ["PSP_GAME/SYSDIR/BOOT.BIN"],
    },
}


def sha1_of(path: Path) -> str:
    h = hashlib.sha1()
    with path.open("rb") as f:
        while chunk := f.read(1 << 20):
            h.update(chunk)
    return h.hexdigest()


def find_7z() -> str:
    for name in ("7z", "7zz"):
        if exe := shutil.which(name):
            return exe
    default = Path("C:/Program Files/7-Zip/7z.exe")
    if default.exists():
        return str(default)
    sys.exit("7z not found: install 7-Zip or add it to PATH")


def expected_sha1(version: str) -> dict[str, str]:
    """Read config/<version>/build.sha1 (sha1sum format)."""
    result = {}
    sha1_file = ROOT / "config" / version / "build.sha1"
    if sha1_file.exists():
        for line in sha1_file.read_text().splitlines():
            if line.strip():
                digest, name = line.split(maxsplit=1)
                result[Path(name.lstrip("*")).name] = digest
    return result


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("-v", "--version", default="ULES01213", choices=VERSIONS)
    parser.add_argument("--iso", type=Path, help="ISO path (default: the only .iso in orig/<version>/)")
    parser.add_argument("--skip-iso-check", action="store_true", help="Do not hash the ISO (slow)")
    args = parser.parse_args()

    orig = ROOT / "orig" / args.version
    iso = args.iso
    if iso is None:
        isos = sorted(orig.glob("*.iso"))
        if len(isos) != 1:
            sys.exit(f"put exactly one .iso in {orig.relative_to(ROOT)} (found {len(isos)})")
        iso = isos[0]

    info = VERSIONS[args.version]
    if info["iso_sha1"] is None:
        print(f"{args.version}: not supported yet, the ISO is not checked")
    elif not args.skip_iso_check:
        digest = sha1_of(iso)
        if digest != info["iso_sha1"]:
            sys.exit(f"{iso.name}: SHA-1 {digest}, expected {info['iso_sha1']}")
        print(f"{iso.name}: OK")

    expected = expected_sha1(args.version)
    seven_zip = find_7z()
    for inner in info["files"]:
        out = orig / Path(inner).name
        with out.open("wb") as f:
            subprocess.run([seven_zip, "e", "-so", str(iso), inner],
                           stdout=f, stderr=subprocess.DEVNULL, check=True)
        digest = sha1_of(out)
        want = expected.get(out.name)
        if want is None:
            print(f"{out.name}: extracted, SHA-1 {digest} (no reference)")
        elif digest != want:
            sys.exit(f"{out.name}: SHA-1 {digest}, expected {want}")
        else:
            print(f"{out.name}: OK")


if __name__ == "__main__":
    main()
