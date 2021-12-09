#!/usr/bin/python3
"""You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1 and
each box may contain keys to the other boxes."""


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened"""

    if type(boxes) is not list or len(boxes) == 0 or len(boxes[0]) == 0:
        return False

    def checkKeys(boxes, key, keys_list):
        """Check all keys in a given box"""

        keys_list.append(key)
        for new_key in boxes[key]:
            if new_key not in keys_list and new_key < len(boxes):
                checkKeys(boxes, new_key, keys_list)

    keys_list = []
    checkKeys(boxes, 0, keys_list)

    return len(boxes) == len(keys_list)
