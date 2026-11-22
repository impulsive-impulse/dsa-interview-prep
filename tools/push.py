#!/usr/bin/env python3
"""Push this repo to GitHub with the repo owner's account (impulsive-impulse).

Why: the GitHub Copilot app adds its own git login (the app's signed-in account) to every git
command, and that beats this repo's own settings. This script adds the repo's login again,
after the app's, for this one command. Outside the app, plain `git push` works too.

Usage:  python tools/push.py [git push arguments]      e.g.  python tools/push.py -u origin main

One-time setup on a new machine (after `gh auth login` with the personal account):
  git config credential.https://github.com.helper ''
  git config --add credential.https://github.com.helper '!f() { test $1 = get || exit 0; echo username=impulsive-impulse; echo password=$(gh auth token --hostname github.com --user impulsive-impulse); }; f'
"""

import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
KEY = "credential.https://github.com.helper"


def main():
    helpers = subprocess.run(
        ["git", "config", "--local", "--get-all", KEY], cwd=ROOT, capture_output=True, text=True
    ).stdout.splitlines()
    helper = helpers[-1] if helpers else ""
    cmd = ["git"]
    if helper:
        # An empty helper clears the list built so far; then ours goes last, so it is used.
        cmd += ["-c", f"{KEY}=", "-c", f"{KEY}={helper}"]
    else:
        print("note: this repo has no credential helper set, so your normal git login is used.")
    cmd += ["push", *sys.argv[1:]]
    sys.exit(subprocess.call(cmd, cwd=ROOT))


if __name__ == "__main__":
    main()
