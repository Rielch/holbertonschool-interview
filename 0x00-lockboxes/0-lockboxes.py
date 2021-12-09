#!/usr/bin/env python3
"""You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1 and
each box may contain keys to the other boxes."""


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened"""

    keys_list = []
    checkKeys(boxes, 0, keys_list)

    if len(keys_list) != len(boxes):
        return False
    return True


def checkKeys(boxes, key, keys_list):
    """Check all keys in a given box"""

    if key not in keys_list:
        keys_list.append(key)

    for new_key in boxes[key]:
        if new_key not in keys_list:
            checkKeys(boxes, new_key, keys_list)
