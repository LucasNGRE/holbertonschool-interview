#!/usr/bin/python3
"""
Module that queries the Reddit API recursively and prints a sorted count
of given keywords found in hot article titles.
"""

import requests


def count_words(subreddit, word_list, after=None, counts=None):
    """
    Queries the Reddit API recursively, parses the titles of all hot
    articles, and prints a sorted count of given keywords.

    Args:
        subreddit (str): The subreddit to query.
        word_list (list): A list of keywords to count.
        after (str): The 'after' parameter for pagination.
        counts (dict): A dictionary used to store keyword counts.

    Returns:
        None
    """
    if counts is None:
        counts = {}
        for word in word_list:
            word = word.lower()
            counts[word] = counts.get(word, 0) + 1

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {"User-Agent": "linux:count_it:v1.0"}
    params = {"limit": 100}
    if after:
        params["after"] = after

    response = requests.get(
        url,
        headers=headers,
        params=params,
        allow_redirects=False
    )

    if response.status_code != 200:
        return

    data = response.json().get("data")
    if not data:
        return

    posts = data.get("children", [])
    for post in posts:
        title = post.get("data", {}).get("title", "").lower()
        words = title.split()

        for word in counts.keys():
            counts[word] += words.count(word)

    after = data.get("after")
    if after is not None:
        return count_words(subreddit, word_list, after, counts)

    sorted_words = sorted(counts.items(), key=lambda item: (-item[1], item[0]))

    for word, count in sorted_words:
        if count > 0:
            print("{}: {}".format(word, count))