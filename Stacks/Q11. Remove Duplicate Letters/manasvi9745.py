def removeDuplicateLetters(s: str) -> str:
    from collections import Counter

    freq = Counter(s)   # remaining frequency
    stack = []
    visited = set()

    for ch in s:
        freq[ch] -= 1   # this occurrence is used

        if ch in visited:
            continue

        # maintain monotonic stack
        while stack and stack[-1] > ch and freq[stack[-1]] > 0:
            removed = stack.pop()
            visited.remove(removed)

        stack.append(ch)
        visited.add(ch)

    return "".join(stack)