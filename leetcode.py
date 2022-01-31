from collections import *
from typing import *
from heapq import *
from math import *
from functools import *
from random import *
from functools import *
import bisect
from sortedcontainers import *


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
