#!/usr/bin/python3

def canUnlockAll(boxes):
    new_list = [0]

    for index in new_list:
        for num in boxes[index]:
            if num not in new_list and num < len(boxes) and isinstance(num, int) and num >= 0:
                new_list.append(num)

    return(bool(len(new_list) == len(boxes)))
