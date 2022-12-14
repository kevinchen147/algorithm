#!/usr/bin/env python3
import random

with open("input", "w") as f:
    f.write("100\n")
    for _ in range(100):
        f.write(str(random.randint(-10, 10)))
        f.write("\n")
