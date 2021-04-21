#!/usr/bin/python3
"""
- boxes is a list of lists
- A key with the same number as a box opens that box
- You can assume all keys will be positive integers
- There can be keys that do not have boxes
- The first box boxes[0] is unlocked
- Return True if all boxes can be opened, else return False
"""


def canUnlockAll(boxes):
    """Determines if all the boxes can be opened."""
    new_list = [0]

    for index in new_list:
        for num in boxes[index]:
            if num not in new_list and num < len(boxes) \
               and isinstance(num, int) and num >= 0:
                new_list.append(num)

    return(bool(len(new_list) == len(boxes)))
