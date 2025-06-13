#!/usr/bin/python3

"""
Module 0-rain
Given a list of non-negative integers representing the heights
of walls with unit width 1, as if viewing the cross-section
of a relief map, calculate how many square units of water
will be retained after it rains..
"""


def rain(walls):
    """"
    Prototype: def rain(walls)
    walls is a list of non-negative integers.
    Return: Integer indicating total amount of rainwater retained.
    Assume that the ends of the list (before index 0 and
    after index walls[-1]) are not walls, meaning they will not retain water.
    If the list is empty return 0.
    """
    if not walls:
        return 0

    n = len(walls)
    left_max = [0] * n
    right_max = [0] * n

    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    right_max[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    total_water = 0
    for i in range(n):
        water = min(left_max[i], right_max[i]) - walls[i]
        if water > 0:
            total_water += water

    return total_water
